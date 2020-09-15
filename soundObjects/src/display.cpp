#include "stdafx.h"
#include "..\include\display.h"

#include"globalConstants.h"
#include<iomanip>
#include<iostream>

Display::Display(Interpolation& approximateSolution)
{
	printSurveyTime(approximateSolution);

}

void Display::printSurveyTime(Interpolation& approximateSolution) {
	int field{ 15 };
	for (auto i : approximateSolution.getLinear())
		std::cout << "Linear time on a segment " << i->get_tA() << ' ' <<
		i->get_tB() << " is " << std::scientific << std::setprecision(12) << 
		std::setw(field) << i->get_tSol() <<
		" corresponding to survObject(lam, phi) " <<
		//i->getAngularCoordinates().m_lam << ' ' << 
		//i->getAngularCoordinates().m_phi*180/PI <<
		std::endl;
}

Display::~Display()
{
}
