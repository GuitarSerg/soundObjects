#ifndef SURVEYSOLUTION_20200824_SURVEYOBJECTS_H
#define SURVEYSOLUTION_20200824_SURVEYOBJECTS_H

#include"vector3.h"

class SurveyObjects
{
	private:
			double m_x;
			double m_y;
			double m_z;
	public:
		SurveyObjects() = default;

		SurveyObjects(double lam, double phi);

		~SurveyObjects();

		double getX() { return m_x; }

		double getY() { return m_y; }

		double getZ() { return m_z; }

		Vector3 getVectorOfObject() { return Vector3{ m_x, m_y, m_z }; }
};

#endif