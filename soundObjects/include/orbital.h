#ifndef SURVEYSOLUTION_20200911_ORBITAL_H
#define SURVEYSOLUTION_20200911_ORBITAL_H

#include<memory>
#include"targets.h"
#include"timePoints.h"
#include<vector>
#include<vector3.h>

class Orbital
{
private:
	Vector3 m_radiusVector;
	Vector3 m_velocityVector;
	
public:
	Orbital() = default;
	Orbital(double radOrb, double t);
	
	void setRadiusVector(double radOrb, double t);
	void setVelocityVector(double radOrb, double t);

	Vector3 getRadiusVector() { return m_radiusVector; }
	Vector3 getVelocityVector() { return m_velocityVector; }

	void setOrbitCoord(double &x, double &y, double &z,
		double radOrb, double t);
	void setOrbitVelocities(double &x, double &y, double &z,
		double radOrb, double t);

	void setOrbitAccelerations(double &x, double &y, double &z,
		double radOrb, double t);

};

#endif