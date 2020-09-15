#include "stdafx.h"

#include"globalConstants.h"
#include "..\include\interpolation.h"
#include<cassert>

Interpolation::Interpolation(Orbital &earthOrbit,
	Targets &targetStorage,
	TimePoints &timeStorage,
	std::vector<AngularCoordinates> &angVect)
{
	/*int tMax{defineTMax(timeStorage, targetStorage)};
	int i{ 0 };
	for (; i < tMax;) {
		double time{ findTimeLinear(earthOrbit, targetStorage, timeStorage, 
									i, i + 1, i / 2) };
		m_timeLinear.push_back(time);
		m_Linear.push_back(new Solution(timeStorage.getTimePointsVect().at(i),
			timeStorage.getTimePointsVect().at(i + 1), time, angVect.at(i/2)));
		i += 2;
	}*/
}

Interpolation::~Interpolation()
{
}

int Interpolation::defineTMax(TimePoints& timeStorage, Targets& targetStorage) {
	int targetSize{ static_cast<int>(targetStorage.getTargetsVector().size()) };
	int timeSize{ static_cast<int>(timeStorage.getTimePointsVect().size()) };
	assert(targetSize != (1 / 2)*timeSize);
	if (timeSize % 2 == 0)
		return timeSize;
	else
		return timeSize - 1;
}

void Interpolation::normalizeVectors(Vector3* vect1, Vector3* vect2, Vector3* vect3) {
	vect1->normalize();
	vect2->normalize();
	vect3->normalize();
}

void Interpolation::normalizeVectors(Vector3* vect1, Vector3* vect2) {
	vect1->normalize();
	vect2->normalize();
}

void Interpolation::normalizeVectors(Vector3* vect1) {
	vect1->normalize();
}

double Interpolation::findTimeLinear(Orbital& earthOrbit, 
	Targets& targetStorage, 
	TimePoints& timeStorage,
	int iA, int iB, int iP) {

	Vector3* sA{ earthOrbit.getRadVect().at(iA) };
	Vector3* sB{ earthOrbit.getRadVect().at(iB) };
	Vector3* p{ targetStorage.getTargetsVector().at(iP) };
	normalizeVectors(sA, sB, p);

	Vector3 normal{ sA->cross(*sB) };
	normal.normalize();
	p->projectOnPlane(normal);
	p->normalize();

	double tA{ timeStorage.getTimePointsVect().at(iA) };
	double tB{ timeStorage.getTimePointsVect().at(iB) };

	double sqr{ sqrt(2 * (1 - sA->operator*(*p))) };
	double tSurv{ tA + sqr / (phys::wS - phys::wE) };
	return tSurv;
}

double Interpolation::findLinearTime(Orbital &earthOrbit, Targets &targetStorage,
									 TimePoints &timeStorage, double tA, 
									 double tB, int targetIndex)
{
	Vector3* sA{ earthOrbit.getRadVectAt(tA, timeStorage) };
	Vector3* sB{ earthOrbit.getRadVectAt(tB, timeStorage) };
	Vector3* p{ targetStorage.getTargetsVector().at(targetIndex) };

	normalizeVectors(sA, sB, p);

	Vector3 normal{ sA->cross(*sB) };
	normal.normalize();
	p->projectOnPlane(normal);
	p->normalize();

	return tA + sqrt(2 * (1 - sA->operator*(*p)))/ (phys::wS - phys::wE);
}

double Interpolation::findTimeQuadratic(Orbital &earthOrbit, 
	Targets &targetStorage, TimePoints &timeStorage, 
	int iA, int iB, int iP)
{
	// --- introduce approximate time ---
	//downloaded from file or smth like
	double tApproximate{ 260.0 };

	// --- introduce approximate time ---
	
	return 0.0;
}

//timeSurvLinearInterp(double tA, double tB,
//										   Orbit satA, Orbit satB,
//										   SurveyObjects& point) {
//	PointsStEndSurv pointsOfSat;
//	estPointsStEndSurv(pointsOfSat, satA, satB, point);
//
//	Vector3 normal{ pointsOfSat.m_sA.cross(pointsOfSat.m_sB) };
//	normal.normalize();
//	pointsOfSat.m_p.projectOnPlane(normal);
//	pointsOfSat.m_p.normalize();
//
//	double tSurv{ tA + sqrt(2 * (1 - pointsOfSat.m_sA*pointsOfSat.m_p))
//		/ (phys::wS - phys::wE) };
//	return tSurv;
//}