#include<iostream>
#include<fstream>
#include<cmath>
#include"complex.h"
#define PI 3.141592

using namespace std;

int main() {

	// 4개의 신호 정의
	int x1 = 2; // x1(t) = 2
	complex x2(-0.2*PI); // x2(t) = 2cos(30πt-0.2π)
	x2.re_num = 2 * x2.re_num; // 실수부분(cos)에 Amplitude 곱해주기
	complex x3(-0.25 * PI); // x3(t) = 4cos(30πt-0.25π)
	x3.re_num = 4 * x3.re_num;
	complex x4(-0.4 * PI); // x4(t) = 3cos(30πt-0.4π)
	x4.re_num = 3 * x4.re_num;

	// x(t) 만들기(복소수 형태)
	double x_re_num = x1 + x2.re_num + x3.re_num + x4.re_num;
	double x_im_num = x2.im_num + x3.im_num + x4.im_num;
	complex signal_x(x_re_num, x_im_num);
	
	// x(t)의 real number, imaginary number 값 확인해보기
	cout << "real number of x(t) : " << x_re_num << endl;
	cout << "imaginary number of x(t) : " << x_im_num << endl;

	// x(t)의 magnitude, phase 구하기
	double sig_x_mag = signal_x.get_mag();
	double sig_x_phase = signal_x.get_phase();
	sig_x_phase = sig_x_phase * (180 / PI); // radian to degree

	// magnitude, phase 값 확인해보기
	cout << "magintude of x(t) : " << sig_x_mag << endl;
	cout << "phase of x(t) : " << sig_x_phase << endl;

	// 텍스트 파일 생성
	ofstream t_axis_file;
	ofstream sp_f_100_file;
	t_axis_file.open("cosine_graph_t.txt");
	sp_f_100_file.open("sp_f_30.txt"); // 100 50 30 10

	// 변수 설정
	double freq, sample_freq, t, Ts;

	// sampling frequency :  100 50 30 10 
	cout << "input the sample frequency : ";
	cin >> sample_freq;
	t = 0;
	freq = (30 * PI) / (2 * PI);
	Ts = 1.0 / sample_freq;
	
	// 결과 값 파일에 출력
	for (int i = 0; i < 50; i++, t = t + Ts) {
		t_axis_file << t << endl; // x축
		sp_f_100_file << sig_x_mag*cos(2 * PI * freq * t - sig_x_phase) << endl; // y축
	}
	cout << "결과 값을 txt파일로 저장했습니다.";
	return 0;

}