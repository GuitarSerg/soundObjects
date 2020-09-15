#include"stdafx.h"

#include "calculationOfTimeAndRoll.h"
#include<iomanip>
#include<iostream>
#include<string>
#include"timePoints.h"
#include<vector>

CalculationOfTimeAndRoll::CalculationOfTimeAndRoll(double tA, double tB, 
												  Orbit satA, Orbit satB, 
												  SurveyObjects& point, 
												  PositionVectors& posVectors)
{
	//TimePoints timeStorage{ std::vector<TimeSegment>{ {240.0, 270.0 } } }; // tA = 240.0, tB = 270.0


	setTimeNewton(tA, tB, satA, satB, point, 1.0e-13, tA, &m_numIter);
	setTimeLinear(tA, tB, satA, satB, point);
	setTimeQuadratic(tA, tB, satA, satB, point);
	setTimeQuadraticTest(tA, tB, satA, satB, point);
	setRollNewton(m_timeNewton, posVectors);
	setRollLinear(m_timeLinear, posVectors);
	setRollQuadratic(m_timeQuadratic, posVectors);
	setRollQuadraticTest(m_timeQuadraticTest, posVectors);
}

void CalculationOfTimeAndRoll::setTimeNewton(double tA, double tB, 
											   Orbit satA, Orbit satB, 
											   SurveyObjects& point, 
											   double eps, double tInit, 
											   int* numIter)
{
	m_timeNewton = timeSurvNewton(eps, tInit, numIter);
}


void CalculationOfTimeAndRoll::setTimeLinear(double tA, double tB,
											   Orbit satA, Orbit satB,
											   SurveyObjects& point) 
{
	m_timeLinear = timeSurvLinearInterp(tA, tB, satA, satB, point);
}

void CalculationOfTimeAndRoll::setTimeQuadratic(double tA, double tB,
												  Orbit satA, Orbit satB,
												  SurveyObjects& point)
{
	m_timeQuadratic = timeSurvQuadraticInterp(tA, tB, satA, satB, point);
}

void CalculationOfTimeAndRoll::setTimeQuadraticTest(double tA, double tB,
													  Orbit satA, Orbit satB,
													  SurveyObjects& point)
{
	//double tApprox{ timeApproximate(tA, tB, satA, satB, point) };
	//double tApprox{ 256.0 };
	m_timeQuadraticTest = quadraticInterpTime(tA, tB, satA, satB, point);
}

void CalculationOfTimeAndRoll::setRollNewton(double tSurv, 
											 PositionVectors& posVectors)
{
	m_rollNewton = rollSurv(tSurv, posVectors);
}

void CalculationOfTimeAndRoll::setRollLinear(double tSurv, 
											 PositionVectors& posVectors)
{
	m_rollLinear = rollSurv(tSurv, posVectors);
}

void CalculationOfTimeAndRoll::setRollQuadratic(double tSurv, 
												PositionVectors& posVectors)
{
	m_rollQuadratic = rollSurv(tSurv, posVectors);
}

void CalculationOfTimeAndRoll::setRollQuadraticTest(double tSurv, 
												    PositionVectors& posVectors)
{
	m_rollQuadraticTest = rollSurv(tSurv, posVectors);
}

