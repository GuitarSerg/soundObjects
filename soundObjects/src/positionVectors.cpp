#include "stdafx.h"
#include "..\include\positionVectors.h"
#include"globalConstants.h"


PositionVectors::PositionVectors(Orbit& satA,
								 Orbit& satB,
								 SurveyObjects& point)
{
	sA = Vector3{ satA.getX(), satA.getY(), satA.getZ() };
	sB = Vector3{ satB.getX(), satB.getY(), satB.getZ() };
	p = Vector3{ point.getX(), point.getY(), point.getZ() };
}

void PositionVectors::setVector_s(double t) {
	Orbit sat{ t, phys::rOrb };
	s = Vector3{ sat.getX(), sat.getY(), sat.getZ() };
}

void PositionVectors::setVector_v(double t) {
	VelocityOrbit vSat{ t, phys::rOrb };
	v = Vector3{ vSat.getVx(), vSat.getVy(), vSat.getVz() };
}

PositionVectors::~PositionVectors()
{
}
