#include "stdafx.h"
#include "..\include\velocityOrbit.h"
#include"globalConstants.h"
#include<iostream>

VelocityOrbit::VelocityOrbit(double t, double radOrb)
{
	m_vx = radOrb*(sin(phys::wS*t)*cos(phys::wE*t)*
		   (-phys::wS + phys::wE*cos(phys::incl)) +
		   sin(phys::wE*t)*cos(phys::wS*t)*
		   (phys::wS*cos(phys::incl) - phys::wE));
	m_vy = radOrb*(sin(phys::wS*t)*sin(phys::wE*t)*
		   (phys::wS - phys::wE*cos(phys::incl)) +
		   cos(phys::wS*t)*cos(phys::wE*t)*
		   (phys::wS*cos(phys::incl) - phys::wE));
	m_vz = radOrb*phys::wS*sin(phys::incl)*cos(phys::wS*t);
}

VelocityOrbit::~VelocityOrbit()
{
}
