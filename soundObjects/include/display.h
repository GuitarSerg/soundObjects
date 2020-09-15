#ifndef SURVEYSOLUTION_20200914_DISPLAY_H
#define SURVEYSOLUTION_20200914_DISPLAY_H

#include"interpolation.h"

class Display
{
public:
	Display(Interpolation& approximateSolution);
	~Display();

	void printSurveyTime(Interpolation& approximateSolution);
};

#endif