#pragma once
#include "velocityOrbit.h"
class VelocityOrbitEarthProjection :
	public VelocityOrbit
{
public:
	VelocityOrbitEarthProjection(double t, double radOrb);
	~VelocityOrbitEarthProjection();
};

