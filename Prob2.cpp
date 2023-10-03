#include<iostream>
#include<fstream>
#include<cmath>

#define PI 3.141592
using namespace std;

int main(){
	// 텍스트 파일 생성
	ofstream t_axis_file;
	ofstream op_axis_file;
	t_axis_file.open("sine_graph_t_axis.txt");
	op_axis_file.open("sine_graph_op_axis.txt");
	// 변수 초기화
	double freq, sample_freq, t, Ts;

	// sampling frequency : ４４００
	cout << "input the sample frequency : ";
	cin >> sample_freq;
	t = 0;
	freq = 440;
	Ts = 1.0 / sample_freq; 

	// 결과 값 파일에 출력
	for (int i = 0; i < 50; i++, t = t + Ts) {
		t_axis_file << t << endl; // x축
		op_axis_file << sin(2 * PI * freq * t) << endl; // y축
	}
	cout << "결과 값을 txt파일로 저장했습니다.";
	return 0;
}