#pragma once
#include "Point.h"
//класс вектор
class Vector {
    Point coord; //координаты вектор
public:
    Vector(); //конструктор без параметров
    Vector(int x, int y); //конструктор с параметрами
    void Init(int x, int y); //метод инициализации
    void Display(); //метод вывода 
    void Read(); //метод ввода
    double CalcVectLen(); //метод вычисления длины вектора
    void CalcVectLen(double* rez);
    void CalcVectLen(double& rez);
    double CalcScalarProd(Vector v2); //метод вычисления скалярного произведения векторов
    Vector operator* (int k);
    friend Vector operator* (int k, Vector v);
    friend Vector operator+ (Vector v1, Vector v2);
 
};

