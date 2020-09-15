#ifndef SURVEYSOLUTION_20200915_SOLUTION_H
#define SURVEYSOLUTION_20200915_SOLUTION_H

#include<functional>
#include"interpolation.h"
#include<map>
#include"orbital.h"
#include"solution.h"
#include"targets.h"
#include"timePoints.h"
#include<vector>

class SolutionLoop
{
	private:
		std::vector<double> m_timePoints;
		std::vector<int> m_targetIndices;
		std::vector<double> m_timeApproximate;

		std::vector<std::string> m_algoTypesVect;// { "Linear", "Quadratic" };
		std::map<std::string, std::vector<Solution*>> m_mapSolutions;
	public:
		SolutionLoop()=default;
		SolutionLoop(Orbital& earthOrbit, TimePoints& timeStorage, Targets& targetStorage);
		~SolutionLoop();
		void setAlgoTypes();
		void launchLoop(Orbital& earthOrbit, Targets& targetStorage,
			TimePoints& timeStorage,
			const std::string& algoType,
			double (Interpolation::*timeFunc)(Orbital&, Targets&,
				TimePoints&, double, double, int));
};

#endif