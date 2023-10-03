#include<iostream>
#include<fstream>
#include<cmath>

#define PI 3.141592
using namespace std;

int main(){
	// �ؽ�Ʈ ���� ����
	ofstream t_axis_file;
	ofstream op_axis_file;
	t_axis_file.open("sine_graph_t_axis.txt");
	op_axis_file.open("sine_graph_op_axis.txt");
	// ���� �ʱ�ȭ
	double freq, sample_freq, t, Ts;

	// sampling frequency : ��������
	cout << "input the sample frequency : ";
	cin >> sample_freq;
	t = 0;
	freq = 440;
	Ts = 1.0 / sample_freq; 

	// ��� �� ���Ͽ� ���
	for (int i = 0; i < 50; i++, t = t + Ts) {
		t_axis_file << t << endl; // x��
		op_axis_file << sin(2 * PI * freq * t) << endl; // y��
	}
	cout << "��� ���� txt���Ϸ� �����߽��ϴ�.";
	return 0;
}