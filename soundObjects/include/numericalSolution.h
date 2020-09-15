#ifndef SURVEYSOLUTION_20200826_NUMERICALSOLUTION_H
#define SURVEYSOLUTION_20200826_NUMERICALSOLUTION_H

#include<functional>

double timeSurvNewton(double eps, double tInit, int* numIter);

void launchDerivativeVerify(double point, double delta,
							double acc, double& diffSchemeDeriv,
							double& analyticalDeriv);

#endif