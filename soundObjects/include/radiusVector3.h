#ifndef SURVEYSOLUTION_20200910_RADIUSVECTOR3_H
#define SURVEYSOLUTION_20200910_RADIUSVECTOR3_H

#include "vector3.h"

class RadiusVector3: public Vector3
{
public:
	RadiusVector3(double lam, double phi);
	~RadiusVector3();
};

#endif

