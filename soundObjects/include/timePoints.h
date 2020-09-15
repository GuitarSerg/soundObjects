#ifndef SURVEYSOLUTION_20200909_TIMEPOINTS_H
#define SURVEYSOLUTION_20200909_TIMEPOINTS_H

#include<vector>

//struct TimeSegment {
//	double tA; //begin of the segment
//	double tB; //end of the segment
//};

class TimePoints
{
	private:
		std::vector<double> m_timePointsVect;
	public:

		TimePoints(std::vector<double> timePointsVect);
		// reserve for TimePoints( file with time data to read )
		~TimePoints();

		std::vector<double> getTimePointsVect() { return m_timePointsVect; }
		double getTimeStep() { return (m_timePointsVect.at(1) - m_timePointsVect.at(0)); }
};

#endif

