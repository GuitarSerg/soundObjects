#include "stdafx.h"
#include "..\include\targets.h"


Targets::Targets(std::vector<std::shared_ptr<Vector3>>& vectOfObjVectors)
{
	for (auto vectIt : vectOfObjVectors) {
		m_targetsVect.push_back(vectIt);
		m_anglesVect.push_back({ 0,0 });
	}
}

Targets::Targets(double radProbingSphere,
	VectorOfAngles &anglesVect)
{
	m_anglesVect = anglesVect;
	setTargetsVect(radProbingSphere, anglesVect); // angular coordinates -> vector of {x,y,z} of every obj
}


Targets::~Targets()
{

}

void Targets::setTargetsVect(double radProbingSphere, VectorOfAngles &anglesVect)
{
	for (auto anglesPair : anglesVect) {
		double x{}, y{}, z{}; //probing target's coordinates
		setObjectCoord(x, y, z, radProbingSphere, anglesPair);
		m_targetsVect.push_back(std::make_shared<Vector3>(x, y, z));
		// it will delete all the objects before the vector goes out of scope
	}
}

void Targets::setObjectCoord(double &x, double &y, double &z,
	double radProbingSphere,
	const AngularCoordinates &anglesPair)
{
	x = radProbingSphere * cos(anglesPair.m_phi) * cos(anglesPair.m_lam);
	y = radProbingSphere * cos(anglesPair.m_phi) * sin(anglesPair.m_lam);
	z = radProbingSphere * sin(anglesPair.m_phi);
}