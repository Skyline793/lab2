#pragma once
#include <string>
#include <iostream>
using namespace std;

class Figure { //����������� ����� ������
protected:
	static const int N; //����� ������
	int colorIndex; //������ ������� ������ 
public:
	static const string colors[]; //������ ������ ������
	Figure(); //����������� 
	void SetColorIndex(int colorIndex); //����� ��������� ������� �����
	int GetColorIndex();
	static void ShowColors(); //����������� ����� ������ ������ ������
	virtual void Display() = 0;
	virtual double CalcSquare() = 0; //����� ����������� ����� ���������� �������
	virtual double CalcPerimeter() = 0; //����� ����������� ����� ���������� ���������
};

