#pragma once
#include "Point.h"
//класс вектор
class Vector : public Point {
public:
    Vector(); //конструктор без параметров
    Vector(int x, int y); //конструктор с параметрами
    Vector(int x, int y, string metka); //конструктор с параметрами
    void Read(); //метод ввода
    double CalcVectLen(); //метод вычисления длины вектора
    void CalcVectLen(double* rez); //метод вычисления длины вектора с возвращением параметра через указатель
    void CalcVectLen(double& rez); //метод вычисления длины вектора с возвращением параметра по ссылке
    double CalcScalarProd(Vector v2); //метод вычисления скалярного произведения векторов
    Vector operator* (int k); //перегруженный оператор умножения вектора на число справа
    void operator= (Point p); //перегруженный оператор присваивания
    friend Vector operator* (int k, Vector v); //дружественный перегруженный оператор умножения вектора на число слева
    friend Vector operator+ (Vector v1, Vector v2); //дружественный перегруженный оператор сложения векторов
    friend ostream& operator<< (ostream& out, Vector v); //перегруженный оператор вывода
 
};

