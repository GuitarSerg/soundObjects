#include "stdafx.h"

#include<cmath>
#include<iostream>
#include"globalConstants.h"

namespace phys {
	//---- Earth properties ----
	extern const double wE{ 2 * PI / phys::TEarthDay }; // angular velocity of the Earth: 1/sec
	//---- Sattelite properties ----
	extern const double wS{ sqrt(phys::G*phys::mEarth / pow(phys::rOrb, 3)) }; // angular velocity of the sat: 1/sec
}