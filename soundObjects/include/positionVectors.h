#ifndef SURVEYSOLUTION_20200826_POSITIONVECTORS_H
#define SURVEYSOLUTION_20200826_POSITIONVECTORS_H

#include"Orbit.h"
#include"SurveyObjects.h"
#include"vector3.h"
#include"velocityOrbit.h"

class PositionVectors
{
	private:
		Vector3 sA;
		Vector3 sB;
		Vector3 s; // radii vect of sat at the moment t
		Vector3 v; // velocity of sat at the moment t
		Vector3 p;
	public:
		PositionVectors() = default;

		PositionVectors(Orbit& satA,
						Orbit& satB,
						SurveyObjects& point);

		~PositionVectors();

		void setVector_s(double t);
		void setVector_v(double t);

		Vector3 getVector_sA() { return sA; }
		Vector3 getVector_sB() { return sB; }
		Vector3 getVector_s() { return s; }
		Vector3 getVector_p() { return p; }
		Vector3 getVector_v() { return v; }
};

#endif