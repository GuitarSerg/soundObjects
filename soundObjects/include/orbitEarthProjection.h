#ifndef SURVEYSOLUTION_20200824_ORBITEARTHPROJECTION_H
#define SURVEYSOLUTION_20200824_ORBITEARTHPROJECTION_H

#include "Orbit.h"
class OrbitEarthProjection : public Orbit
{
public:
	OrbitEarthProjection(double t, double radOrb);
	~OrbitEarthProjection();
};

#endif