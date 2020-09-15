// main.cpp
//

#include "stdafx.h"
#include<iostream>

#include"calculation.h"
#include"calculationOfTimeAndRoll.h"
#include"globalConstants.h"
#include"interpolationSolution.h"
#include<iomanip>
#include"numericalSolution.h"
#include"Orbit.h"
#include"positionVectors.h"
#include"radiusVector3.h"
#include"roll.h"
#include<string>
#include"SurveyObjects.h"
#include"timePoints.h"
#include<vector>
#include"vector3.h"
#include"vectorConstructor.h"

using std::cout;
using std::endl;

int main()
{
	std::vector<std::vector<int>> vect(3);// { {1, 2, 3, 4, 5}, { 1,2,5 }, { -1,-5,-8 } };
	vect.push_back({ -5,-6,-7 });
	vect.at(0).push_back(10);
	
	Calculation calculator{};
	//Vector3 xVect{ 0,1,2 };
	//RadiusVector3 rVect{ 0,0 };
	////xVect.printVector();
	////printVector(Vector3{ 0,1,2 });
	//TimePoints timeStorage{ std::vector<TimeSegment>{ {240.0, 270.0 } } }; // tA = 240.0, tB = 270.0
	//VectorConstructor vectStor{ timeStorage, 
	//							pointsContainer{ new RadiusVector3{ 0, 30 * PI / 180 }},
	//							satteliteContainter{{new Vector3{2,2,2}, 
	//												 new Vector3{3,3,3}}}
	//};
	//
	//pointsContainer point{ vectStor.getVectorPointVecPtrs() };
	//Vector3 pointVect{ vectStor.getPointVectorNo(0) };
	//
	//pointsContainer satVect{ new Vector3{0, 1, 2}, new Vector3{1, 2, 3} };
	//for (auto s : satVect)
	//	s->printVector();

	//std::vector<Vector3*> satteliteVect;
	//satteliteVect = satVect;
	//satVect.push_back(new Vector3{ 3,3,3 });
	/*std::vector<TimeSegment> tVect{ {240.0, 270.0} };
	TimePoints timeStorage{ tVect };*/
//	TimePoints timeStorage{ std::vector<TimeSegment>{ {240.0, 270.0 } } };

	//double tStep{ 30.0 }; // 30 sec
	//double tA{ 240.0 }; // 300 sec
	//double tB{ tA + tStep }; // closest time to tA ( 330 sec here)
	//
	//SurveyObjects point{ 0, 30 * PI / 180 };
	//Orbit satA{ tA, phys::rOrb }, satB{ tB, phys::rOrb };
	///*Vector3 pointVect{ point.getX(), point.getY(), point.getZ() };*/
	//PositionVectors posVectors{ satA, satB, point };

	//CalculationOfTimeAndRoll calcObj(tA, tB, satA, satB, point, posVectors);
	//printResults(calcObj);

	system("pause>>void");
	return 0;
}


//std::cout << std::setprecision(10)
//		  << posVectors.getVector_sA().magnitude() << ' '
//		  << posVectors.getVector_sB().magnitude()
//		  << std::endl;

/*double t0_start{ 210.0 };
std::vector<double> tTest;
while (t0_start < 227) {
tTest.push_back(t0_start);
t0_start += 0.49;
}
for (auto t : tTest)
std::cout << "rounded " << t << " is "
<< quadraticInterpTime(tA, tB, t, satA, satB, point) <<
std::endl;*/



//int numIter{};
//double tApprox{ timeApproximate(tA, tB, satA, satB, point) };
//double tSurvLinear{ timeSurvLinearInterp(tA, tB, satA, satB, point) };
//double tSurvQuadratic{ timeSurvQuadraticInterp(tA, tB, satA, satB, point) };
//double tQuadr{ quadraticInterpTime(tA, tB, tApprox, satA, satB, point) };
//double tSurvNewton{ timeSurvNewton(1.0e-13, tA, &numIter) }; // (eps, tInitial, &numIter)
/////*** HERE ROLL IS A TANGENT OF A ROLL'S ANGLE ***///
//double rollSurvLinear{ rollSurv(tSurvLinear, posVectors) };
//double rollSurvQuadratic{ rollSurv(tSurvQuadratic, posVectors) };
//double rollQuadratic{ rollSurv(tQuadr, posVectors) };
//double rollSurvNewton{ rollSurv(tSurvNewton, posVectors) };
//std::string timeDim{ "(sec): " }, rollDim{ "(degrees): " };
//cout << std::setw(30) << "tSurvLinear" + timeDim <<
//		std::setprecision(10) << tSurvLinear << endl;
//cout << std::setw(30) << "rollSurvLinear" + rollDim <<
//		rollSurvLinear << endl;
//cout << std::setw(30) << "tSurvQuadratic" + timeDim << tSurvQuadratic << endl;
//cout << std::setw(30) << "rollSurvQuadratic" + rollDim << rollSurvQuadratic << endl;
//cout << std::setw(30) << "tQuadratic" + timeDim << tQuadr << endl;
//cout << std::setw(30) << "rollQuadratic" + rollDim << rollQuadratic << endl;
//cout << std::setw(30) << "tSurvNewton" + timeDim << tSurvNewton << endl;
//cout << std::setw(30) << "rollSurvNewton" + rollDim << rollSurvNewton <<
//						 " \nfor " << numIter << " iterations" <<endl;

