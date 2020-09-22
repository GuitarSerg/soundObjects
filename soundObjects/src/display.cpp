#include "stdafx.h"
#include "..\include\display.h"

#include"globalConstants.h"
#include<iomanip>
#include<iostream>

Display::Display(SolutionAggregation &solutions)
{
	printSolutions(solutions);
}

Display::~Display()
{

}

void Display::printSolutions(SolutionAggregation &solutions)
{
	auto it = solutions.m_mapSolutions.cbegin();
	std::size_t solAmount{ it->second.size() }; // it's well-known that all the vectors of solutions are of equal size
	std::size_t iSol{ 0 }; //iSol
	while (iSol < solAmount) {
		for (auto mapIt : solutions.m_mapSolutions) {
			setWidthsAndPrecisions();

			std::cout << std::setw(m_typeWidth)
				<< mapIt.first << ": ";
			std::cout.precision(m_rootPrec);
			std::cout << "root: " << std::scientific <<
				std::setw(m_rootWidth) << mapIt.second.at(iSol)->m_tRoot << ' ';
			std::cout.precision(m_rollPrec);
			std::cout << "roll: " << std::defaultfloat <<
				std::setw(m_rollWidth) << mapIt.second.at(iSol)->m_roll << ' ';
			std::cout.precision(m_tApprPrec);
			std::cout << "tApp was " << std::fixed <<
				std::setw(m_tApproxWidth) << mapIt.second.at(iSol)->m_tApprox << ' ';
			std::cout.precision(m_angularPrec);
			std::cout << "(lam, phi): " << std::defaultfloat <<
				std::setw(m_phiWidth) <<
				mapIt.second.at(iSol)->m_angularCoord.m_lam * 180 / PI << ':' <<
				std::setw(m_lamWidth) <<
				mapIt.second.at(iSol)->m_angularCoord.m_phi * 180 / PI <<
				std::endl;
		}
		iSol++;
		std::cout << '\n';
	}
}

void Display::setWidthsAndPrecisions()
{
	m_typeWidth = 9;

	m_rootWidth = 10;
	m_rootPrec = 6;

	m_rollWidth = 5;
	m_rollPrec = 3;

	m_tApproxWidth = 4;
	m_tApprPrec = 2;

	m_phiWidth = 3;
	m_lamWidth = m_phiWidth;
	m_angularPrec = 3;
}
