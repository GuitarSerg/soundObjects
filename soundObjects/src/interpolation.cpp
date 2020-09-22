#include "stdafx.h"

#include"globalConstants.h"
#include "..\include\interpolation.h"
#include<cassert>
#include<cmath>
#include<limits>


Interpolation::Interpolation(SurveyData &dataStorage)
{
	m_dt = dataStorage.getTimeStorage().getTimeStep();
}

double Interpolation::evaluateLinearTime(SurveyData &dataStorage, double tApprox,
	std::shared_ptr<Vector3> target)
{
	std::tie(m_t0, m_t1) = dataStorage.getTimeStorage().getTwoTimesCloseTo(tApprox);
	// --- define vectors
	setVectors();
	Vector3 p{ *target };

	// --- define functions' values
	double f0{ p*m_v0 };
	double f1{ p*m_v1 };

	// --- define coefficients 
	double b{}, c{};
	std::tie(b, c) = setCoeff_b_c(f0, f1);
	// --- evaluate root
	assert(std::abs(b) > std::numeric_limits<double>::epsilon() ||
		std::abs(c) > std::numeric_limits<double>::epsilon()); //( b != 0 || c!= 0 )
	m_tSurv = -c / b;
	return m_tSurv;
}

double Interpolation::evaluateLinearRoll(SurveyData &dataStorage,
	std::shared_ptr<Vector3> target)
{
	// --- Vectors
	Vector3 n0{ m_s0.cross(m_v0) };
	Vector3 n1{ m_s1.cross(m_v1) };
	Vector3 p{ *target };
	// --- normalization
	normalizeVectors(&n0, &n1, &p);
	// --- define functions' values
	double g0{ n0*p };
	double g1{ n1*p };
	// --- define coefficients 
	double b{}, c{};
	std::tie(b, c) = setCoeff_b_c(g0, g1);
	// --- define sin and cos
	double sinAlfSurv{ b*m_tSurv + c };
	double cosAlfSurv{ sqrt(1 - sinAlfSurv*sinAlfSurv) };
	// --- define rollSurv
	double H{ phys::rOrb - phys::rEarth };
	return atan(sinAlfSurv / (1 - cosAlfSurv + H / phys::rEarth)) * 180 / PI;
}

double Interpolation::evaluateQuadraticTime(SurveyData &dataStorage, double tApprox,
	std::shared_ptr<Vector3> target)
{
	std::tie(m_t_1, m_t0, m_t1) = dataStorage.getTimeStorage().
		getThreeTimesCloseTo(tApprox);
	// --- define vectors
	setVectors();
	Vector3 p{ *target };

	// --- define functions' values
	double f_1{ p*m_v_1 };
	double f0{ p*m_v0 };
	double f1{ p*m_v1 };

	// --- define coefficients
	double a{}, b{}, c{};
	std::tie(a, b, c) = setCoeff_a_b_c(f_1, f0, f1);
	// --- evaluate root
	assert(std::abs(b) > std::numeric_limits<double>::epsilon()); // b != 0
	if (std::abs(a) < std::numeric_limits<double>::epsilon()) // a = 0
		m_tSurv = -c / b;
	else { // a != 0
		double D{ b*b - 4 * a*c };
		if (b > std::numeric_limits<double>::epsilon()) // b > 0
			m_tSurv = (-b + sqrt(D)) / 2 / a;
		else//if (-b > std::numeric_limits<double>::epsilon()) // b < 0
			m_tSurv = (-b - sqrt(D)) / 2 / a;
	}
	return m_tSurv;

}

double Interpolation::evaluateQuadraticRoll(SurveyData &dataStorage,
	std::shared_ptr<Vector3> target)
{
	Vector3 n_1{ m_s_1.cross(m_v_1) };
	Vector3 n0{ m_s0.cross(m_v0) };
	Vector3 n1{ m_s1.cross(m_v1) };
	Vector3 p{ *target };
	// --- normalization
	normalizeVectors(&n_1, &n0, &n1, &p);
	// --- define functions' values
	double g_1{ n_1*p };
	double g0{ n0*p };
	double g1{ n1*p };
	// --- define coefficients 
	double a{}, b{}, c{};
	std::tie(a, b, c) = setCoeff_a_b_c(g_1, g0, g1);
	// --- define sin and cos
	double sinAlfSurv{ a*m_tSurv*m_tSurv + b*m_tSurv + c };
	double cosAlfSurv{ sqrt(1 - sinAlfSurv*sinAlfSurv) };
	// --- define rollSurv
	double H{ phys::rOrb - phys::rEarth };
	return atan(sinAlfSurv / (1 - cosAlfSurv + H / phys::rEarth)) * 180 / PI;
}



void Interpolation::normalizeVectors(Vector3* vect1, Vector3* vect2, Vector3* vect3,
	Vector3* vect4)
{
	vect1->normalize();
	vect2->normalize();
	vect3->normalize();
	vect4->normalize();
}

void Interpolation::normalizeVectors(Vector3* vect1, Vector3* vect2, Vector3* vect3)
{
	vect1->normalize();
	vect2->normalize();
	vect3->normalize();
}

void Interpolation::normalizeVectors(Vector3* vect1, Vector3* vect2)
{
	vect1->normalize();
	vect2->normalize();
}

void Interpolation::normalizeVectors(Vector3* vect1)
{
	vect1->normalize();
}

void Interpolation::setVectors()
{
	Orbital orb_1{ phys::rEarth, m_t_1 };
	Orbital orb0{ phys::rEarth, m_t0 };
	Orbital orb1{ phys::rEarth, m_t1 };
	m_s0 = orb0.getRadiusVector();
	m_s1 = orb1.getRadiusVector();
	m_v0 = orb0.getVelocityVector();
	m_v1 = orb1.getVelocityVector();
	m_s_1 = orb_1.getRadiusVector();
	m_v_1 = orb_1.getVelocityVector();
}

std::tuple<double, double> Interpolation::setCoeff_b_c(double func0, double func1)
{
	double b{ (func1 - func0) / m_dt };
	double c{ func1 - m_t1*b };
	return{ b,c };
}

std::tuple<double, double, double> Interpolation::setCoeff_a_b_c(double func_1, double func0, double func1)
{
	double func1_0{ func1 - func0 }; //
	double a{ ((func_1 - func0) + func1_0) / 2 / m_dt / m_dt };
	double b{ func1_0 / m_dt - a*(m_t1 + m_t0) };
	double c{ func1 - m_t1*(a*m_t1 + b) };
	return{ a,b,c };
}
