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
	//тест статических методов
	cout << "тест статических методов" << endl;
	double grad = 90, rad = 2 * PI / 3;
	printf("1) Градусы: %.2f радианы: %.2f\n2) Радианы: %.2f градусы: %.2f\n", grad, Angle::PerevodToRadian(grad), rad, Angle::PerevodToGradus(rad));

	//тест возвращения параметров через указатель и ссылку
	cout << "\nтест возвращения параметров через указатель и ссылку" << endl;
	Vector v; 
	Triangle tr;
	double rez1, rez2;
	v.Read();
	v.Display();
	v.CalcVectLen(&rez1);
	v.CalcVectLen(rez2);
	cout << "Длина вектора через указатель |v|=" << rez1 << endl << "Длина вектора по ссылке |v|=" << rez2 << endl;
	tr.Read();
	tr.Display();
	tr.CalcPerimeter(&rez1);
	tr.CalcSquare(rez2);
	cout << "Периметр треугольника через указатель P=" << rez1 << endl << "Площадь треугольника по ссылке S=" << rez2 << endl;
	
	//тест дружественных функций и перегрузки операторов
	cout << "\nтест дружественных функций и перегрузки операторов" << endl;
	Vector v1, v2, v3;
	v1.Read();
	v1.Display();
	v2.Read();
	v2.Display();
	v3 = v1 + v2;
	cout << "Сумма векторов v1+v2" << endl;
	v3.Display();
	v3 = v1 * 3;
	cout << "Умножение вектора v1 на число 3 справа" << endl;
	v3.Display();
	v3 = 2 * v2;
	cout << "Умножение вектора v2 на число 2 слева" << endl;
	v3.Display();
	
	cout << endl;
	Point p1, p2, p3;
	p1.Read();
	p1.Display();
	cout << endl;
	p2.Read();
	p2.Display();
	cout << endl;
	cout << "Префиксный инкремент точки p1" << endl;
	p3 = ++p1;
	p1.Display();
	cout << endl;
	p3.Display();
	cout << endl;
	cout << "Постфиксный инкремент точки p2" << endl;
	p3 = p2++;
	p2.Display();
	cout << endl;
	p3.Display();
	cout << endl;
	
	//тест работы со строками
	cout << "\nтест работы со строками" << endl;
	Point a(1, 2, "A"), b;
	a.Display();
	cout << endl;
	b.Display();
	cout << endl;
	b.Read();
	b.Display();
	cout << endl;

	//тест cтатического поля счетчика
	cout << "\nтест статического поля счетчика" << endl;
	cout << "Общее количество точек: " << Point::GetCount() << endl;
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
