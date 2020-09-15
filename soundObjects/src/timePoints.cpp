#include "stdafx.h"
#include "..\include\timePoints.h"


TimePoints::TimePoints(std::vector<double> timePointsVect)
{
	//std::vector<TimePoints>::const_iterator it{m;
	m_timePointsVect = timePointsVect;
	//for (auto t : timePointsVect) {
	//	m_timePointsVect.push_back(t);
	//}
}


TimePoints::~TimePoints()
{
}

// reserve for TimePoints::TimePoints( file with time data to read )
