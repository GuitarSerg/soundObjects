#include "stdafx.h"
#include "..\include\SurveyObjects.h"
#include "globalConstants.h"
#include<iostream>


SurveyObjects::SurveyObjects(double lam, double phi) {
	m_x = phys::rEarth * cos(phi) * cos(lam);
	m_y = phys::rEarth * cos(phi) * sin(lam);
	m_z = phys::rEarth * sin(phi);
}


SurveyObjects::~SurveyObjects()
{
}
