#pragma once
#include <string>
using std::string;

class Figure {
protected:
	static const string colors[5];
	int colorIndex;
public:
	Figure() {
		colorIndex = 0;
	}
	virtual double CalcSquare() = 0;
	virtual double CalcPerimeter() = 0;
};
