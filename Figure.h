#pragma once
#include <string>
#include <iostream>
using namespace std;

class Figure { //����������� ����� ������
protected:
	static const string colors[]; //������ ������ ������
	int colorIndex; //������ ������� ������ 
public:
	Figure(); //����������� 
	void SetColorIndex(int colorIndex); //����� ��������� ������� �����
	virtual double CalcSquare() = 0; //����� ����������� ����� ���������� �������
	virtual double CalcPerimeter() = 0; //����� ����������� ����� ���������� ���������
};

