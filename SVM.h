#ifndef SVM_H
#define SVM_H
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
//SVM is a classifier which aims to find a hyper-plain which can classify the data in the largest.
//Generic Algorithm+SMO
using namespace std;
class VectorProcessor{
private:
    double inner_product;
	double Euclid_Distance;
	vector<double> Vector;
public:
    VectorProcessor(vector<double> v);
    double operator * (const vector<double> a);
	vector<double> Initializer(vector<double> a);
};
VectorProcessor::VectorProcessor(vector<double> v){
	V=v;
}
double VectorProcessor::operator * (const vector<double>& a){
	int dimension=a.size();
	if(dimension==(this->Vector).size()){
		for(int i=0;i<dimension;i++){
			this->inner_product+=(this->Vector).at(i)*a.at(i);
		}
	}
	return this->inner_product;
}
vector<double> VectorProcessor::Initializer(vector<double>& a){
	int length=a.size();
	a.clear();
	for(int i=0;i<length;i++){
		a.push(0);
	}
	return a;
}
template<class type_name>
class Matrix{
	typedef vector<type_name>* matrix;
	typedef Matrix<type_name> MatrixXt;
private:
    int rows;
	int cols;
public:
    Matrix(int row=1,int col=1);
	Matrix(matrix input);
	Matrix(Matrix<type_name> M);
	MatrixXt operator * (const Matrix<type_name>& A,const Matrix<type_name>& B);
	MatrixXt operator + (const MatrixXt& A,const MatrixXt& B);
	type_name getElement(int i,int j);
};

class SVM:public VectorProcessor,public Matrix {
	typedef vector<double>* input_model;
	typedef queue<vector<double> > storage_model;
	typedef Matrix<double> MatrixXd;
private:
    MatrixXd Kernel;
	vector<double> weight;
	vector<double> valve;
	vector<double> alpha;
	queue<input_model > result;
protected:
    int* Select_Variable(input_model Input);     //Selecting variable's index method
	double* Update_Error(input_model Input,int* alpha_index,double valve=0);      //Error E1&E2 updating
	double Update_Valve(input_model Input,int* alpha_index,double valve_old=0);   //valve b updating
	void Update_Alpha(input_model Input,int* alpha_index,double valve_old);
	vector<double> g(vector<double> alpha,input_model Input,double valve);
	bool Terminate_Condition(input_model Input);
public:
    SVM(MatrixXd Kernel);    //Kernel is the kernel function matrix
	storage_model Solution_SMO(input_model Input,double err=0.1,double valve_old=1);    //Recursively solve SMO
	storage_model SMO(input_model Input,double err=0.1);  //Sequential Minimum Optimization
	storage_model GA(input_model Input);  //Generic Algorithm
	storage_model SAA(input_model Input); //Simulated Anealing Algorithm
	storage_model PSO(input_model Input); //Particle Swarm Optimization
	
};
SVM::SVM(MatrixXd kernel){
	Kernel=kernel;
	this->alpha=this->Initializer(this->alpha);   
	 //Initialize alpha vector
}
queue<vector<double> > SVM::SMO(vector<double>* Input,double err){
	//recursively solution
	return Solution_SMO(Input,err);
	//The first element is alpha vector, the second is valve b
}
queue<vector<double> > SVM::Solution_SMO(vector<double>* Input,double err,double valve_old){
	typedef queue<vector<double> > storage_model;
	typedef vector<double> Vector;
	int* Optimi_variable_Index=new int[2];
	double* error=new double[2];
	double valve_new;
	Vector valve;
	valve_old=(*(Input)).at((*Input).size()-1);
    //Initialize valve
	if(!Terminate_Condition(Input)){
		Optimi_variable_Index=Select_Variable(Input);
		Update_Alpha(Input,Optimi_variable_Index,valve_old);
		valve_new=Update_Valve(Input,Optimi_variable,valve_old);
		error=Update_Error(Input,Optimi_variable_Index,valve_new);
		valve.push_back(valve_new);
		this->result.clear();
		this->result.push(this->alpha);
		this->result.push(valve);
		this->result=Solution_SMO(Input,err,valve_new);
	}
	return this->result;
}
//SMO Solution interface
double* SVM::Select_Variable(vector<double>* Input){
	vector<double>::iterator it=alpha.begin();

}
void Update_Alpha(vector<double>* Input,int* alpha_index,double valve_old){
	vector<double>::iterator it=alpha.begin();
	double* error=new double[2];
	int dimension=(*(Input)).size();
	int a1=*alpha_index;
	int a2=*(alpha_index+1);
	double kai=this->Kernel.getElement(0,0)+this->Kernel.getElement(1,1)-2*(this->Kernel.getElement(0,1));
	double y2=(*(Input+a2)).at(dimension-1);
	*error=g(*(Input+a1)),Input,valve_old)-(*(Input+a1)).at(dimension-1);
	*(error+1)=g(*(Input+a2),Input,valve_old)-(*(Input+a2)).at(dimension-1);
	*(it+a2)=*(it+a2)+y2*(error[0]-error[1])/kai;
	*(it+a1)=
}

//Selecting optimized variable a1,a2
#endif