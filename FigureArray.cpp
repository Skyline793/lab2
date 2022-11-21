#include "FigureArray.h"

int wantedColor; //переменна€ дл€ хранени€ искомого индекса цвета
bool condByMaxSquare(Figure* f1, Figure* f2); //предикат сортировки по возрастанию площади
bool condByMinSquare(Figure* f1, Figure* f2); //предикат сортировки по убыванию площади
bool condByMaxPerimeter(Figure* f1, Figure* f2); //предикат сортировки по возрастанию периметра
bool condByMinPerimeter(Figure* f1, Figure* f2); //предикат сортировки по убыванию периметра
bool condColor(Figure* f); //предикат поиска фигур по цвету

void FigureArray::Add(Figure* f) //метод добавлени€ фигуры
{
	vect.push_back(f);
}

void FigureArray::Read() //метод добавлени€ фигуры с вводом через консоль
{
	int type;
	do
	{
		cout << "¬ыберите тип фигуры, которую хотите добавить:\n1.  руг\n2. “реугольник\n3. ѕараллелограмм" << endl;
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

void FigureArray::Display() //метод вывода объектов вектора
{
	vector<Figure*>::iterator ir;
	for (ir = vect.begin(); ir != vect.end(); ++ir) {
		(*ir)->Display();
	}
}

void FigureArray::Insert(Figure* f, int ind) //метод вставки объекта на определнное место
{
	if (ind >= vect.size()) throw new exception("»ндекс вне диапазона");
	vector<Figure*>::iterator it = vect.begin() + ind;
	vect.insert(it, f);
}

void FigureArray::Delete(int ind) //метод удалени€ объекта из вектора
{
	if (ind >= vect.size()) throw new exception("»ндекс вне диапазона");
	vector<Figure*>::iterator it = vect.begin() + ind;
	vect.erase(it);
}

void FigureArray::SortByMaxSquare() //метод сортировки по возрастанию площади фигур
{
	sort(vect.begin(), vect.end(), condByMaxSquare);
}

void FigureArray::SortByMinSquare() //метод сортировки по убыванию площади фигур
{
	sort(vect.begin(), vect.end(), condByMinSquare);
}

void FigureArray::SortByMaxPerimeter() //метод сортировки по возрастанию периметра фигур
{
	sort(vect.begin(), vect.end(), condByMaxPerimeter);
}

void FigureArray::SortByMinPerimeter() //метод сортировки по убыванию периметра фигур
{
	sort(vect.begin(), vect.end(), condByMinPerimeter);
}

void FigureArray::DisplayColorFigures(int colorIndex) //метод поиска фигур определенного цвета
{
	bool found = 0;
	wantedColor = colorIndex;
	cout << "‘игуры выбранного цвета:" << endl;
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
	if (!found) cout << "Ќе найдены" << endl;
}

FigureArray FigureArray::GetColorFigures(int colorIndex) //метод поиска фигур определенного цвета
{
	FigureArray colorArr;
	wantedColor = colorIndex;
	vector<Figure*>::iterator it = vect.begin(), ir;
	while (it != vect.end()) {
		ir = find_if(it, vect.end(), condColor);
		if (ir != vect.end()) {
			colorArr.Add((*ir));
			it = ++ir;
		}
		else break;
	}
	return colorArr;
}

bool condByMaxSquare(Figure* f1, Figure* f2) //предикат сортировки по возрастанию площади
{
	return f1->CalcSquare() < f2->CalcSquare();
}

bool condByMinSquare(Figure* f1, Figure* f2) //предикат сортировки по убыванию площади
{
	return f1->CalcSquare() > f2->CalcSquare();
}

bool condByMaxPerimeter(Figure* f1, Figure* f2) //предикат сортировки по возрастанию периметра
{
	return f1->CalcPerimeter() < f2->CalcPerimeter();
}

bool condByMinPerimeter(Figure* f1, Figure* f2) //предикат сортировки по убыванию периметра
{
	return f1->CalcPerimeter() > f2->CalcPerimeter();
}

bool condColor(Figure* f) //предикат поиска по цвету
{
	return f->GetColorIndex() == wantedColor;
}

