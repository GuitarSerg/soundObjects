#include "stdafx.h"

#include<cassert>
#include"globalConstants.h"
#include "..\include\surveyData.h"

SurveyData::SurveyData()
{
	std::vector<double> tSurvPointsVect{ { input::tA, input::tB } };
	std::vector<double> tApproximateVect{ input::tApprox, input::tApprox2 };
	TimePoints timeStorage{ 0.0, input::T, input::d_t,
		tSurvPointsVect, tApproximateVect };

	Orbital earthOrbit{};

	VectorOfAngles anglePairsVect{ {input::lam, input::phi},
	{ input::lam2, input::phi2 } };
	checkIfEqual(tApproximateVect.size(), anglePairsVect.size());
	Targets targetStorage{ phys::rEarth, anglePairsVect };

	setAllFields(timeStorage, earthOrbit, targetStorage);
}

SurveyData::SurveyData(TimePoints &timeStorage, Orbital &orbit, Targets &targetStorage)
{
	setAllFields(timeStorage, orbit, targetStorage);
}

SurveyData::~SurveyData()
{
}

void SurveyData::setAllFields(TimePoints &timeStorage, Orbital &orbit, Targets &targetStorage)
{
	m_timeStorage = timeStorage;
	m_orbit = orbit;
	m_targetStorage = targetStorage;
}

void SurveyData::checkIfEqual(std::size_t sizeApproxTimeVect, std::size_t sizeTargetStorage)
{
	assert(sizeApproxTimeVect == sizeTargetStorage);
}
