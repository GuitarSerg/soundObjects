#ifndef SURVEYSOLUTION_20200824_INTERPOLATIONSOLUTION_H
#define SURVEYSOLUTION_20200824_INTERPOLATIONSOLUTION_H

#include"Orbit.h"
#include"SurveyObjects.h"

double timeSurvLinearInterp(double tA, double tB,
	Orbit satA, Orbit satB,
	SurveyObjects& point);

double timeSurvQuadraticInterp(double tA, double tB,
	Orbit satA, Orbit satB,
	SurveyObjects point);

double timeApproximate(double tA, double tB,
	Orbit satA, Orbit satB,
	SurveyObjects point);

double quadraticInterpTime(double tA, double tB,
						   Orbit satA, Orbit satB, SurveyObjects point);

#endif
