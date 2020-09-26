#include "stdafx.h"
#include "..\include\solutionAggregation.h"

#include"interpolation.h"
#include<iostream>
#include<memory>
#include"targets.h"

SolutionAggregation::SolutionAggregation(SurveyData &dataStorage)
{
	launchLoop(dataStorage);
}

SolutionAggregation::~SolutionAggregation()
{
}

void SolutionAggregation::launchLoop(SurveyData &dataStorage)
{
	std::vector<double> *ptrTimeAppVect{
		&(dataStorage.getTimeStorage().getTimeApproximateVect()) };
	std::vector<std::shared_ptr<Vector3>> *ptrTargetsVect{
		&(dataStorage.getTargetStorage().getTargetsVector()) };
	auto timeIt = ptrTimeAppVect->cbegin();
	auto targetIt = ptrTargetsVect->cbegin();
	auto angVectIt = dataStorage.getTargetStorage().getAnglesVect().cbegin();

	Interpolation iObj{ dataStorage };
	while (timeIt != ptrTimeAppVect->cend() && targetIt != ptrTargetsVect->cend()) {
		// second condition placed here just for insurance, because size of timeApproximateVect = size of TargetsVect always 
		double tApprox{ *timeIt };
		m_mapSolutions["Linear"].push_back(
			SurveySolutionData{ 
				iObj.evaluateLinearTime(dataStorage, tApprox, *targetIt),
				iObj.evaluateLinearRoll(dataStorage, *targetIt),
				tApprox,
				*angVectIt }
		);

		m_mapSolutions["Quadratic"].push_back(
			SurveySolutionData{
				iObj.evaluateQuadraticTime(dataStorage, tApprox, *targetIt),
				iObj.evaluateQuadraticRoll(dataStorage, *targetIt),
				tApprox,
				*angVectIt }
		);

		timeIt++;
		targetIt++;
		angVectIt++;
	}
}
