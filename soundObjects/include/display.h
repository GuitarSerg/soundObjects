#ifndef SURVEYSOLUTION_20200914_DISPLAY_H
#define SURVEYSOLUTION_20200914_DISPLAY_H

#include"solutionAggregation.h"

class Display
{
private:
	int m_typeWidth;
	int m_rootWidth;
	int m_rootPrec;
	int m_rollWidth;
	int m_rollPrec;
	int m_tApproxWidth;
	int m_tApprPrec;
	int m_phiWidth;
	int m_lamWidth;
	int m_angularPrec;
public:
	Display(SolutionAggregation &solutions);
	~Display();

	void printSolutions(SolutionAggregation &solutions);
private:
	void setWidthsAndPrecisions();
};

#endif