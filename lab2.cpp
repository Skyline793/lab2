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
#include "Figure.h"
#include "Comparison.h"
#define PI 3.14159265335

using namespace std;



int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //тест оператора присваивания
    cout << "тест оператора присваивания" << endl;
    Point tchk(4, 1, "C");
    Vector vect;
    cout << tchk << endl << vect << endl;
    vect = tchk;
    cout << tchk << endl << vect << endl;
    //тест работы вируальной функции
    cout << "\nтест работы вируальной функции" << endl;
    Point* p = new Point(1, 3, "A");
    Vector* v = new Vector(2, -4);
    cout << *p << endl << *v;
    p = v;
    cout << *p << endl << *v;
    p->Read();
    cout << *p << endl << *v;
    //тест шаблона класса
    cout << "\nтест шаблона класса" << endl;
    Parallelogram pr1(4, 1, -2, 3), pr2(1, -4, 4, 7);
    Circle c1(3, 4, 4.3), c2(-2, 3, 3.6);
    cout << pr1 << pr2;
    cout << "Большая площадь: " << Comparison<Parallelogram>::CompareSquare(pr1, pr2) << endl;
    cout << c1 << c2;
    cout << "Больший периметр: " << Comparison<Circle>::ComparePerimeter(c1, c2);
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
