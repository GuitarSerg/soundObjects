#include "stdafx.h"

#include<algorithm>
#include<iostream>
#include "..\include\timePoints.h"

TimePoints::TimePoints(double tStart, double tEnd, double tStep,
	std::vector<double> &timeSurveyPointsVect,
	std::vector<double> &timeApproximateVect)
{
	setTimePointsVect(tStart, tEnd, tStep);
	setTimeSurveyPointsVect(timeSurveyPointsVect);
	setTimeApproximateVect(timeApproximateVect);
}

void TimePoints::setTimePointsVect(double tStart, double tEnd, double tStep)
{
	std::size_t vectSize{ static_cast<std::size_t>((tEnd - tStart) / tStep) };
	m_timePointsVect.resize(vectSize);
	std::generate(m_timePointsVect.begin(), m_timePointsVect.end(),
		[t = tStart, tSt = tStep]() mutable {t += tSt; return t; });
}

void TimePoints::setTimeSurveyPointsVect(std::vector<double> &timeSurveyPointsVect)
{
	m_timeSurveyPointsVect = timeSurveyPointsVect;
}

void TimePoints::setTimeApproximateVect(std::vector<double> &timeApproximateVect)
{
	m_timeApproximateVect = timeApproximateVect;
}

std::tuple<double, double, double> TimePoints::getThreeTimesCloseTo(double tApproximate)
{
	auto it = m_timePointsVect.cbegin();
	double tStep{ *(it + 1) - *it };
	auto itApprox = std::lower_bound(m_timePointsVect.begin(),
		m_timePointsVect.end(),
		tApproximate);
	double t0{};
	if ((*itApprox - tApproximate) >= tStep / 2.0)
		t0 = *(--itApprox);
	else
		t0 = *itApprox;
	double t_1{ *(itApprox - 1) };
	double t1{ *(itApprox + 1) };

	return{ t_1, t0, t1 };  // t_1 < t_0 < t1
}

std::tuple<double, double> TimePoints::getTwoTimesCloseTo(double tApproximate)
{
	auto it = m_timePointsVect.cbegin();
	double tStep{ *(it + 1) - *it };
	auto itApprox = std::lower_bound(m_timePointsVect.begin(),
		m_timePointsVect.end(),
		tApproximate);

	double t0{ *(itApprox - 1) };
	double t1{ *itApprox };

	return{ t0, t1 }; 
}

// reserve for TimePoints::TimePoints( file with time data to read )