void printResults(CalculationOfTimeAndRoll& calcObj)
{
	std::string timeDim{ "(sec): " }, rollDim{ "(degrees): " };
	std::vector<std::string> timesArr{ "tSurvNewton", "tSurvLinear", 
									"tSurvQuadratic", "tSurvQuadraticTest" };
	std::vector<std::string> rollsArr{ "rollSurvNewton", "rollSurvLinear", 
									"rollSurvQuadratic", "rollSurvQuadraticTest" };
	int fieldWidth{ 60 };
	int precision{ 15 };
	//std::setprecision(10);
	std::cout << std::scientific << std::setw(fieldWidth) << std::setprecision(precision) 
	<< timesArr.at(0) + timeDim
	<< calcObj.m_timeNewton << std::endl;
	std::cout << std::setw(fieldWidth) << timesArr.at(1) + timeDim
	<< calcObj.m_timeLinear << std::endl;
	std::cout << std::setw(fieldWidth) << timesArr.at(2) + timeDim
	<< calcObj.m_timeQuadratic << std::endl;
	std::cout << std::setw(fieldWidth) << timesArr.at(3) + timeDim
	<< calcObj.m_timeQuadraticTest << std::endl << std::endl;

	std::cout << std::setw(fieldWidth) << rollsArr.at(0) + rollDim
	<< calcObj.m_rollNewton << std::endl;
	std::cout << std::setw(fieldWidth) << rollsArr.at(1) + rollDim
	<< calcObj.m_rollLinear << std::endl;
	std::cout << std::setw(fieldWidth) << rollsArr.at(2) + rollDim
	<< calcObj.m_rollQuadratic << std::endl;
	std::cout << std::setw(fieldWidth) << rollsArr.at(3) + rollDim
	<< calcObj.m_rollQuadraticTest << std::endl << std::endl;


	std::string diffBtw{ "diff btw " }, and {" and "};
	int diffFieldWid{ 60 };
	std::cout << std::setw(diffFieldWid) 
	<< diffBtw + timesArr[1] + and + timesArr[0] + timeDim 
	<< calcObj.m_timeLinear - calcObj.m_timeNewton << std::endl;
	std::cout << std::setw(diffFieldWid)
	<< diffBtw + timesArr[2] + and + timesArr[0] + timeDim
	<< calcObj.m_timeQuadratic - calcObj.m_timeNewton << std::endl;
	std::cout << std::setw(diffFieldWid)
	<< diffBtw + timesArr[3] + and + timesArr[0] + timeDim
	<< calcObj.m_timeQuadraticTest - calcObj.m_timeNewton << std::endl << std::endl;

	std::cout << std::setw(diffFieldWid)
		<< diffBtw + rollsArr[1] + and + rollsArr[0] + rollDim
		<< calcObj.m_rollLinear - calcObj.m_rollNewton << std::endl;
	std::cout << std::setw(diffFieldWid)
		<< diffBtw + rollsArr[2] + and + rollsArr[0] + rollDim
		<< calcObj.m_rollQuadratic - calcObj.m_rollNewton << std::endl;
	std::cout << std::setw(diffFieldWid)
		<< diffBtw + rollsArr[3] + and +rollsArr[0] + rollDim
		<< calcObj.m_rollQuadraticTest - calcObj.m_rollNewton << std::endl << std::endl;
	/*cout << "diff btw Linear and Newton(roll): " << (rollSurvLinear - rollSurvNewton) << endl;
	cout << "diff btw Quadratic and Newton: " << (tSurvQuadratic - tSurvNewton) << endl;
	cout << "diff btw Quadratic and Newton(roll): " << (rollSurvQuadratic - rollSurvNewton) << endl;
	cout << "diff btw Quadratic and Quadratic(new): " << (tSurvQuadratic - tQuadr) << endl;
	cout << "diff btw Quadratic and Quadratic(roll): " << (rollSurvQuadratic - rollQuadratic) << endl;*/
	/*for (auto t : timesArr) {
		std::cout << std::setw(fieldWidth) << t+timeDim << calcObj.m_timeNewton
	}*/
	/*std::cout << std::setw(fieldWidth) <<
	"tSurvLinear" + timeDim <<
	std::setprecision(10) << tSurvLinear << endl;
	cout << std::setw(30) << "rollSurvLinear" + rollDim <<
		rollSurvLinear << endl;
	cout << std::setw(30) << "tSurvQuadratic" + timeDim << tSurvQuadratic << endl;
	cout << std::setw(30) << "rollSurvQuadratic" + rollDim << rollSurvQuadratic << endl;
	cout << std::setw(30) << "tQuadratic" + timeDim << tQuadr << endl;
	cout << std::setw(30) << "rollQuadratic" + rollDim << rollQuadratic << endl;
	cout << std::setw(30) << "tSurvNewton" + timeDim << tSurvNewton << endl;
	cout << std::setw(30) << "rollSurvNewton" + rollDim << rollSurvNewton <<
		" \nfor " << numIter << " iterations" << endl;*/
}
