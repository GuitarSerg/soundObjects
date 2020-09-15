#include "stdafx.h"
#include "..\include\accelerationOrbit.h"
#include"globalConstants.h"
#include<iostream>

AccelerationOrbit::AccelerationOrbit(double t, double radOrb)
{
	m_ax = radOrb*(cos(phys::wS*t)*cos(phys::wE*t)*
		   (2 * phys::wS*phys::wE*cos(phys::incl) - pow(phys::wS, 2) - pow(phys::wE, 2)) +
		   sin(phys::wS*t)*sin(phys::wE*t)*
		   (2 * phys::wS*phys::wE - cos(phys::incl)*(pow(phys::wS, 2) + pow(phys::wE, 2))));
	m_ay = radOrb*(cos(phys::wS*t)*sin(phys::wE*t)*
		   (-2 * phys::wS*phys::wE*cos(phys::incl) + 
		   pow(phys::wS, 2) + pow(phys::wE, 2)) +
		   sin(phys::wS*t)*cos(phys::wE*t)*
		   (2 * phys::wS*phys::wE - cos(phys::incl)*
		   (pow(phys::wS, 2) + pow(phys::wE, 2))));
	m_az = -radOrb*sin(phys::wS*t)*pow(phys::wS, 2)*sin(phys::incl);
}


AccelerationOrbit::~AccelerationOrbit()
{
}
