#ifndef PERCEPTRON_H
#define PERCEPTRON_H
// This is a modula of Perceptron which is a linear classifier
#include<cstdlib>
#include<iostream>
#include"Eigen\Eigen\Dense" //Including Eigen Library
using namespace std;
using namespace Eigen;
class Perceptron {
private:
	int Dimension;
	double* weight;
	double Learning_Rate;
	double bias;
public:
	Perceptron();
	Perceptron(int dimension);
	double setVariable(double* __Input__[2],int x);
	double getVariable(double* __Input__[2]);
	void perceptron(double* __Input__[2], double* __alpha__, double __bias__,const int __size__,double __LR__);
	int Sign(double __variable__);
	void ShowModel();
	friend int perceptron(double* __Input__);
};

Perceptron::Perceptron() {
	Dimension = 0;
}
Perceptron::Perceptron(int dimension) {
	Dimension = dimension;
}

double Perceptron::setVariable(double* __Input__[2],int x) {
	double* Candidate;
	double variable;
	double* x_i;
	double* x_j;
	int d=Dimension;
	MatrixXd Gram(d,d);
	for (int i = 0; i< d; i++) {
		x_i = *(__Input__ + i);
		for(int j=0;j<d;j++){
			x_j = *(__Input__+j);
			Gram(i, j) = x_i[0] * x_j[0];
		}
	}
	for (int j = 0; j < Dimension; j++) {
		Candidate = *(__Input__ + j);
		variable += *(weight + j)*(*(Candidate + 1))*(Gram(x, j));
	}
	variable += bias;
	return variable;
}
double Perceptron::getVariable(double* __Input__[2]) {
	double* S=new double[2];
	double variable;
	double* x_i;
	double* x_j;
	int d=Dimension;
	MatrixXd Gram(d,d);
	for (int i = 0; i< d; i++) {
		x_i = *(__Input__ + i);
		for(int j=0;j<d;j++){
			x_j = *(__Input__+j);
			Gram(i, j) = x_i[0] * x_j[0];
		}
	}
	for (int i = 0; i < Dimension; i++) {
		for (int j = 0; j < Dimension; j++) {
			S = *(__Input__ + j);
			variable = *(weight + j)*S[1]*(Gram(i, j));
		}
	}
	variable = variable + bias;
	return variable;
}
int Perceptron::Sign(double __variable__) {
	if (__variable__ <= 0) {
		return -1;
	}
	else {
		return 1;
	}
}
void Perceptron::perceptron(double* __Input__[2],double* __alpha__, double __bias__,const int __size__,double __LR__) {
	bias = __bias__;
	Dimension = __size__;
	Learning_Rate = __LR__;
	weight=new double[Dimension];
	weight=__alpha__;
	double __variable__;
	double* S=new double[2];
	for (int i = 0; i < Dimension; i++) {
		S = *(__Input__ + i);
		__variable__ = setVariable(__Input__,i);
		if (S[1]*(__variable__)<=0) {
			*(weight + i) =*(weight+i) + Learning_Rate;
			bias = bias + Learning_Rate * S[1];
		}
	}
}
void Perceptron::ShowModel(){
	cout << "f(x)="<<"sign("<<*weight<<"x"<<"^"<<"("<<0<<")";
	for (int i = 1; i < Dimension; i++) {
		cout << "+" << *(weight + i) << "x" << "^" << "(" << i << ")" ;
	}
	cout <<bias<< ")" << endl;
}
#endif
