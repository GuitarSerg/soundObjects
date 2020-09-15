#ifndef SURVEYSOLUTION_20200813_VECTOR3_H
#define SURVEYSOLUTION_20200813_VECTOR3_H

constexpr double EPSILON{ 0.001f };

class Vector3
{
public:

	union
	{
		struct
		{
			 double x, y, z;
		};
		double v[3];
	};

	Vector3() : x(0), y(0), z(0) {}
	Vector3(Vector3& v) : x(v.x), y(v.y), z(v.z) {}
	Vector3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

	// assignment of one vect to another
	Vector3& operator= (Vector3& v);

	// comparison of one vect and another (true - the same; false - not the same)
	bool operator== (Vector3& v);

	// отрицательный вектор (унарная операция!!!)
	Vector3 operator- ()
	{
		return Vector3(-x, -y, -z);
	}

	// сложение векторов
	Vector3 operator+ (Vector3& v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	// разность векторов
	Vector3 operator- (Vector3& v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	// умножение вектора на скаляр
	Vector3 operator* (double& a)
	{
		return Vector3(x*a, y*a, z*a);
	}

	// деление вектора на скаляр
	Vector3 operator/ (double& a)
	{
		double b = 1.0f / a;
		return Vector3(x*b, y*b, z*b);
	}

	// скалярное произедение векторов (dot product)
	double operator* (Vector3& v)
	{
		return x*v.x + y*v.y + z*v.z;
	}

	// векторное произведение векторов (cross product)
	Vector3 cross(Vector3& v)
	{
		return Vector3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
	}

	Vector3& operator+= (Vector3& v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}

	Vector3& operator-= (Vector3& v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}

	Vector3& operator*= (double& a)
	{
		x *= a; y *= a; z *= a;
		return *this;
	}

	Vector3& operator/= (double& a)
	{
		double b = 1.0f / a;
		x *= b; y *= b; z *= b;
		return *this;
	}

	// magnitude of vector (it's absolute length)
	double magnitude();

	// normalization
	void normalize();
	
	// расстояние между двумя точками (не векторами!!!)
	double distance(Vector3& v);

	//projection on plane
	void projectOnPlane(/*Vector3& v,*/ Vector3& vNorm2Plane); //to project we need to know norm vector

	//print vector coordinates
	void printVector();
};

void printVector(const Vector3 &vector);

#endif