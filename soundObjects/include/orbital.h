#ifndef SURVEYSOLUTION_20200911_ORBITAL_H
#define SURVEYSOLUTION_20200911_ORBITAL_H

#include"timePoints.h"
#include<vector>
#include<vector3.h>

class Orbital
{
	private:
		std::vector<Vector3*> m_radVect;
		std::vector<Vector3*> m_veloVect;
		std::vector<Vector3*> m_accelVect;
	public:
		Orbital(double radOrb, TimePoints& timeStorage);
		~Orbital();

		void setRadVect(double radOrb, TimePoints& timeStorage);
		//void setOrbitCoord(double radOrb, double t);
		void setVeloVect(double radOrb, TimePoints& timeStorage);
		void setAccelVect(double radOrb, TimePoints& timeStorage);
		void setOrbitCoord(double &x, double &y, double &z, 
						   double radOrb, double t);
		void setOrbitVelocities(double &x, double &y, double &z, 
							    double radOrb, double t);
		void setOrbitAccelerations(double &x, double &y, double &z, 
								   double radOrb, double t);

		std::vector<Vector3*> getRadVect() { return m_radVect; } //get the whole vector
		std::vector<Vector3*> getVeloVect() { return m_veloVect; } //get the whole vector
		std::vector<Vector3*> getAccelVect() { return m_accelVect; } //get the whole vector

		Vector3* getRadVectAt(double t, TimePoints& timeStorage); //get a 3D Vector3* from the whole vector at specific moment t

	private:
		double round(double t) { return ((t - floor(t)) >= 0.5) ? ceil(t) : floor(t); }

};

#endif