#ifndef SURVEYSOLUTION_20200824_ORBIT_H
#define SURVEYSOLUTION_20200824_ORBIT_H

class Orbit
{
	private:
		double m_x;
		double m_y;
		double m_z;
		double m_vx;
		double m_vy;
		double m_vz;
		double m_ax;
		double m_ay;
		double m_az;
	public:
		Orbit() = default;

		Orbit(double t, double radOrb);

		~Orbit();
	
		double getX() { return m_x; }
	
		double getY() { return m_y; }
	
		double getZ() { return m_z; }

		double getVx() { return m_vx; }

		double getVy() { return m_vy; }

		double getVz() { return m_vz; }

		double getAx() { return m_ax; }

		double getAy() { return m_ay; }

		double getAz() { return m_az; }


};

#endif