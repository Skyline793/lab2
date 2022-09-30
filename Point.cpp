#include "Point.h"
#include <iostream>
using std::cout;

Point::Point() { //конструктор без параметров
    X = Y = 0;
}

Point::Point(int x, int y) { //конструктор с параметрами
    this->X = x;
    this->Y = y;
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
