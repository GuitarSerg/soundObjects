#ifndef SURVEYSOLUTION_20200909_VECTORCONSTRUCTOR_H
#define SURVEYSOLUTION_20200909_VECTORCONSTRUCTOR_H

#include"timePoints.h"
#include<vector>
#include"vector3.h"

//struct SatteliteVectors {
//	Vector3* vectSatA; // position of Sattelite in a moment tA
//	Vector3* vectSatB; // position of Sattelite in a moment tB
//};
//
//typedef std::vector<Vector3*> pointsContainer;
//typedef std::vector<SatteliteVectors> satteliteContainter;


class VectorConstructor
{
	VectorConstructor();
	~VectorConstructor();
//private:
//	pointsContainer m_pointVect;
//	satteliteContainter m_satVect;
//public:
//	VectorConstructor() = default;
//	VectorConstructor(TimePoints &timeStorage,
//		pointsContainer pointVect);
//	VectorConstructor(TimePoints &timeStorage,
//		pointsContainer pointVect,
//		satteliteContainter satVect);
//	~VectorConstructor();
//
//	pointsContainer getVectorPointVecPtrs();
//	Vector3 getPointVectorNo(int i);
};

#endif
