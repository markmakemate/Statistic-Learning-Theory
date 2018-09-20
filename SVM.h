#ifndef SVM_H
#define SVM_H
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include"Linear_Algebra.h"
//SVM is a classifier which aims to find a hyper-plain which can classify the data. 
//Evolutionary Algorithm+SMO
using namespace std;
class SVM:public Matrix {
	typedef vector<double>* input_model;
	typedef queue<vector<double> > storage_model;
	typedef Matrix<double> MatrixXd;
private:
    MatrixXd Kernel;
	vector<double> weight;
	vector<double> valve;
	vector<double> alpha;
	vector<double> classes;
	queue<input_model > result;
	int size,dimension;
	input_model Input;
protected:
    int* Select_Variable();     //Selecting variable's index method
	double* Update_Error(int* alpha_index,double valve=0);      //Error E1&E2 updating
	double Update_Valve(int* alpha_index,double valve_old=0);   //valve b updating
	void Update_Alpha(int* alpha_index,double valve_old);     //updating alpha
	vector<double> g(double valve);
	bool Terminate_Condition();
public:
    SVM(MatrixXd Kernel,vector<double>* _Input);    //Kernel is the kernel function matrix
	storage_model Solution_SMO(double err=0.1,double valve_old=1);    //Recursively solve SMO
	storage_model SMO(double err=0.1);  //Sequential Minimum Optimization
};
SVM::SVM(MatrixXd kernel,vector<double>* _Input){
	size=sizeof(_Input);
	Input=new vector<double>[size];
	Input=_Input;
	dimension=(*(Input)).size();
	Kernel=kernel;
	this->alpha=this->Initializer(this->alpha);  
	for(int i=0;i<size;i++){
		classes.push_back((*(Input+i)).at(dimension-1));
	} 
	 //Initialize alpha vector
}
queue<vector<double> > SVM::SMO(double err){
	//recursively solution
	int dimension=(*(this->Input)).size();
	for(int i=0;i<this->size;i++){
		this->classes.push_back((*(this->Input+i)).at(dimension-1));
	}
	return Solution_SMO(err);
	//The first element is alpha vector, the second is valve b
}
queue<vector<double> > SVM::Solution_SMO(double err,double valve_old){
	typedef queue<vector<double> > storage_model;
	typedef vector<double> Vector;
	int* Optimi_variable_Index=new int[2];
	double* error=new double[2];
	double valve_new;
	Vector valve;
	valve_old=(*(this->Input)).at((*(this->Input)).size()-1);
    //Initialize valve
	if(!Terminate_Condition()){
		Optimi_variable_Index=Select_Variable();
		Update_Alpha(Optimi_variable_Index,valve_old);
		valve_new=Update_Valve(Optimi_variable_Index,valve_old);
		error=Update_Error(Optimi_variable_Index,valve_new);
		valve.push_back(valve_new);
		this->result.clear();
		this->result.push(this->alpha);
		this->result.push(valve);
		this->result=Solution_SMO(err,valve_new);
	}
	return this->result;
}
//SMO Solution interface
double* SVM::Select_Variable(){
	vector<double>::iterator it=alpha.begin();

}
void SVM::Update_Alpha(int* alpha_index,double valve_old){
	vector<double>::iterator it=alpha.begin();
	double* error=new double[2];
	int a1=*alpha_index;
	int a2=*(alpha_index+1);
	double kai=this->Kernel.getElement(0,0)+this->Kernel.getElement(1,1)-2*(this->Kernel.getElement(0,1));
	double y2=(this->classes).at(a2);
	*error=g(valve_old)-(*(this->Input+a1)).at(dimension-1);
	*(error+1)=g(valve_old)-(*(this->Input+a2)).at(dimension-1);
	*(it+a2)=*(it+a2)+y2*(error[0]-error[1])/kai;
	*(it+a1)=
}


//Selecting optimized variable a1,a2
#endif