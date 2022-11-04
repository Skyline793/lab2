#include "Point.h"
#include <iostream>
#define PI 3.14159265335
using namespace std;

int Point::counter = 0; //инициализация счетчика точек

Point::Point() { //конструктор без параметров
    X = Y = 0;
	counter++;
}

Point::Point(int X, int Y) { //конструктор с параметрами
	this->X = X;
	this->Y = Y;
	counter++;
}

Point::Point(int X, int Y, string metka) { //конструктор с параметрами
	this->X = X;
	this->Y = Y;
	this->metka = metka;
	counter++;
}

Point::~Point() { //деструктор
	counter--;
}

void Point::SetX(int X) { //метод установки значения X
	this->X = X;
}

void Point::SetY(int Y) { //метод установки значения Y
	this->Y = Y;
}

void Point::SetMetka(string metka) { //метод установки значения идентификатора
	this->metka = metka;
}

void Point::Read() { //метод ввода
	bool correct = 0;
	int x, y;
	string strX, strY;
	string metka;
	while (!correct) {
		try {
			cout << "Введите координаты точки (x, y): ";
			cin >> strX >> strY;
			x = stoi(strX);
			y = stoi(strY);
			correct = 1;
		}
		catch (invalid_argument& e) {
			cout << "Некорректное значение! Повторите ввод:" << endl;
		}
		cin.ignore(1024, '\n');
	}
	cout << "Введите идентификатор точки (Enter, чтобы не создавать идентификатор): ";
	getline(cin, metka);
	*this = Point(x, y, metka);
}

int Point::GetX() { //метод получения координаты X
    return X;
}

int Point::GetY() { //метод получения координаты Y
    return Y;
}

string Point::GetMetka() { //метод получения идентификатора
	return metka;
}

void Point::Display() { //Метод вывода координат
	cout << metka << "(" << X << "," << Y << ")";
}

void Point::PolarCoords() { //метод перевода в полярные координаты
	double r, f;
	r = sqrt(X * X + Y * Y);
	try {
		if (X == 0) throw 0;
		f = atan(Y / X);
		if (X > 0 && Y < 0)
			f += 2 * PI;
		if (X < 0)
			f += PI;
		f = Angle::PerevodToGradus(f);
	}
	catch (int) {
		if (Y > 0)
			f = Angle::PerevodToGradus(PI / 2);
		if (Y < 0)
			f = Angle::PerevodToGradus(3 * PI / 2);
		if (Y == 0)
			f = 0;
	}
	printf("Полярные координаты: r=%.3lf f=%.1lf град.\n", r, f);
}

int Point::GetCount() //статический метод получения счетчика
{
	return counter;
}

Point& Point::operator++() //перегруженный оператор префиксного инкремента
{
	this->X++;
	this->Y++;
	return *this;
}

Point Point::operator++(int) //перегруженный оператор постфиксного инкремента
{
	Point tmp = *this;
	++(*this);
	return tmp;
}