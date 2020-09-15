#pragma once
#include "accelerationOrbit.h"
class AccelerationOrbitEarthProjection : public AccelerationOrbit
{
public:
	AccelerationOrbitEarthProjection(double t, double radOrb);
	~AccelerationOrbitEarthProjection();
};

