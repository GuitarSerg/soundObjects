#include "stdafx.h"
#include "..\include\targets.h"


Targets::Targets(double radProbingSphere,
				 AnglesContainer& anglesVect)
{
	setRadVect(radProbingSphere, anglesVect);
}


Targets::~Targets()
{

}

void Targets::setObjectCoord(double &x, double &y, double &z,
							 double radProbingSphere, 
							 AngularCoordinates angles)
{
	x = radProbingSphere * cos(angles.m_phi) * cos(angles.m_lam);
	y = radProbingSphere * cos(angles.m_phi) * sin(angles.m_lam);
	z = radProbingSphere * sin(angles.m_phi);
}

void Targets::setRadVect(double radProbingSphere, AnglesContainer& anglesVect)
{
	for (auto angles : anglesVect) {
		double x, y, z; //probing target's coordinates
		setObjectCoord(x, y, z, radProbingSphere, angles);
		m_targetsVect.push_back(new Vector3{ x,y,z });
	}
}