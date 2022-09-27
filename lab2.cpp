// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <cmath>
#include "Point.h"
#include "Vector.h"
#include "Circle.h"
#include "Triangle.h"
#include "Parallelogram.h"

using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    cout << "Тест класса вектор:" << endl;
    Vector* V1 = new Vector; //динамический объект
    Vector* V2 = new Vector(4, -3); //динамический объект
    cout << "\nКонструктор без параметров и с параметрами:" << endl;
    V1->Display();
    V2->Display();
    cout << "\nВвод вектора V1 c клавиатуры:" << endl;
    V1->Read();
    V1->Display(); 
    cout << "\nВвод вектора V2 c клавиатуры:" << endl;
    V2->Read();
    V2->Display();
    cout << "\nТест методов:" << endl;
    cout << "Модуль вектора |V1|= " << V1->CalcVectLen() << endl;
    cout << "Модуль вектора |V2|= " << V2->CalcVectLen() << endl;
    cout << "Скалярное произведение (V1, V2)=" << V1->CalcScalarProd(V2) << endl;
    delete V1, V2;

    cout << "\n\nТест класса окружность:" << endl;
    Circle* circles = new Circle[5]; //динамический массив
    cout << "\nИнициализация динамического массива окружностей:" << endl;
    for (int i = 0; i < 5; i++) {
        circles[i].Init(i * 2, i - 3, i * i+1);
        circles[i].Display();
    }
    cout << "\nВвод данных динамического массива окружностей:" << endl;
    for (int i = 0; i < 5; i++) {
        circles[i].Read();
    }
    cout << "\nУравнения окружностей динамического массива:" << endl;
    for (int i = 0; i < 5; i++) {
        circles[i].PrintEquation();
    }
    cout << "\nПлощади окружностей динамического массива:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Площадь круга " << i+1 << " S=" << circles[i].CalcSquare() << endl;
    }
    delete[] circles;


    cout << "\n\nТест класса треугольник:" << endl;
    Triangle tr(0, 2, 3, -1, -3, 1); //статический объект
    cout << "\nКонструктор с параметрами:" << endl;
    tr.Display();
    cout << "\nВвод координат вершин треугольника:" << endl;
    tr.Read();
    tr.Display();
    cout << "\nТест методов:" << endl;
    cout << "Площадь треугольника S=" << tr.CalcSquare() << endl;;
    cout << "Периметр треугольника P=" << tr.CalcPerimeter() << endl;


    cout << "\n\nТест класса параллелограмм:" << endl;
    //массив динамических объектов
    Parallelogram* prgrams[3]; 
    for (int i = 0; i < 3; i++)
        prgrams[i] = new Parallelogram;
    cout << "\nВвод координат векторов, на которых построен параллелограмм:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "параллелограмм " << i+1 << ":" << endl;
        (*prgrams[i]).Read();
    }
    cout << "\nВывод параллелограммов массива:" << endl;
    for (int i = 0; i < 3; i++)
        (*prgrams[i]).Display();
    cout << "\nПлощади параллелограммов массива:" << endl;
    for (int i = 0; i < 3; i++)
        cout << "Площадь параллелограмма " << i + 1 << " S=" << (*prgrams[i]).CalcSquare() << endl;;
    for (int i = 0; i < 3; i++)
        delete prgrams[i];

    cin.get(); cin.get();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
