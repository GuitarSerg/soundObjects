#ifndef SURVEYSOLUTION_20200907_CALCULATIONOFTIMEANDROLL_H
#define SURVEYSOLUTION_20200907_CALCULATIONOFTIMEANDROLL_H

#include "interpolationSolution.h"
#include "numericalSolution.h"
#include "Orbit.h"
#include "positionVectors.h"
#include "roll.h"
#include "SurveyObjects.h"

class CalculationOfTimeAndRoll {
	private:
		double m_timeNewton;
		double m_timeLinear;
		double m_timeQuadratic;
		double m_timeQuadraticTest;
		double m_rollNewton;
		double m_rollLinear;
		double m_rollQuadratic;
		double m_rollQuadraticTest;
		int m_numIter;


	public:
		CalculationOfTimeAndRoll(double tA, double tB,
								 Orbit satA, Orbit satB,
								 SurveyObjects& point,
								 PositionVectors& posVectors);

		void setTimeNewton(double tA, double tB,
						     Orbit satA, Orbit satB,
						     SurveyObjects& point,
						     double eps, double tInit, 
						     int* numIter);
		void setTimeLinear(double tA, double tB,
						     Orbit satA, Orbit satB,
						     SurveyObjects& point);
		void setTimeQuadratic(double tA, double tB,
							    Orbit satA, Orbit satB,
							    SurveyObjects& point);
		void setTimeQuadraticTest(double tA, double tB,
								    Orbit satA, Orbit satB,
								    SurveyObjects& point);
		void setRollNewton(double t, PositionVectors& posVectors);
		void setRollLinear(double t, PositionVectors& posVectors);
		void setRollQuadratic(double t, PositionVectors& posVectors);
		void setRollQuadraticTest(double t, PositionVectors& posVectors);

		double getTimeNewton() { return m_timeNewton; }
		double getRollNewton() { return m_rollNewton; }
		double getTimeLinear() { return m_timeLinear; }
		double getRollLinear() { return m_rollLinear; }
		double getTimeQuadratic() { return m_timeQuadratic; }
		double getRollQuadratic() { return m_rollQuadratic; }
		double getTimeQuadraticTest() { return m_timeQuadraticTest; }
		double getRollQuadraticTest() { return m_rollQuadraticTest; }

		friend void printResults(CalculationOfTimeAndRoll& calcObj);
};

#endif
