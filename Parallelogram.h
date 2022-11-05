#pragma once
#include "Vector.h"
#include "Figure.h"

//класс параллелограмм
class Parallelogram : public Figure {
    Vector a, b; //вектора, на которых построен параллелограмм
public:
    Parallelogram(); //конструктор без параметров
    Parallelogram(int x1, int y1, int x2, int y2); //конструктор с параметрами
    Parallelogram(int x1, int y1, int x2, int y2, int colorIndex); //конструктор с параметрами
    void Read(); //метод ввода
    double CalcSquare(); //метод вычисления площади 
    void CalcSquare(double* rez); //метод вычисления площади с возвращением параметра через указатель
    void CalcSquare(double& rez); //метод вычисления площади с возвращением параметра по ссылке
    double CalcPerimeter(); //метод вычисления периметра
    void CalcPerimeter(double* rez); //метод вычисления периметра с возвращением параметра через указатель
    void CalcPerimeter(double& rez); //метод вычисления периметра с возвращением параметра по ссылке
    friend ostream& operator<< (ostream& out, Parallelogram pr); //перегруженный оператор вывода
};

