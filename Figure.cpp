#include "Figure.h"
const string Figure::colors[5] = {"не задан", "красный", "синий", "зеленый", "желтый"};

Figure::Figure()
{
	colorIndex = 0;
}

void Figure::SetColorIndex(int colorIndex)
{
	if (colorIndex < 0 || colorIndex >= colors->length())
		throw exception("Выбранный индекс цвета вне диапазона");
	this->colorIndex = colorIndex;
}