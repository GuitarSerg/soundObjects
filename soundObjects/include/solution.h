#ifndef SURVEYSOLUTION_20200914_SOLUTION_H
#define SURVEYSOLUTION_20200914_SOLUTION_H

//#include"targets.h"

class Solution
{
	private:
		double m_tA;
		double m_tB;
		double m_tSol;
		//AngularCoordinates m_angularPhiLam;
	public:
		Solution(double tA, double tB, double tSol/*, AngularCoordinates &angularPhiLam*/);
		~Solution();

		double get_tA() { return m_tA; }
		double get_tB() { return m_tB; }
		double get_tSol() { return m_tSol; }
		//AngularCoordinates getAngularCoordinates() { return m_angularPhiLam; }
};

#endif
