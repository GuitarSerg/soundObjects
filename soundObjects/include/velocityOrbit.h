#ifndef SURVEYSOLUTION_20200824_VELOCITYORBIT_H
#define SURVEYSOLUTION_20200824_VELOCITYORBIT_H

class VelocityOrbit
{
	private:
		double m_vx;
		double m_vy;
		double m_vz;
	public:
		VelocityOrbit() = default;

		VelocityOrbit(double t, double radOrb);
		~VelocityOrbit();

		double getVx() { return m_vx; }
		double getVy() { return m_vy; }
		double getVz() { return m_vz; }
};

#endif