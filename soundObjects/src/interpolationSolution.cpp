#include "stdafx.h"
#include<iostream>
#include<cassert>
#include"globalConstants.h"
#include"interpolationSolution.h"
#include<vector>
#include"vector3.h"
#include "velocityOrbit.h"

struct PointsStEndSurv{
	Vector3 m_sA, m_sB, m_p;
};

void estPointsStEndSurv(PointsStEndSurv& Points, Orbit& satA, Orbit& satB, SurveyObjects& point) {
	Points.m_p = Vector3{ point.getX(), point.getY(), point.getZ() };
	Points.m_sA = Vector3{ satA.getX(), satA.getY(), satA.getZ() };
	Points.m_sB = Vector3{ satB.getX(), satB.getY(), satB.getZ() };
	Points.m_p.normalize();
	Points.m_sA.normalize();
	Points.m_sB.normalize();
}

void estPointsStEndSurv(PointsStEndSurv& Points, SurveyObjects& point) {
	Points.m_p = Vector3{ point.getX(), point.getY(), point.getZ() };
}

double timeApproximate(double tA, double tB,
	                   Orbit satA, Orbit satB,
					   SurveyObjects point) {
	PointsStEndSurv pointsOfSat;
	estPointsStEndSurv(pointsOfSat, satA, satB, point);

	double tAVG{ (tA + tB) / 2 };
	Orbit satAVG{ tAVG, phys::rOrb };
	VelocityOrbit velSatAVG{ tAVG, phys::rOrb };
	Vector3 sAVG{ satAVG.getX(), satAVG.getY(), satAVG.getZ() };
	Vector3 vAVG{ velSatAVG.getVx(), velSatAVG.getVy(), velSatAVG.getVz() };
	Vector3 normalAVG{ sAVG.cross(vAVG) };
	normalAVG.normalize(); // because sAVG and vAVG arent't normalized

	Vector3 pc{ pointsOfSat.m_p }, sAc{ pointsOfSat.m_sA };
	pc.projectOnPlane(normalAVG);
	sAc.projectOnPlane(normalAVG);
	pc.normalize();
	sAc.normalize();

	Vector3 sOrt{ sAc.cross(normalAVG) };

	double x{ pc*sAc };
	double y{ pc*sOrt };

	double tApprox{ tA + (1 / phys::wS)*atan2(y, x) };
	return tApprox;
 }

double timeSurvLinearInterp(double tA, double tB, 
							Orbit satA, Orbit satB, 
							SurveyObjects& point) {
	PointsStEndSurv pointsOfSat;
	estPointsStEndSurv(pointsOfSat, satA, satB, point);

	Vector3 normal{ pointsOfSat.m_sA.cross(pointsOfSat.m_sB) };
	normal.normalize();
	pointsOfSat.m_p.projectOnPlane(normal);
	pointsOfSat.m_p.normalize();

	double tSurv{ tA + sqrt(2 * (1 - pointsOfSat.m_sA*pointsOfSat.m_p)) 
												/ (phys::wS - phys::wE) };
	return tSurv;
}

double functionPV(double t, SurveyObjects& point) {
	Vector3 p{ point.getX(), point.getY(), point.getZ() };
	VelocityOrbit velocity{ t, phys::rOrb };
	Vector3 v{ velocity.getVx(), velocity.getVy(), velocity.getVz() };
	return p*v;
}

double round(double t) {
	return ((t - floor(t)) >= 0.5) ? ceil(t) : floor(t);
}

