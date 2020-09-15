#include "stdafx.h"

#include"globalConstants.h"
#include<iostream>
#include "..\include\radiusVector3.h"

RadiusVector3::RadiusVector3(double lam, double phi)
{
	x = phys::rEarth * cos(phi) * cos(lam);
	y = phys::rEarth * cos(phi) * sin(lam);
	z = phys::rEarth * sin(phi);
}



RadiusVector3::~RadiusVector3()
{
}
