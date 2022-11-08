#include "Parallelogram.h"
#include <iostream>
using namespace std;

Parallelogram::Parallelogram() //конструктор без параметров
{
}

Parallelogram::Parallelogram(int x1, int y1, int x2, int y2): //конструктор с параметрами
    a(x1, y1), b(x2, y2)
{
}

Parallelogram::Parallelogram(int x1, int y1, int x2, int y2, int colorIndex): //конструктор с параметрами
    a(x1, y1), b(x2, y2)
{
    this->colorIndex = colorIndex;
}

void Parallelogram::Read() { //метод ввода
    bool correct = 0;
    string strIndex;
    int index;
    cout << "ѕервый из векторов, на которых построен параллелограмм:" << endl;
    a.Read();
    cout << "¬торой из векторов, на которых построен параллелограмм: " << endl;
    b.Read();
    while (!correct) {
        try
        {
            cout << "¬ыберите цвет фигуры:\n0 - без цвета\n1 - красный\n2 - синий\n3 - зеленый\n4 - желтый" << endl;
            cin >> strIndex;
            index = stoi(strIndex);
            if (index < 0 || index >= Figure::colors->length()) throw 0;
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << "Ќекорректное значение. ѕовторите ввод:" << endl;
        }
        catch (int)
        {
            cout << "¬ведите число от 0 до 4!. ѕовторите ввод:" << endl;
        }
        cin.ignore(1024, '\n');
    }
    colorIndex = index;
}

double Parallelogram::CalcSquare() { //метод вычислени€ площади
    double S, len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    if (len_a * len_b == 0)
        return 0;
    prod = a.CalcScalarProd(b);
    cosinus = prod / (len_a * len_b);
    sinus = sqrt(1 - cosinus * cosinus);
    S = len_a * len_b * sinus;
    return S;
}

void Parallelogram::CalcSquare(double* rez) { //метод вычислени€ площади с возвращением параметра через указатель
    if (rez == NULL) throw exception("Ќулевой указатель!");
    double len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    try {
        if (len_a * len_b == 0) throw 0;
        cosinus = prod / (len_a * len_b);
    }
    catch (int) {
        cosinus = 0;
    }
    sinus = sqrt(1 - cosinus * cosinus);
    *rez = len_a * len_b * sinus;
}

void Parallelogram::CalcSquare(double& rez) { //метод вычислени€ площади с возвращением параметра по ссылке
    double len_a, len_b, prod, cosinus, sinus;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    prod = a.CalcScalarProd(b);
    try {
        if (len_a * len_b == 0) throw 0;
        cosinus = prod / (len_a * len_b);
    }
    catch (int) {
        cosinus = 0;
    }
    sinus = sqrt(1 - cosinus * cosinus);
    rez = len_a * len_b * sinus;
}

double Parallelogram::CalcPerimeter() //метод вычислени€ периметра
{
    double len_a, len_b, P;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    P = 2 * (len_a + len_b);
    return P;
}
void Parallelogram::CalcPerimeter(double* rez) //метод вычислени€ периметра с возвращением параметра через указатель
{
    if (rez == NULL) throw exception("Ќулевой указатель!");
    double len_a, len_b;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    *rez = 2 * (len_a + len_b);
}
void Parallelogram::CalcPerimeter(double& rez) //метод вычислени€ периметра с возвращением параметра по ссылке
{
    double len_a, len_b;
    len_a = a.CalcVectLen();
    len_b = b.CalcVectLen();
    rez = 2 * (len_a + len_b);
}

ostream& operator<< (ostream& out, Parallelogram pr) { //перегруженный оператор вывода
    if (pr.colorIndex < 0 || pr.colorIndex >= Figure::colors->length()) throw exception("¬ыбранный индекс цвета вне диапазона!");
    out << "ѕараллелограмм, построенный на векторах:" << endl << pr.a << pr.b << "÷вет фигуры: " << Figure::colors[pr.colorIndex] << endl;
    return out;
}