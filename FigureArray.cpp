#include "FigureArray.h"

int wantedColor;
bool condByMaxSquare(Figure* f1, Figure* f2);
bool condByMinSquare(Figure* f1, Figure* f2);
bool condByMaxPerimeter(Figure* f1, Figure* f2);
bool condByMinPerimeter(Figure* f1, Figure* f2);
bool condColor(Figure* f);

void FigureArray::Add(Figure* f)
{
	vect.push_back(f);
}

void FigureArray::Read()
{
	int type;
	do
	{
		cout << "Выберите тип фигуры, которую хотите добавить:\n1. Круг\n2. Треугольник\n3. Параллелограмм" << endl;
		cin >> type;
	} while (type <= 0 || type > 3);
	switch (type)
	{
	case 1:
	{
		Circle* c = new Circle();
		c->Read();
		vect.push_back(c);
		break;
	}
	case 2:
	{
		Triangle* tr = new Triangle();
		tr->Read();
		vect.push_back(tr);
		break;
	}
	case 3:
	{
		Parallelogram* pr = new Parallelogram();
		pr->Read();
		vect.push_back(pr);
		break;
	}
	}
}

void FigureArray::Display()
{
	vector<Figure*>::iterator ir;
	for (ir = vect.begin(); ir != vect.end(); ++ir) {
		(*ir)->Display();
		cout << (*ir)->CalcSquare() << endl << (*ir)->CalcPerimeter() << endl;
	}
}

void FigureArray::Insert(Figure* f, int ind)
{
	if (ind >= vect.size()) throw new exception("Индекс вне диапазона");
	vector<Figure*>::iterator it = vect.begin() + ind;
	vect.insert(it, f);
}

void FigureArray::Delete(int ind)
{
	if (ind >= vect.size()) throw new exception("Индекс вне диапазона");
	vector<Figure*>::iterator it = vect.begin() + ind;
	vect.erase(it);
}

void FigureArray::SortByMaxSquare()
{
	sort(vect.begin(), vect.end(), condByMaxSquare);
}

void FigureArray::SortByMinSquare()
{
	sort(vect.begin(), vect.end(), condByMinSquare);
}

void FigureArray::SortByMaxPerimeter()
{
	sort(vect.begin(), vect.end(), condByMaxPerimeter);
}

void FigureArray::SortByMinPerimeter()
{
	sort(vect.begin(), vect.end(), condByMinPerimeter);
}

void FigureArray::FindColor(int colorIndex)
{
	bool found = 0;
	wantedColor = colorIndex;
	cout << "Фигуры выбранного цвета:" << endl;
	vector<Figure*>::iterator it = vect.begin(), ir;
	while (it != vect.end()) {
		ir = find_if(it, vect.end(), condColor);
		if (ir != vect.end()) {
			found = 1;
			(*ir)->Display();
			it = ++ir;
		}
		else break;
	}
	if (!found) cout << "Не найдены" << endl;
}

bool condByMaxSquare(Figure* f1, Figure* f2)
{
	return f1->CalcSquare() < f2->CalcSquare();
}

bool condByMinSquare(Figure* f1, Figure* f2)
{
	return f1->CalcSquare() > f2->CalcSquare();
}

bool condByMaxPerimeter(Figure* f1, Figure* f2)
{
	return f1->CalcPerimeter() < f2->CalcPerimeter();
}

bool condByMinPerimeter(Figure* f1, Figure* f2)
{
	return f1->CalcPerimeter() > f2->CalcPerimeter();
}

bool condColor(Figure* f)
{
	return f->GetColorIndex() == wantedColor;
}

