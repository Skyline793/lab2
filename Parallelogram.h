#pragma once
#include "Vector.h"

//класс параллелограмм
class Parallelogram {
    Vector a, b; //вектора, на которых построен параллелограмм
public:
    Parallelogram(); //конструктор без параметров
    Parallelogram(int x1, int y1, int x2, int y2); //конструктор с параметрами
    void Init(int x1, int y1, int x2, int y2); //метод инициализации
    void Read(); //метод ввода
    void Display(); //метод вывода
    double CalcSquare(); //метод вычисления площади 
    void CalcSquare(double* rez); //метод вычисления площади с возвращением параметра через указатель
    void CalcSquare(double& rez); //метод вычисления площади с возвращением параметра по ссылке
};

