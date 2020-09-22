#include "stdafx.h"
#include "..\include\calculation.h"

#include <algorithm>
#include"display.h"
#include"globalConstants.h"
#include"interpolation.h"
#include"orbital.h"
#include"solutionAggregation.h"
#include"surveyData.h"
#include"targets.h"
#include"timePoints.h"

Calculation::Calculation()
{

	SurveyData dataStorage{};
	SolutionAggregation solutions{ dataStorage };
	Display displayObject{ solutions };

}


Calculation::~Calculation()
{
}