//cout << "diff btw Linear and Newton: " << (tSurvLinear - tSurvNewton) << endl;
//cout << "diff btw Linear and Newton(roll): " << (rollSurvLinear - rollSurvNewton) << endl;
//cout << "diff btw Quadratic and Newton: " << (tSurvQuadratic - tSurvNewton) << endl;
//cout << "diff btw Quadratic and Newton(roll): " << (rollSurvQuadratic - rollSurvNewton) << endl;
//cout << "diff btw Quadratic and Quadratic(new): " << (tSurvQuadratic - tQuadr) << endl;
//cout << "diff btw Quadratic and Quadratic(roll): " << (rollSurvQuadratic - rollQuadratic) << endl;


/*cout << "tApprox: " << timeApproximate(tA, tB, satA, satB, point) << endl; */
// what's with the result with approximate ??? 



/*Vector3 sA3(satA.getX(), satA.getY(), satA.getZ());
Vector3	sB3(satB.getX(), satB.getY(), satB.getZ());
sA3.normalize();
sB3.normalize();
Vector3 normal3{ sA3.cross(sB3) };
normal3.normalize();
Vector3 p3(point.getX(), point.getY(), point.getZ());
p3.normalize();

p3.projectOnPlane(normal3);
p3.normalize();

double tSurv3{ tA + sqrt(2 * (1 - sA3*p3)) / (phys::wS - phys::wE) };*/




//class SurveyObject {
//private:
//	double m_x;
//	double m_y;
//	double m_z;
//public:
//	SurveyObject(double lam, double phi) {
//		m_x = phys::rEarth * cos(phi) * cos(lam);
//		m_y = phys::rEarth * cos(phi) * sin(lam);
//		m_z = phys::rEarth * sin(phi);
//	}
//
//	double getX() {
//		return m_x;
//	}
//
//	double getY() {
//		return m_y;
//	}
//
//	double getZ() {
//		return m_z;
//	}
//};
//
//class Orbit {
//private:
//	double m_x;
//	double m_y;
//	double m_z;
//public:
//	Orbit(double t) {
//		m_x = phys::rEarth*(cos(phys::wS*t)*cos(phys::wE*t)
//			+ cos(phys::incl)*sin(phys::wS*t)*sin(phys::wE*t));
//		m_y = phys::rEarth*(-cos(phys::wS*t)*sin(phys::wE*t)
//			+ cos(phys::incl)*sin(phys::wS*t)*cos(phys::wE*t));
//		m_z = phys::rEarth*sin(phys::incl)*sin(phys::wS*t);
//	}
//
//	double getX() {
//		return m_x;
//	}
//
//	double getY() {
//		return m_y;
//	}
//
//	double getZ() {
//		return m_z;
//	}
//};

