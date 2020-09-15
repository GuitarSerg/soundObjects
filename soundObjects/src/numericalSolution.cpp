#include "stdafx.h"
#include<iostream>
#include<iomanip>

#include"accelerationOrbitEarthProjection.h"
#include"globalConstants.h"
#include"numericalSolution.h"
#include"orbitEarthProjection.h"
#include"vector3.h"
#include"velocityOrbitEarthProjection.h"

/********functions and derivatives********/
double fPlane(double t) {
	OrbitEarthProjection r{ t, phys::rEarth};
	VelocityOrbitEarthProjection v{ t, phys::rEarth };
	return (v.getVx()*(phys::rEarth*cos(phys::phi)*cos(phys::lam) - r.getX()) +
		   v.getVy()*(phys::rEarth*cos(phys::phi)*sin(phys::lam) - r.getY()) +
		   v.getVz()*(phys::rEarth*sin(phys::phi) - r.getZ()))/ phys::rEarth;
}

double fPlaneDer(double t) {
	OrbitEarthProjection r{ t, phys::rEarth };
	VelocityOrbitEarthProjection v{ t, phys::rEarth };
	AccelerationOrbitEarthProjection a{ t, phys::rEarth };
	return (a.getAx()*(phys::rEarth*cos(phys::phi)*cos(phys::lam) - r.getX()) - pow(v.getVx(), 2) +
		   a.getAy()*(phys::rEarth*cos(phys::phi)*sin(phys::lam) - r.getY()) - pow(v.getVy(), 2) +
		   a.getAz()*(phys::rEarth*sin(phys::phi) - r.getZ()) - pow(v.getVz(), 2))/ phys::rEarth;
}

double fSin(double t) {
	return sin(t) - 0.5;
}

double fSinDer(double t) {
	return cos(t);
}

double fSin2tPer2(double t) {
	return sin(t)*cos(t) - 0.25;
}

double fSin2tPer2Der(double t) {
	return cos(t)*cos(t) - sin(t)*sin(t);
}
/********functions and derivatives********/

/********verifying methods********/

double diffSchDer(double point, double delta,
	std::function<double(double)> f) {
	return (f(point + delta) - f(point)) / delta;
}

double der(double point, std::function<double(double)> fDer) {
	return fDer(point);
}

bool verifyDerivative(double point, double delta,
	double acc,
	std::function<double(double)> f,
	std::function<double(double)> fDer,
	double& diffSchemeDeriv,
	double& analyticalDeriv) {
	diffSchemeDeriv = diffSchDer(point, delta, f);
	analyticalDeriv = der(point, fDer);
	return (std::abs((f(point + delta) - f(point)) / delta - fDer(point)) < acc) ? true : false;
}

void launchDerivativeVerify(double point, double delta,
							double acc, double& diffSchemeDeriv,
							double& analyticalDeriv) {
	verifyDerivative(point, delta, acc, fPlane, fPlaneDer, 
					 diffSchemeDeriv, analyticalDeriv);
}

/********verifying methods********/

/******** Newton ********/

void printSteps4Newton(double t, double tIter, int numIter,
					   std::function<double(double)> f, 
					   std::function<double(double)> fDer) {
	std::cout << std::scientific << std::setprecision(17)
	<< "iter:" <<std::setw(3) << numIter
	<< " fDer: " << std::setw(23) << fDer(t)
	<< " f: " << std::setw(25) << f(t)
	<< " t: " << std::setw(23) << tIter << std::endl;
}

double newton(const double eps, const double xInit, int* numIter,
	std::function<double(double)> f, std::function<double(double)> fDer) {
	double tk{};
	if (eps < 1)
		tk = xInit + 1; //not 2 give a chance for tk be equal to tk1 before iterations
	else
		tk = xInit + eps ;
	double tk1{ xInit };
	//printSteps4Newton(tk, tk1, *numIter, f, fDer);
	while ((std::abs(tk1 - tk) > eps) && (*numIter < 20)) {
		tk = tk1;
		tk1 = tk - f(tk) / fDer(tk);
		(*numIter)++;
		//printSteps4Newton(tk, tk1, *numIter, f, fDer);
	}
	return tk1;
}

double timeSurvNewton(double eps, double tInit, int* numIter) {
	return newton(eps, tInit, numIter, fPlane, fPlaneDer); //fPlane, fPlaneDer
}

/******** Newton ********/



