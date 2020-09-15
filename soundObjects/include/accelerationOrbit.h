#ifndef SURVEYSOLUTION_20200826_ACCELERATIONORBIT_H
#define SURVEYSOLUTION_20200826_ACCELERATIONORBIT_H

class AccelerationOrbit
{
	private:
		double m_ax;
		double m_ay;
		double m_az;
	public:
		AccelerationOrbit() = default;

		AccelerationOrbit(double t, double radOrb);

		~AccelerationOrbit();

		double getAx() { return m_ax; }

		double getAy() { return m_ay; }

		double getAz() { return m_az; }
};

#endif
