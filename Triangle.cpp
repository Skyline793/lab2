#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle() //конструктор без параметров
{
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3): //конструктор с параметрами
    A(x1, y1), B(x2, y2), C(x3, y3) 
{
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int colorIndex): //конструктор с параметрами
    A(x1, y1), B(x2, y2), C(x3, y3)
{
    if (colorIndex < 0 || colorIndex >= Figure::N) throw invalid_argument("»ндекс цвета вне диапазона");
    this->colorIndex = colorIndex;
}


void Triangle::Read() { //метод ввода
    bool correct = 0;
    string strIndex;
    int index;
    cout << "ѕерва€ вершина треугольника:" << endl;
    A.Read();
    cout << "¬тора€ вершина треугольника:" << endl;
    B.Read();
    cout << "“реть€ вершина треугольника:" << endl;
    C.Read();
    while (!correct) {
        try
        {
            cout << "¬ыберите цвет фигуры:" << endl;
            Figure::ShowColors();
            cin >> strIndex;
            index = stoi(strIndex);
            SetColorIndex(index);
            correct = 1;
        }
        catch (invalid_argument& e) {
            cout << e.what() << " ѕовторите ввод:" << endl;
        }
        cin.ignore(1024, '\n');
    }
}

double Triangle::CalcSquare() { //метод вычислени€ площади
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    double S;
    S = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    return S;
}

void Triangle::CalcSquare(double* rez) { //метод вычислени€ площади с возвращением параметра через указатель
    if (rez == NULL) throw exception("Ќулевой указатель!");
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    *rez = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

void Triangle::CalcSquare(double& rez) { //метод вычислени€ площади с возвращением параметра по ссылке
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    rez = 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
}

double Triangle::CalcPerimeter() { //метод вычислени€ периметра
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double P = AB + AC + BC;
    return P;
}

void Triangle::CalcPerimeter(double* rez) { //метод вычислени€ периметра с возвращением параметра через указатель
    if (rez == NULL) throw exception("Ќулевой указатель!");
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    *rez = AB + AC + BC;
}

void Triangle::CalcPerimeter(double& rez) { //метод вычислени€ периметра с возвращением параметра по ссылке
    int x1 = A.GetX(), y1 = A.GetY();
    int x2 = B.GetX(), y2 = B.GetY();
    int x3 = C.GetX(), y3 = C.GetY();
    double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    rez = AB + AC + BC;
}

ostream& operator<< (ostream& out, Triangle tr) { //перегруженный оператор вывода
    out << "“реугольник с вершинами " << tr.A << ", " << tr.B << ", " << tr.C << ". ÷вет фигуры: " << Figure::colors[tr.colorIndex] << endl;
    return out;
}