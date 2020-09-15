#include "stdafx.h"
#include "..\include\calculation.h"

#include"display.h"
#include"globalConstants.h"
#include"interpolation.h"
#include"orbital.h"
#include"solutionLoop.h"
#include"targets.h"
#include"timePoints.h"

Calculation::Calculation()
{
	TimePoints timeStorage{ std::vector<double> {input::tA, input::tB} };
	std::vector<AngularCoordinates> anglesStorage{ {input::lam, input::phi} };
	Orbital earthOrbit{ input::rOrb, timeStorage };
	Targets targetStorage{ phys::rEarth, anglesStorage };

	SolutionLoop loop1{ earthOrbit, timeStorage, targetStorage };
	/*Interpolation interpResolution{ earthOrbit, targetStorage, timeStorage, anglesStorage };
	Display output{ interpResolution };*/
	//double tLin{ interpResolution.findTimeLinear(earthOrbit, targetStorage, timeStorage, 0, 1, 0) };
}


Calculation::~Calculation()
{
}
