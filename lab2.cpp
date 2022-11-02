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
#define PI 3.14159265335

using namespace std;



int main()
{
	
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    const int N = 2;
    Point pts[N];
    cout << "Ввод массива точек" << endl;
    for (int i = 0; i < N; i++) {
        pts[i].Read();
    }
    cout << "Вывод массива точек" << endl;
    for (int i = 0; i < N; i++) {
        pts[i].Display();
        cout << endl;
    }
    cout << "Запись координат точек массива в полярной системе" << endl;
    for (int i = 0; i < N; i++) {
        pts[i].PolarCoords();
    }

    Circle** cs = new Circle*[N];
    for (int i = 0; i < N; i++)
        cs[i] = new Circle[2];
    cout << "Ввод элементов двумерного массива кругов" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cs[i][j].Read();
    }
    cout << "Вывод элементов двумерного массива кругов" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cs[i][j].Display();
    }
    cout << "Вычисление площадей элементов двумерного массива кругов" << endl;
    double* ptr = NULL;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            try {
                cs[i][j].CalcSquare(ptr);
                cout << *ptr << endl;
            }
            catch (const char* msg) {
                cout << "Вызвано исключение " << msg << endl;
            }
        }
    }
    for (int i = 0; i < N; i++)
        delete[] cs[i];
    delete[] cs;
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
