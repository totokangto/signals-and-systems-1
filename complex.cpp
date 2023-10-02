#include <iostream>
#include <math.h>
#include "complex.h"
#define PI 3.141592

using namespace std;

double complex::mag() {
	return sqrt(re*re + im*im); // 크기 구해서 반환
}
double complex::phase() {
	// 복소수 --> 페이저 변환
	if (re == 0.0) {
		if (im >= 0.0) return PI / 2.0; // 90도
		else return -PI / 2.0; // -90도
	}
	else return atan(im / re);
}
complex complex::operator/(const complex& y) {

	complex c;
	c = complex(y.re, -y.im); // 복소수 y의 켤레복소수
	if (re == 0.0 && im == 0.0) { cout << " complex: divided by 0\n"; return c; } // 예외처리
	c = (*this + c) / (y.re * y.re + y.im * y.im);
	return c;
}
complex& complex::operator=(const complex& x) {
	re = x.re;
	im = x.im;
	return *this;
}
complex& complex::operator+=(const complex& y) {
	re += y.re;
	im += y.im;
	return *this;
}
complex complex::operator+(const complex& y) {
	complex c;
	c.re = re + y.re;
	c.im = im + y.im;
	return c;
}
complex complex::operator-(const complex& y) {
	complex c;
	c.re = re - y.re;
	c.im = im - y.im;
	return c;
}
complex complex::operator*(const complex& y) {
	complex c;
	c.re = re*y.re - im*y.im;
	c.im = re*y.im + im*y.re;
	return c;
}
complex complex::operator/(const double& y) {
	complex c;
	c.re = re / y;
	c.im = im / y;
	return c;
}
complex complex::operator*(const double& y) {
	complex c;
	c.re = re*y;
	c.im = im*y;
	return c;
}