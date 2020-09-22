#ifndef SURVEYSOLUTION_20200918_SURVEYDATA_H
#define SURVEYSOLUTION_20200918_SURVEYDATA_H

#include "orbital.h"
#include "targets.h"
#include "timePoints.h"

class SurveyData
{
private:
	TimePoints m_timeStorage;
	Orbital m_orbit;
	Targets m_targetStorage;

public:
	SurveyData();
	SurveyData(TimePoints &timeStorage, Orbital &orbit, Targets &targetStorage);

	~SurveyData();

	TimePoints& getTimeStorage() { return m_timeStorage; }
	Orbital& getOrbit() { return m_orbit; }
	Targets& getTargetStorage() { return m_targetStorage; }

	void setAllFields(TimePoints &timeStorage, Orbital &orbit, Targets &targetStorage);

	void checkIfEqual(std::size_t sizeApproxTimeVect, std::size_t sizeTargetStorage);
};

#endif