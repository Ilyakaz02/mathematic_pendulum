#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

double pi() { // ����� ����, ��� �� ��������� ��������� ��������������� ��������
	double x1, v1, vmid, t, dt; // ������� ����������
	dt=0.000002;
	x1=0.03;
	v1=0;
	t=0;
	vmid = -x1 * dt/2; // ������� �������� � ������� ����� (��� ��� ������������� midpoint), � v1=0
	while (vmid <= 0) { //������� �������� �������
		t= t + dt;
		x1 = x1 + vmid * dt;
		vmid = vmid-x1 * dt; // ������ ��������� ����������� ��� ��� ��������	
	
	}
			cerr << "pi=" << t << "       " << x1 << "\n"; // ������� ������������ ����� ��
	
	return t;
}
double pendulum(double p) { //����� ��������� ��� ����������� ��������
	double x1, v1, vmid, dx,  t, dt; //������� ����������
	dt=0.0002;
	x1=0.8;
	dx=0.0005; //���������� ���������
	vmid = -sin(x1) * dt/2;
		ofstream outf("pendulum.txt");
	while (x1<p && x1>-p){ //������� ��������� ��� ������ ������ � �������������
	
	x1=x1+dx;
	t=0;
	vmid=0;
	while (vmid <= 0) { //������� �������� �������
		t= t + dt;
		x1 = x1+vmid*dt;
		vmid = vmid-sin(x1) * dt;	// ������ ��������� ����������� ��� ��� ��������

	}	x1 = -x1; //���� ����������� � ��������� ���������
	
	
	 outf << 2 * t << "\t" << x1 << "\n"; //������� � ���� ������ �������� ������� � ���������
	}
}
	

int main () { //������ ������� ������� ��� ��������������� ��������, ��������� ����� ��
	double p;
	p=pi(); 
	
	pendulum(p); //������� ����������� ��������
	return 0; 
}
   //������� �������� � ��������� ����, � ���� ��������� ������� ������ �������� ����� ��, ��������� �(t^2)