// --------- ---------
//class Vector {
	//private:
	//	double m_x, m_y, m_z; //prjections of the vector
	//						  //double m_x0, m_y0, m_z0; //beginning of the vector
	//public:
	//	Vector(double x, double y, double z,
	//		double x0 = 0, double y0 = 0, double z0 = 0) :
	//		m_x(x - x0), m_y(y - y0), m_z(z - z0) {
	//		// in case beginning is (0,0,0) it's implemented by default
	//	}
	//
	//	double getX() {
	//		return m_x;
	//	}
	//
	//	double getY() {
	//		return m_y;
	//	}
	//
	//	double getZ() {
	//		return m_z;
	//	}
	//
	//	double getLength() {
	//		return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
	//	}
	//
	//	void normalizeSlow() {
	//		double vectLen{ getLength() };
	//		m_x /= vectLen;
	//		m_y /= vectLen;
	//		m_z /= vectLen;
	//	}
	//
	//	void project2Plane(const Vector &norm);
	//	//projection; normalization(odrinary and specific - 2 cases)
	//};
	//
	//class VectorProducts {
	//protected:
	//	Vector m_vect1, m_vect2;
	//	/*double x1, y1, z1;
	//	double x2, y2, z2;*/
	//public:
	//	VectorProducts(const Vector &vect1, const Vector &vect2) :
	//		m_vect1(vect1), m_vect2(vect2) {
	//	}
	//};
	//
	//class OuterProduct : public VectorProducts { // outer product of v1 and v2
	//public:
	//	OuterProduct(const Vector &vect1, const Vector &vect2) :
	//		VectorProducts(vect1, vect2) {
	//	}
	//
	//	double getX() {
	//		return m_vect1.getY()*m_vect2.getZ() - m_vect1.getZ()*m_vect2.getY();
	//	}
	//
	//	double getY() {
	//		return  -m_vect1.getX()*m_vect2.getZ() + m_vect1.getZ()*m_vect2.getX();
	//	}
	//
	//	double getZ() {
	//		return m_vect1.getX()*m_vect2.getY() - m_vect1.getY()*m_vect2.getX();
	//	}
	//
	//	Vector getOuterProduct() {
	//		return Vector(getX(), getY(), getZ());
	//	}
	//};
	//
	//class InnerProduct : public VectorProducts {
	//public:
	//	InnerProduct(const Vector &vect1, const Vector &vect2) :
	//		VectorProducts(vect1, vect2) {
	//	}
	//
	//	double getResult() {
	//		return m_vect1.getX()*m_vect2.getX() + m_vect1.getY()*m_vect2.getY() +
	//			m_vect1.getZ()*m_vect2.getZ();
	//	}
	//};
	//
	//void Vector::project2Plane(const Vector &norm) {
	//	Vector thisVect(m_x, m_y, m_z);
	//	InnerProduct prod(norm, thisVect);
	//	double scalarProd{ prod.getResult() };
	//	m_x -= scalarProd*norm.m_x;
	//	m_y -= scalarProd*norm.m_y;
	//	m_z -= scalarProd*norm.m_z;
	//}
	//
	//
	///********some operations with vectors********/
	//double vectorLength(double* vect) {
	//	return sqrt(pow(vect[0], 2) + pow(vect[1], 2) + pow(vect[2], 2));
	//}
	//
	//// length; 
	//
	//// IT'S REASONABLE TO CREATE CLASS FOR ORDINARY 3D VECTORS WITH THIS METHODS
	//
	//
	///********some operations with vectors********/
	//
	////void printResultVector3Class() {
	////	std::cout << "Iner product Vector3Class: " << 
	////}



	// --- older mode ---


	//Vector sA(satA.getX(), satA.getY(), satA.getZ());
	//sA.normalizeSlow();
	//Vector sB(satB.getX(), satB.getY(), satB.getZ());
	//sB.normalizeSlow();
	//Vector p(point.getX(), point.getY(), point.getZ());
	//p.normalizeSlow();
	////	cout << sA.getLength() << ' ' << sB.getLength() << ' ' << p.getLength() << endl;

	//OuterProduct normal2Plane(sA, sB);
	//Vector normal{ normal2Plane.getOuterProduct() };
	////cout << normal.getLength() << endl;
	//normal.normalizeSlow();
	////	cout << normal.getLength() << endl;
	//p.project2Plane(normal);
	////	cout << p.getLength() << endl;
	//p.normalizeSlow();
	//cout << p.getLength() << endl;

	//InnerProduct scProd(sA, p);
	//double scalarProd{ scProd.getResult() };
	//double tSurv{ tA + sqrt(2 * (1 - scalarProd)) / (phys::wS - phys::wE) };

	//cout << tSurv << endl;

	// --- older mode ---

	//Vector3 vect1{ 1, 2, 2 };
	//Vector3 vect2{ 3, 2, -1 };
	//Vector3 vect3{ vect1.cross(vect2) }; // vector for cross product
	//Vector3 p{ 1, 2, 1 };

	//std::cout << "Inner product Vector3Class: " << vect1*vect2 << std::endl;
	//std::cout << "Cross product Vector3Class: ";
	//vect3.printVector();
	//vect3.normalize();
	//std::cout << "Normalized Vector3 vect's length: " << vect3.magnitude()
	//	<< std::endl;
	//p.normalize();
	//p.projectOnPlane(vect3);
	//std::cout << "Projected Vector3 vect's length: " << p.magnitude() << std::endl;

	//Vector vVect1{ 1, 2, 2 };
	//Vector vVect2{ 3, 2, -1 };
	//InnerProduct inPr{ vVect1, vVect2 };
	//OuterProduct outPr{ vVect1, vVect2 };

	//std::cout << "Inner product Vector Class: " << inPr.getResult() << std::endl;
	//std::cout << "Cross product Vector Class: ";
	//std::cout << "x: " << std::setw(5) << outPr.getX() << ' ' <<
	//	"y: " << std::setw(5) << outPr.getY() << ' ' <<
	//	"z: " << std::setw(5) << outPr.getZ() << ' ' <<
	//	std::endl;
	//Vector vVect3{ outPr.getOuterProduct() };
	//vVect3.normalizeSlow();
	//std::cout << "Normalized vect's length: " << vVect3.getLength();
	//Vector vp{ 1, 2, 1 };
	//vp.normalizeSlow();
	//vp.project2Plane(vVect3);
	//std::cout << "Projected vect's length: " << vp.getLength() << std::endl;



	//Vector vVect3{}



	//double TOrb{ 2 * math::PI / phys::wS };
	///*double pow1{ 1.0 / 3.0 }, pow2{ 2.0 / 3.0 };
	//double radOrb{ pow((G*mEarth), (1.0/3.0))*pow((5400 / 2 / math::PI), (2.0 / 3.0)) };*/
	////cout << 2*math::PI/wS << endl;
