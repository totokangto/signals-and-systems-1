#include<iostream>
#include<cmath>
#include"complex.h"
#include<stdlib.h>

using namespace std;

int main() {
	
	// Problem 1 : Complex Numbers
	
	// 汗家荐 积己
	complex com_num_1(3, 5); // 3 + 5j
	complex com_num_2(4, 2); // 4 + 2j

	// 汗家荐 怠祭
	complex sum_of_com = com_num_1 + com_num_2; // (3 + 5j) + (4 + 2j) = 7 + 7j

	cout << "Verify the result value : ";
	cout << sum_of_com.re_num << "+" << sum_of_com.im_num << "j" << endl;
	cout << "Magnitude : ";
	cout << sum_of_com.get_mag() << endl;
	cout << "Phase : ";
	cout << sum_of_com.get_phase() << endl;
	system("pause");
	return 0;
}