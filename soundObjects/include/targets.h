#ifndef SURVEYSOLUTION_20200911_TARGETS_H
#define SURVEYSOLUTION_20200911_TARGETS_H

#include<memory>
#include"timePoints.h"
#include<vector>
#include<vector3.h>

struct AngularCoordinates {
	double m_lam;
	double m_phi;
};

typedef std::vector<AngularCoordinates> VectorOfAngles;

class Targets
{
private:
	VectorOfAngles m_anglesVect;
	//Vector3 m_radiusVector;
	std::vector<std::shared_ptr<Vector3>> m_targetsVect; // vector of{ x,y,z } of every obj
public:
	Targets() = default;
	Targets(std::vector<std::shared_ptr<Vector3>>& vectOfObjVectors);
	Targets(double radProbingSphere, VectorOfAngles &anglesVect); // it constructs vector of {x,y,z} of every obj
	~Targets();

	void setTargetsVect(double radProbingSphere, VectorOfAngles& anglesVect);

	std::vector<std::shared_ptr<Vector3>>& getTargetsVector() { return m_targetsVect; }
	VectorOfAngles& getAnglesVect() { return m_anglesVect; }

private:
	void setObjectCoord(double &x, double &y, double &z,
		double radProbingSphere,
		const AngularCoordinates &anglesPair);
};

#endif