#ifndef SURVEYSOLUTION_20200812_GLOBALCONSTANTS_H
#define SURVEYSOLUTION_20200812_GLOBALCONSTANTS_H

#define PI 3.14159265358979323846

//namespace math {
//	constexpr double PI{ 3.141592653589793 };
//}

namespace phys {
	//---- Earth properties ----
	constexpr double mEarth{ 6.0e24 }; //mass of the Earth: kg
	constexpr double TEarthDay{ 24.0 * 3600.0 }; //sec
	constexpr double rEarth{ 6.4e6 }; //radii of the Earth: met
	constexpr double G{ 6.67e-11 }; //gravitational constant: met^3 / kg / sec^2
	extern const double wE; // angular velocity of the Earth: 1/sec
	//---- orbit properties (radii and inclination) ----
	constexpr double rOrb{ 6661442.58526079 }; //radii of the 90 min Orbit: met
	constexpr double incl{ 30.0 * PI / 180.0 }; // inclination in radians
	//---- being under survey object ----
	constexpr double lam{ 0.0 };
	constexpr double phi{ 30.0 * PI / 180.0 };
	//---- sattelite properties ----
	extern const double wS; // angular velocity of the sat: 1/sec
	
}

namespace input {
	//---- timeSurvey (tA, tB) ----
	constexpr double tA{ 240.0 };
	constexpr double tB{ 270.0 };
	//---- orbit properties (radii and inclination) ---- (should be taken for "Kanopus" SC)
	constexpr double rOrb{ 6661442.58526079 }; //radii of the 90 min Orbit: met
	constexpr double incl{ 30.0 * PI / 180.0 }; // inclination in radians
	//---- being under survey object ----
	constexpr double lam{ 0.0 };
	constexpr double phi{ 30.0 * PI / 180.0 };
}

#endif
