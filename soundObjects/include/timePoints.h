#ifndef SURVEYSOLUTION_20200909_TIMEPOINTS_H
#define SURVEYSOLUTION_20200909_TIMEPOINTS_H

#include<iostream>
#include<tuple>
#include<vector>

class TimePoints
{
private:
	std::vector<double> m_timePointsVect; // all time points from 0 to T with fixed step dT
	std::vector<double> m_timeSurveyPointsVect; // tA, tB
	std::vector<double> m_timeApproximateVect;  // only tApproximate 
public:
	TimePoints() = default;
	TimePoints(double tStart, double tEnd, double tStep,
		std::vector<double> &timeSurveyPointsVect,
		std::vector<double> &timeApproximateVect);
	
	// reserve for TimePoints( file with time data to read )

	void setTimePointsVect(double tStart, double tEnd, double tStep);
	void setTimeSurveyPointsVect(std::vector<double> &timeSurveyPointsVect);
	void setTimeApproximateVect(std::vector<double> &timeApproximateVect);

	std::tuple<double, double, double> getThreeTimesCloseTo(double tApproximate);
	std::tuple<double, double> getTwoTimesCloseTo(double tApproximate);

	std::vector<double>& getTimePointsVect() { return m_timePointsVect; }
	std::vector<double>& getTimeApproximateVect() { return m_timeApproximateVect; }
	double getTimeStep() { return (m_timePointsVect.at(1) - m_timePointsVect.at(0)); } 
};

#endif

