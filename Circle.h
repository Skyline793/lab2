#pragma once
#include "Point.h"
//класс окружность
class Circle {
    Point Center; //центр окружности
    int R; //радиус
public:
    Circle(); //конструктор без параметров
    Circle(int x, int y, int r); //конструктор с параметрами
    void Init(int x, int y, int r); //метод инициализации
    void Display(); //метод вывода
    void Read(); //метод ввода
    void PrintEquation(); //метод вывода уравнения окружности
    double CalcSquare(); //метод вычисления площади круга
};

