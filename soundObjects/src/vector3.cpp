#include "stdafx.h"

#include<iomanip>
#include <iostream>
#include "vector3.h"

Vector3& Vector3::operator= (Vector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

bool Vector3::operator== (Vector3& v)
{
	if (fabs(x - v.x) < EPSILON)
		if (fabs(y - v.y) < EPSILON)
			if (fabs(z - v.z) < EPSILON)
				return true;
	return false;
}

double Vector3::magnitude()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector3::normalize()
{
	double magnitude = Vector3::magnitude(); 
	if (magnitude > 0)
	{
		double invertedMag = 1 / magnitude;
		x *= invertedMag;
		y *= invertedMag;
		z *= invertedMag;
	}
}

double Vector3::distance(Vector3& v)
{
	double dx = x - v.x;
	double dy = y - v.y;
	double dz = z - v.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

void Vector3::printVector() { // display cooardinates of vect
	{
		std::cout << "x: " << std::setw(5) << x << ' ' <<
		"y: " << std::setw(5) << y << ' ' <<
		"z: " << std::setw(5) << z << ' ' <<
		std::endl;
	}
}

void Vector3::projectOnPlane(/*Vector3& v, */Vector3& vNorm2Plane) {
	Vector3 v{ x, y, z };
	double innerProduct{ v * vNorm2Plane };
	x -= innerProduct * vNorm2Plane.x;
	y -= innerProduct * vNorm2Plane.y;
	z -= innerProduct * vNorm2Plane.z;
}

void printVector(const Vector3 &vector) {
	std::cout << "x: " << std::setw(5) << vector.x << ' ' <<
				 "y: " << std::setw(5) << vector.y << ' ' <<
				 "z: " << std::setw(5) << vector.z << ' ' <<
	std::endl;
}

//void Vector::project2Plane(const Vector &norm) {
//	Vector thisVect(m_x, m_y, m_z);
//	InnerProduct prod(norm, thisVect);
//	double scalarProd{ prod.getResult() };
//	m_x -= scalarProd*norm.m_x;
//	m_y -= scalarProd*norm.m_y;
//	m_z -= scalarProd*norm.m_z;
//}