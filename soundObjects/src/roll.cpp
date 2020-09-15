#include "stdafx.h"
#include <iostream>

#include"globalConstants.h"
#include"roll.h"
#include"vector3.h"

/******** Roll *********/

double rollSurv(double tSurv, PositionVectors& posVectors/*Vector3& pVect, Vector3& sVect, Vector3& vVect*/) {
	// finding of tSurv is time-consuming process, 
	// that's why it's passed as an argument !!!
	// n(t) = s(t) x v(t);  p - vect
	posVectors.setVector_s(tSurv);
	posVectors.setVector_v(tSurv);
	Vector3 s{ posVectors.getVector_s() };
	Vector3 p{ posVectors.getVector_p() };
	Vector3 v{ posVectors.getVector_v() };
	Vector3 nVect{ s.cross(v) };
	double H{ s.magnitude() };
	s.normalize();
	p.normalize();
	nVect.normalize();
	double sinAlf{ p*nVect };
	double cosAlf{ p*s };
	
	
	return atan(sinAlf / (1 - cosAlf + H / phys::rEarth))*180/PI;
}

/******** Roll *********/