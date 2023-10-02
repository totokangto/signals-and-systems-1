#include<iostream>
#include<fstream>
#include<cmath>

#define PI 3.141592
using namespace std;

int main(){
	// �ؽ�Ʈ ���� ����
	ofstream out_file1;
	ofstream out_file2;
	out_file1.open("sine_graph_time.txt");
	out_file2.open("sine_graph_output.txt");
	// ���� �ʱ�ȭ
	double fre, sample_fre, t, dt;

	// sampling frequency : 8000
	cout << "input the sample frequency : ";
	cin >> sample_fre;
	t = 0;
	fre = 440;
	dt = 1.0 / sample_fre; 

	// ��� �� ���Ͽ� ���
	for (int i = 0; i < 50; i++, t = t + dt) {
		out_file1 << t << endl; // x��
		out_file2 << sin(2 * PI * fre * t) << endl; // y��
	}
	return 0;
}