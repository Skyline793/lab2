#pragma once
#include "Point.h"
//класс окружность
class Circle {
    Point Center; //центр окружности
    double R; //радиус
public:
    Circle(); //конструктор без параметров
    Circle(int x, int y, double R); //конструктор с параметрами
    Circle(int x, int y, double R, string metka); //конструктор с параметрами
    void Init(int x, int y, double R); //метод инициализации
    void Display(); //метод вывода
    void Read(); //метод ввода
    void PrintEquation(); //метод вывода уравнения окружности
    double CalcSquare(); //метод вычисления площади круга
    void CalcSquare(double* rez); //метод вычисления площади с возвращением параметра через указатель
    void CalcSquare(double& rez); //метод вычисления площади с возвращением параметра по ссылке
};

