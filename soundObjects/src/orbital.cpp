#include "stdafx.h"

#include"globalConstants.h"
#include "..\include\orbital.h"

Orbital::Orbital(double radOrb, TimePoints& timeStorage) // take radOrb from phys::namespace
{
	setRadVect(radOrb, timeStorage);
	setVeloVect(radOrb, timeStorage);
	setAccelVect(radOrb, timeStorage);
}

Orbital::~Orbital()
{

}

void Orbital::setOrbitCoord(double &x, double &y, double &z, double radOrb, double t)
{
	x = radOrb*(cos(phys::wS*t)*cos(phys::wE*t)
		+ cos(phys::incl)*sin(phys::wS*t)*sin(phys::wE*t));
	y = radOrb*(-cos(phys::wS*t)*sin(phys::wE*t)
		+ cos(phys::incl)*sin(phys::wS*t)*cos(phys::wE*t));
	z = radOrb*sin(phys::incl)*sin(phys::wS*t);
}

void Orbital::setRadVect(double radOrb, TimePoints& timeStorage)
{
	for (auto t : timeStorage.getTimePointsVect()) {
		double x, y, z;
		setOrbitCoord(x, y, z, radOrb, t);
		m_radVect.push_back(new Vector3{ x, y, z });
	}
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

void Orbital::setVeloVect(double radOrb, TimePoints& timeStorage)
{
	for (auto t : timeStorage.getTimePointsVect()) {
		double vx, vy, vz;
		setOrbitVelocities(vx, vy, vz, radOrb, t);
		m_veloVect.push_back(new Vector3{ vx, vy, vz });
	}
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

void Orbital::setAccelVect(double radOrb, TimePoints & timeStorage)
{
	for (auto t : timeStorage.getTimePointsVect()) {
		double vx, vy, vz;
		setOrbitAccelerations(vx, vy, vz, radOrb, t);
		m_accelVect.push_back(new Vector3{ vx, vy, vz });
	}
}

Vector3* Orbital::getRadVectAt(double t, TimePoints & timeStorage)
{
	double t0{ timeStorage.getTimePointsVect().at(0) };
	double dt{ timeStorage.getTimeStep() };
	int index_t{ static_cast<int>(round((t - t0) / dt)) };
	return m_radVect.at(index_t);
}
