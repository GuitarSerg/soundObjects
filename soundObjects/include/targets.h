#ifndef SURVEYSOLUTION_20200911_TARGETS_H
#define SURVEYSOLUTION_20200911_TARGETS_H

#include"timePoints.h"
#include<vector>
#include<vector3.h>

struct AngularCoordinates {
	double m_lam;
	double m_phi;
};

typedef std::vector<AngularCoordinates> AnglesContainer;

class Targets
{
	private:
		std::vector<Vector3*> m_targetsVect;
	public:
		Targets(double radProbingSphere, AnglesContainer &anglesVect);
		~Targets();

		void setObjectCoord(double &x, double &y, double &z, double radProbingSphere, AngularCoordinates angles);
		void setRadVect(double radProbingSphere, AnglesContainer& anglesVect);

		std::vector<Vector3*> getTargetsVector() { return m_targetsVect; }
};

#endif