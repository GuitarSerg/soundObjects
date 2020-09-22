#ifndef SURVEYSOLUTION_20200911_INTERPOLATION_H
#define SURVEYSOLUTION_20200911_INTERPOLATION_H

#include<cassert>
#include<cmath>
#include"globalConstants.h"
#include<memory>
#include"orbital.h"
#include"surveyData.h"
#include"targets.h"
#include"timePoints.h"
#include<vector>

class Interpolation
{
private:
	double m_t_1, m_t0, m_t1;
	double m_tSurv;
	double m_dt;
	//double m_rollSurv;
	Vector3 m_s_1, m_s0, m_s1;
	Vector3 m_v_1, m_v0, m_v1;
	Vector3 m_n_1, m_n0, m_n1;

public:
	Interpolation() = default; //0.0 times
	Interpolation(SurveyData &dataStorage);


	void setVectors();


	std::tuple<double, double> setCoeff_b_c(double func0, double func1);

	std::tuple<double, double, double> setCoeff_a_b_c(double func_1,
		double func0, double func1);



	double evaluateLinearTime(SurveyData &dataStorage, double tApprox,
		std::shared_ptr<Vector3> target);

	double evaluateLinearRoll(SurveyData &dataStorage, std::shared_ptr<Vector3> target);

	double evaluateQuadraticTime(SurveyData &dataStorage, double tApprox,
		std::shared_ptr<Vector3> target);

	double evaluateQuadraticRoll(SurveyData &dataStorage, std::shared_ptr<Vector3> target);


	void normalizeVectors(Vector3* vect1, Vector3* vect2, Vector3* vect3,
		Vector3* vect4);
	void normalizeVectors(Vector3* vect1, Vector3* vect2, Vector3* vect3);
	void normalizeVectors(Vector3* vect1, Vector3* vect2);
	void normalizeVectors(Vector3* vect1);

private:

};

#endif