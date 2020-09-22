#include "stdafx.h"

#include"globalConstants.h"
#include "..\include\orbital.h"

//---new snippet---
Orbital::Orbital(double radOrb, double t)
{
	setRadiusVector(radOrb, t);
	setVelocityVector(radOrb, t);
}

void Orbital::setRadiusVector(double radOrb, double t)
{
	double x{}, y{}, z{};
	setOrbitCoord(x, y, z, radOrb, t);
	m_radiusVector = Vector3(x, y, z);
}

void Orbital::setVelocityVector(double radOrb, double t)
{
	double vx{}, vy{}, vz{};
	setOrbitVelocities(vx, vy, vz, radOrb, t);
	m_velocityVector = Vector3(vx, vy, vz);
}

void Orbital::setOrbitCoord(double &x, double &y, double &z, double radOrb, double t)
{
	x = radOrb*(cos(phys::wS*t)*cos(phys::wE*t)
		+ cos(phys::incl)*sin(phys::wS*t)*sin(phys::wE*t));
	y = radOrb*(-cos(phys::wS*t)*sin(phys::wE*t)
		+ cos(phys::incl)*sin(phys::wS*t)*cos(phys::wE*t));
	z = radOrb*sin(phys::incl)*sin(phys::wS*t);
}

void Orbital::setOrbitVelocities(double &vx, double &vy, double &vz,
	double radOrb, double t)
{
	vx = radOrb*(sin(phys::wS*t)*cos(phys::wE*t)*
		(-phys::wS + phys::wE*cos(phys::incl)) +
		sin(phys::wE*t)*cos(phys::wS*t)*
		(phys::wS*cos(phys::incl) - phys::wE));
	vy = radOrb*(sin(phys::wS*t)*sin(phys::wE*t)*
		(phys::wS - phys::wE*cos(phys::incl)) +
		cos(phys::wS*t)*cos(phys::wE*t)*
		(phys::wS*cos(phys::incl) - phys::wE));
	vz = radOrb*phys::wS*sin(phys::incl)*cos(phys::wS*t);
}

void Orbital::setOrbitAccelerations(double &ax, double &ay, double &az,
	double radOrb, double t)
{
	ax = radOrb*(cos(phys::wS*t)*cos(phys::wE*t)*
		(2 * phys::wS*phys::wE*cos(phys::incl) - pow(phys::wS, 2) - pow(phys::wE, 2)) +
		sin(phys::wS*t)*sin(phys::wE*t)*
		(2 * phys::wS*phys::wE - cos(phys::incl)*(pow(phys::wS, 2) + pow(phys::wE, 2))));
	ay = radOrb*(cos(phys::wS*t)*sin(phys::wE*t)*
		(-2 * phys::wS*phys::wE*cos(phys::incl) +
			pow(phys::wS, 2) + pow(phys::wE, 2)) +
		sin(phys::wS*t)*cos(phys::wE*t)*
		(2 * phys::wS*phys::wE - cos(phys::incl)*
		(pow(phys::wS, 2) + pow(phys::wE, 2))));
	az = -radOrb*sin(phys::wS*t)*pow(phys::wS, 2)*sin(phys::incl);
}
