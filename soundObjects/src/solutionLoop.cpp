#include "stdafx.h"
#include "..\include\solutionLoop.h"


SolutionLoop::SolutionLoop(Orbital& earthOrbit, TimePoints& timeStorage, Targets& targetStorage)
{
	m_timePoints = timeStorage.getTimePointsVect();
	//std::size_t targetStorSize{ targetStorage.getTargetsVector().size() };
	for (std::size_t i{ 0 }; i < targetStorage.getTargetsVector().size(); i++)
		m_targetIndices.push_back(static_cast<int>(i));
	m_timeApproximate.push_back(260.0); // bad tone to do like this!
	setAlgoTypes();

	launchLoop(earthOrbit, targetStorage, timeStorage, "Linear", &Interpolation::findLinearTime);
}

SolutionLoop::~SolutionLoop()
{
}

void SolutionLoop::setAlgoTypes() {
	m_algoTypesVect = { "Linear", "Quadratic" };
}

void SolutionLoop::launchLoop(Orbital& earthOrbit, Targets& targetStorage, 
							  TimePoints& timeStorage, 
							  const std::string& algoType,
							  double (Interpolation::*timeFunc)(Orbital&, Targets&,
								  TimePoints&, double, double, int)
							  /*std::function<double(Orbital&, Targets&, 
							  TimePoints&, double, double, int)> timeFunc*/) {
	std::size_t maxInd{};
	std::size_t targetStorSize{ targetStorage.getTargetsVector().size() };
	if (m_timePoints.size() > 2 * targetStorSize)
		maxInd = 2 * targetStorSize;
	else
		maxInd = m_timePoints.size()/2;

	std::vector<Solution*> solutionVect;

	for (std::size_t i{ 0 }; i < maxInd; i++) {
		double tA{ m_timePoints.at(i) };
		double tB{ m_timePoints.at(i + 1) };
		int indexSurvObj{ static_cast<int>(i) / 2 };

		Interpolation interpInstance;
		double timeRes{ (interpInstance.*timeFunc)(earthOrbit, targetStorage,timeStorage,
												   tA, tB, indexSurvObj) };

		solutionVect.push_back(new Solution(tA, tB, timeRes));
		//m_mapSolutions[algoType] = timeRes;
	}
	m_mapSolutions[algoType] = solutionVect;
}
