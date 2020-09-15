#ifndef SURVEYSOLUTION_20200911_INTERPOLATION_H
#define SURVEYSOLUTION_20200911_INTERPOLATION_H

#include"orbital.h"
#include"solution.h"
#include"targets.h"
#include"timePoints.h"
#include<vector>

typedef std::vector<Solution*> TimeSurv;

class Interpolation
{
	private:
		std::vector<double> m_givenTimeDots;
		std::vector<double> m_timeLinear;
		std::vector<double> m_timeQuadratic;
		TimeSurv m_Linear;
		TimeSurv m_Quadratic;
	public:
		Interpolation()=default; //0.0 times
		Interpolation(Orbital &earthOrbit, Targets &targetStorage, 
			TimePoints &timeStorage, std::vector<AngularCoordinates> &angVect);
		~Interpolation();
		int defineTMax(TimePoints &timeStorage, Targets &targetStorage);

		double findTimeLinear(Orbital &earthOrbit, 
			Targets &targetStorage, TimePoints &timeStorage, 
			int iA, int iB, int iP);

		double findLinearTime(Orbital & earthOrbit, Targets & targetStorage, 
							  TimePoints &timeStorage,double tA, double tB, 
							  int targetIndex);

		double findTimeQuadratic(Orbital &earthOrbit, 
			Targets &targetStorage, TimePoints &timeStorage,
			int iA, int iB, int iP);

		void normalizeVectors(Vector3* vect1, Vector3* vect2, Vector3* vect3);
		void normalizeVectors(Vector3* vect1, Vector3* vect2);
		void normalizeVectors(Vector3* vect1);

		std::vector<double> getTimeLinear() { return m_timeLinear; }
		std::vector<double> getTimeQuadratic() { return m_timeQuadratic; }

		TimeSurv getLinear() { return m_Linear; }
		TimeSurv getQuadratic() { return m_Quadratic; }
};

#endif