#pragma once
#include "Point.h"
//класс вектор
class Vector {
    Point coord; //координаты вектора
public:
    Vector(); //конструктор без параметров
    Vector(int x, int y); //конструктор с параметрами
    void Init(int x, int y); //метод инициализации
    void Display(); //метод вывода 
    void Read(); //метод ввода
    double CalcVectLen(); //метод вычисления длины вектора
    void CalcVectLen(double* rez); //метод вычисления длины вектора с возвращением параметра через указатель
    void CalcVectLen(double& rez); //метод вычисления длины вектора с возвращением параметра по ссылке
    double CalcScalarProd(Vector v2); //метод вычисления скалярного произведения векторов
    Vector operator* (int k); //перегруженный оператор умножения вектора на число справа
    friend Vector operator* (int k, Vector v); //дружественный перегруженный оператор умножения вектора на число слева
    friend Vector operator+ (Vector v1, Vector v2); //дружественный перегруженный оператор сложения векторов
 
};

