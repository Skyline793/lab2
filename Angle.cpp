#include "Angle.h"

double Angle::PerevodToGradus(double rad) //статический метод перевода радиан в градусы
{
	double grad = rad * 180 / PI;
	return grad;
}

double Angle::PerevodToRadian(double grad) //статический метод перевода градусов в радианы
{
	double rad = grad * PI / 180;
	return rad;
}
