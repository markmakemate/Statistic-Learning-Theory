#include<iostream>
#include<cstdlib>
#include"Perceptron.h"
#include"Eigen\Eigen\Dense"
using namespace std;
using namespace Eigen;
int main() {
	Perceptron P;
	double* input[2];
	double A[2][2]={{3.0,1},{4.0,-1}};
	*input=A[0];
	*(input+1)=A[1];
	double a[2]={0,0} ;
	double* alpha=new double[2];
	*(alpha+1)=a[1];
	*alpha=a[0];
	P.perceptron(input, alpha, 0, 2, 1);
	P.ShowModel();
	return 0;
}