double quadraticInterpTime(double tA, double tB,
						   Orbit satA, Orbit satB, SurveyObjects point){

	// --- introduce approximate time ---

	//double tApproximate{ timeApproximate(tA, tB, satA, satB, point) };
	double tApproximate{ 260.0 };

	// --- introduce approximate time ---
	
	// --- time dots 4 interp ---
	double d_t{ tB - tA }; // delta t
	std::vector<double> timeSamples{ tA - d_t, tA, tB, tB + d_t };
	int index_t0{ static_cast<int>(round((tApproximate - timeSamples[0]) / d_t)) };
	double t0{ timeSamples.at(index_t0) }; // t"0"
	double t_1{ t0 - d_t }; // t"-1" = t"0" - delta t
	double t1{ t0 + d_t }; // t"1" = t"0" + delta t
	// --- time dots 4 interp ---

	// --- quadr interp coeff ---
	double f_1{ functionPV(t_1, point) };
	double f0{ functionPV(t0, point) };
	double f1{ functionPV(t1, point) };
	double f1_0{ f1 - f0 };

	double a{ ((f_1 - f0) + f1_0) / 2 / d_t / d_t };

	double b{ f1_0 / d_t - a*(t1 + t0) };

	double c{ f1 - t1*(a*t1 + b) };
	// --- quadr interp coeff ---

	// --- root (i.e. resulting time) ---
	double D{ b*b - 4 * a*c };

	if ((b > 0) && (a > 0 || a < 0))
		return (-b + pow(D, 0.5)) / 2 / a;
	else if ((b < 0) && (a > 0 || a < 0))
		return (-b - pow(D, 0.5)) / 2 / a;
	else if (a == 0)
		return -c / b;

	// --- root (i.e. resulting time) ---

}

double timeSurvQuadraticInterp(double tA, double tB,
							   Orbit satA, Orbit satB,
							   SurveyObjects point) {

	// --- introduce approximate time ---
	
	//double tApprox{ timeApproximate(tA, tB, satA, satB, point) };
	double tApprox{ 260.0 };
	
	// --- introduce approximate time ---

	// --- time dots 4 interp ---
	double tDelta{ tB - tA };
	double tAdd{};
	if ((tApprox - tA) > (tB - tApprox))
		tAdd = tB + tDelta;
	else if ((tApprox - tA) < (tB - tApprox))
		tAdd = tA - tDelta;
	// --- time dots 4 interp ---

	// --- quadr interp coeff ---
	double a{ ((functionPV(tB, point) - functionPV(tA, point))*(tAdd - tA) +
			   (functionPV(tA, point) - functionPV(tAdd, point))*(tB - tA)) /
			   (tB - tA) / (tB - tAdd) / (tAdd - tA) };

	double b{ (functionPV(tAdd, point) - functionPV(tA, point)
			   - a*(pow(tAdd,2.0) - pow(tA, 2.0))) / (tAdd - tA) };

	double c{ functionPV(tA, point) - a*pow(tA, 2.0) - b*tA };

	double D{ pow(b, 2.0) - 4 * a*c };
	assert(D >= 0);
	assert(a != 0);

	double tVertex{ -b / 2 / a };
	// --- quadr interp coeff ---

	// --- root (i.e. resulting time) ---
	double tMid{ (tA + tB) / 2 };
	if (tVertex < tMid) {
		if (a > 0)
			return (-b + pow(D, 0.5)) / 2 / a;
		else
			return (-b - pow(D, 0.5)) / 2 / a;
	}
	else if (tVertex > tMid) {
		if (a > 0)
			return (-b - pow(D, 0.5)) / 2 / a;
		else
			return (-b + pow(D, 0.5)) / 2 / a;
	}
	else
		return -1.0; // an awkward option
	// --- root (i.e. resulting time) ---
}

//--- trashes from quadratic interp ---

//PointsStEndSurv pointsOfSat;
//estPointsStEndSurv(pointsOfSat, point);
//VelocityOrbit velSat{ timeApproximate(tA,tB,satA, satB, point) };
//double functionPVResult{ functionPV(tApprox, point) };
//std::cout << functionPV(tA, point) << ":" << functionPV(tB, point) << std::endl;

//--- trashes form quadratic interp ---

/*Vector3 sA{ satA.getX(), satA.getY(), satA.getZ() };
Vector3	sB{ satB.getX(), satB.getY(), satB.getZ() };
Vector3 p{ point.getX(), point.getY(), point.getZ() };
sA.normalize();
sB.normalize();
p.normalize();*/ // overlapped code - BAD