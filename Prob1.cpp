#include<iostream>
#include<cmath>
#include"complex.h"

#define PI 3.141592
using namespace std;

int main() {
	
	// Problem 1 : Complex Numbers

	// 汗家荐 积己
	complex com1(1, 2); // 1 + 2j
	complex com2(2, 3); // 2 + 3j

	// 汗家荐 怠祭
	complex sum = com1 + com2; // (1 + 2j) + (2 + 3j) = 3 + 5j

	cout << "Verify the result value : ";
	cout << sum.re << "+" << sum.im << "j" << endl;
	cout << "Magnitude : ";
	cout << sum.mag() << endl;
	cout << "Phase : ";
	cout << sum.phase() << endl;
	return 0;
}