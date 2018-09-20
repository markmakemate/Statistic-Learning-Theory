#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H
#include<vector>
#include<iostream>
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
    matrix M;
public:
	Matrix(matrix input);
	friend MatrixXt operator * (const Matrix<type_name>& A,const Matrix<type_name>& B);
	friend MatrixXt operator + (const MatrixXt& A,const MatrixXt& B);
	type_name getElement(int i,int j);
    int rows();
    int cols();
    vector<type_name> getColumn(int i);
    vector<type_name> getRow(int i);
    MatrixXt setElement(int i,int j,type_name value);
};
template<class type_name>
Matrix<type_name>::Matrix(vector<type_name>* input){
    rows=sizeof(input);
    cols=(*input).size();
    M=new vector<type_name>[rows];
    M=input;
}
template<class type_name>
int Matrix<type_name>::rows(){
    return rows;
}
template<class type_name>
int Matrix<type_name>::cols(){
    return cols;
}
template<class type_name>
type_name Matrix<type_name>::getElement(int i,int j){
    return (*(this->M+i)).at(j);
}
template<class type_name>
vector<type_name> Matrix<type_name>::setElement(int i,int j,type_name value){
    vector<type_name> S;
    S=*(this->M+i);
    vector<type_name>::iterator it=S.begin();
    *(S+j)=value;
    return S;
}
template<class type_name>
Matrix<type_name> operator * (const Matrix<type_name>& A,Matrix<type_name>& B){
    Matrix<type_name> result;
    vector<type_name>::iterator a;
    vector<type_name>::iterator b;
    vector<type_name> S;
    if(A.cols()==B.rows()){
        for(int i=0;i<A.rows();i++){
            for(int j=0;j<B.cols();j++){
                S=B.getColumn(j);
                b=S.begin();
                for(a=A.getRow(i).begin();a!=A.getRow(i).end();a++){
                    result.setElement(i,j,(*a)*(*b));
                    b++;
                }
            }
        }
    }
    return result;
}

#endif