#pragma once
#ifndef __COMPLEX
#define __COMPLEX
#include <math.h>
class complex {
public:
	// �Ǽ� ��� ����
	double re, im;
	// ������
	complex() { re = im = 0; }; // argument ���� ��
	complex(double x, double y) { re = x; im = y; }; //argument 2��
	complex(double theta) { re = cos(theta); im = sin(theta); }; // argument 1��

	// ��� �Լ�
	double mag();
	double phase();

	// ������ �����ε�
	complex& operator=(const complex&);
	complex& operator+=(const complex&);
	complex operator+(const complex&);
	complex operator-(const complex&);
	complex operator*(const complex&); // ��� ���ϱ�
	complex operator/(const double&);  // �Ǽ��� ������
	complex operator/(const complex&); // ����� ������
	complex operator*(const double&);  // �Ǽ� ���ϱ�

};
#endif
