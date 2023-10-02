#include<iostream>
#include<fstream>
#include<cmath>

#define PI 3.141592
using namespace std;

int main(){
	// 텍스트 파일 생성
	ofstream out_file1;
	ofstream out_file2;
	out_file1.open("sine_graph_time.txt");
	out_file2.open("sine_graph_output.txt");
	// 변수 초기화
	double fre, sample_fre, t, dt;

	// sampling frequency : 8000
	cout << "input the sample frequency : ";
	cin >> sample_fre;
	t = 0;
	fre = 440;
	dt = 1.0 / sample_fre; 

	// 결과 값 파일에 출력
	for (int i = 0; i < 50; i++, t = t + dt) {
		out_file1 << t << endl; // x축
		out_file2 << sin(2 * PI * fre * t) << endl; // y축
	}
	return 0;
}