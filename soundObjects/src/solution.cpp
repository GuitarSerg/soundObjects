#include "stdafx.h"
#include "..\include\solution.h"

Solution::Solution(double tA, double tB, double tSol/*, AngularCoordinates &angularPhiLam*/)
{
	m_tA = tA;
	m_tB = tB;
	m_tSol = tSol;
	/*m_angularPhiLam = angularPhiLam;*/
}

Solution::~Solution()
{
}
