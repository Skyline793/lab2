#include "Point.h"
#include <iostream>
#define PI 3.14159265335
using std::cout;

Point::Point() { //конструктор без параметров
    X = Y = 0;
	counter++;
}

Point::Point(int x, int y) { //конструктор с параметрами
	this->X = x;
	this->Y = y;
	counter++;
}

Point::~Point()
{
	counter--;
}

void Point::Init(int x, int y) { //метод инициализации
    this->X = x;
    this->Y = y;
}

int Point::GetX() { //метод получения координаты X
    return this->X;
}

int Point::GetY() { //метод получения координаты Y
    return this->Y;
}

void Point::Display() { //Метод вывода координат
    cout << "(" << X << "," << Y << ")";
}

void Point::PolarCoords() {
	double r, f;
	r = sqrt(X * X + Y * Y);
	if (X == 0) {
		if (Y > 0)
			f = PerevodToGradus(PI / 2);
		if (Y < 0)
			f = PerevodToGradus(3 * PI / 2);
		else f = 0;
	}
	else {
		f = atan((double)Y / X);
		if (X > 0 && Y < 0)
			f += 2 * PI;
		if (X < 0)
			f += PI;
		f = PerevodToGradus(f);
	}
	printf("Полярные координаты: r=%.3lf f=%.1lf град.\n", r, f);
}

double Point::PerevodToGradus(double rad)
{
	double grad = rad * 180 / PI;
	return grad;
}

double Point::PerevodToRadian(double grad)
{
	double rad = grad * PI / 180;
	return rad;
}

int Point::GetCount()
{
	return counter;
}

Point& Point::operator++()
{
	this->X++;
	this->Y++;
	return *this;
}

Point Point::operator++(int)
{
	Point tmp = *this;
	++(*this);
	return tmp;
}