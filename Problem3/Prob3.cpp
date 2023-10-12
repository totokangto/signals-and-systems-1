#include<iostream>
#include<fstream>
#include<cmath>
#include"complex.h"
#include<stdlib.h>
#define PI 3.141592

using namespace std;

int main() {

	// 4개의 신호 정의
	// Acos(wπt+Ø)의 복소수 형태 : AcosØ + jAsinØ
	int x1 = 2; // x1(t) = 2
	complex x2(-0.2*PI); // x2(t) = 2cos(30πt-0.2π)
	x2 = x2*2; // Amplitude(2) 곱해주기
	complex x3(-0.25 * PI); // x3(t) = 4cos(30πt-0.25π)
	x3 = x3 * 4; // Amplitude(4) 곱해주기
	complex x4(-0.4 * PI); // x4(t) = 3cos(30πt-0.4π)
	x4 = x4 * 3; // Amplitude(3) 곱해주기

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

	// singal_x는 복소수 형태이므로 sinusoid형태로 나타내면
	// x(t) = sig_x_mag*cos(wt+sig_x_phase)

	// magnitude, phase 값 확인해보기
	cout << "magintude of x(t) : " << sig_x_mag << endl;
	cout << "phase of x(t) : " << sig_x_phase << endl;

	// 텍스트 파일 생성
	ofstream t_axis_file;
	ofstream sp_f_num_file;
	t_axis_file.open("cosine_graph_t.txt");
	sp_f_num_file.open("sp_f_25.txt"); // 200 100 60 25로 각각 바꿔주며 실행한다.

	// 변수 설정
	double freq, sample_freq, t, Ts;

	// sampling frequency : 200 100 60 25 
	cout << "input the sample frequency : ";
	cin >> sample_freq;
	t = 0;
	freq = (30 * PI) / (2 * PI); // w/2π = 15(w=30π)
	Ts = 1.0 / sample_freq;
	
	// 결과 값 파일에 출력
	for (int i = 0; i < 50; i++, t = t + Ts) {
		t_axis_file << t << endl; // x축
		sp_f_num_file << sig_x_mag*cos(2 * PI * freq * t - sig_x_phase) << endl; // y축
	}
	cout << "결과 값을 txt파일로 저장했습니다.";
	system("pause");
	return 0;

}
