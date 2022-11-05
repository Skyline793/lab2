#pragma once
#include "Point.h"
#include "Figure.h"

//класс окружность
class Circle : public Figure {
    Point Center; //центр окружности
    double R; //радиус
public:
    Circle(); //конструктор без параметров
    Circle(int x, int y, double R); //конструктор с параметрами
    Circle(int x, int y, double R, int colorIndex); //конструктор с параметрами
    Circle(int x, int y, double R, string metka, int colorIndex); //конструктор с параметрами
    void Read(); //метод ввода
    void PrintEquation(); //метод вывода уравнения окружности
    double CalcSquare(); //метод вычисления площади круга
    void CalcSquare(double* rez); //метод вычисления площади с возвращением параметра через указатель
    void CalcSquare(double& rez); //метод вычисления площади с возвращением параметра по ссылке
    double CalcPerimeter(); //метод вычисления длины окружности
    void CalcPerimeter(double* rez); //метод вычисления длины окружности с возвращением параметра через указатель
    void CalcPerimeter(double& rez); //метод вычисления длины окружности с возвращением параметра по ссылке
    friend ostream& operator<< (ostream& out, Circle c); //перегруженный оператор вывода
};

