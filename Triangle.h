#pragma once
#include "Point.h"

//класс треугольник
class Triangle { 
    Point A, B, C; //вершины треугольника
public:
    Triangle(); //конструктор без параметров
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3); //конструктор с параметрами 
    void Read(); //метод ввода
    double CalcSquare(); //метод вычисления площади
    void CalcSquare(double* rez); //метод вычисления площади с возвращением параметра через указатель
    void CalcSquare(double& rez); //метод вычисления площади с возвращением параметра по ссылке
    double CalcPerimeter(); //метод вычисления периметра
    void CalcPerimeter(double* rez); //метод вычисления периметра с возвращением параметра через указатель
    void CalcPerimeter(double& rez); //метод вычисления периметра с возвращением параметра по ссылке
    friend ostream& operator<< (ostream& out, Triangle tr); //перегруженный оператор вывода
};

