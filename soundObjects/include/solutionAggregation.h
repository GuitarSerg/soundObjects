#ifndef SURVEYSOLUTION_20200921_SOLUTIONAGGREGATION_H
#define SURVEYSOLUTION_20200921_SOLUTIONAGGREGATION_H

#include<map>
#include<string>
#include<surveyData.h>
#include<vector>

struct SurveySolutionData
{
	//new snippet//
	double m_tRoot;
	double m_roll;
	double m_tApprox;
	AngularCoordinates m_angularCoord;
	//new snippet//
};

class SolutionAggregation
{
private:
	std::map<std::string, std::vector<SurveySolutionData*>> m_mapSolutions;
	friend class Display;
public:
	SolutionAggregation(SurveyData &dataStorage);
	~SolutionAggregation();

	void launchLoop(SurveyData &dataStorage);
};

#endif