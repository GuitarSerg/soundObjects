#include "stdafx.h"
#include "..\include\Orbit.h"
#include "globalConstants.h"
#include<iostream>

Orbit::Orbit(double t, double radOrb)
{
	m_x = radOrb*(cos(phys::wS*t)*cos(phys::wE*t)
		+ cos(phys::incl)*sin(phys::wS*t)*sin(phys::wE*t));
	m_y = radOrb*(-cos(phys::wS*t)*sin(phys::wE*t)
		+ cos(phys::incl)*sin(phys::wS*t)*cos(phys::wE*t));
	m_z = radOrb*sin(phys::incl)*sin(phys::wS*t);

	m_vx = radOrb*(sin(phys::wS*t)*cos(phys::wE*t)*
		(-phys::wS + phys::wE*cos(phys::incl)) +
		sin(phys::wE*t)*cos(phys::wS*t)*
		(phys::wS*cos(phys::incl) - phys::wE));
	m_vy = radOrb*(sin(phys::wS*t)*sin(phys::wE*t)*
		(phys::wS - phys::wE*cos(phys::incl)) +
		cos(phys::wS*t)*cos(phys::wE*t)*
		(phys::wS*cos(phys::incl) - phys::wE));
	m_vz = radOrb*phys::wS*sin(phys::incl)*cos(phys::wS*t);

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

Orbit::~Orbit()
{
}
