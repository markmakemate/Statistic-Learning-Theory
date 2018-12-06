#include<queue>
#include<map>
#include<iostream>
#include<cmath>
#include "Vector.h"
using namespace std;
//Matrix class
template<class value_type>
class Matrix{
    typedef Vector<value_type> raw;
    typedef map<int,raw> matrix;
private:
//Data: copy of input
//col_num: number of columns
//raw_num: number of rows
    matrix Data;
    int raw_num;
    int col_num;
protected:
    Matrix cofactor(int m,int n);
public:
    Matrix();
    Matrix(matrix& Input);
    ~Matrix(){
        Data.clear();
    }
    void load(matrix& Input);
    Matrix transposition();
    Matrix inverse();
    int raws();
    int cols();
    double det();  //calculate the determinant
    value_type operator () (int raw_index,int col_index);
    raw operator [] (int& raw_index){
        return Data[raw_index];
    }
    Matrix operator * (Matrix& B);
    Matrix operator + (Matrix& B);
    Matrix operator * (value_type paramas);
    Matrix power(int n);
    queue<value_type> eigen_value();
    Vector<value_type> eigen_vector();
};
template<class value_type>
Matrix<value_type>::Matrix(){
    raw_num=col_num=0;
}
template<class value_type>
Matrix<value_type>::Matrix(map<int,Vector<value_type> >& Input){
    Vector<value_type> candidate=Input.at(0);
    Data=Input;
    raw_num=Input.size();
    col_num=candidate.dim();
}
template<class value_type>
//load the data
void Matrix<value_type>::load(map<int,Vector<value_type> >& Input){
    Data=Input;
    Vector<value_type> candidate=Input.at(0);
    raw_num=Input.size();
    col_num=candidate.dim();
}
template<class value_type>
//return the number of rows
int Matrix<value_type>::raws(){
    return raw_num;
}
template<class value_type>
//return the number of columns
int Matrix<value_type>::cols(){
    return col_num;
}
template<class value_type>
//Override operator ()
//Get the element M(i,j) of i-th row and j-th col
value_type Matrix<value_type>::operator()(int raw_index,int col_index){
    return Data[raw_index][col_index];
}
template<class value_type>
//Override operator *
//Implementation of multiply operation
//Strassn Algorithm, Complexity: O(N^2)
Matrix<value_type> Matrix<value_type>::operator * (Matrix<value_type>& B){
    map<int,Vector<value_type> > candidate;
    Vector<value_type> raw;
    Matrix<value_type> result;
    Matrix<value_type> T;
    value_type value;
    if(col_num==B.raws()&&raw_num==B.cols()){
        T=B.transposition();
        for(int i=0;i<raw_num;i++){
            for(int j=0;j<col_num;j++){
                value=T[j]*Data[i];
                raw.push(value);
            }
            candidate.insert(pair<int,Vector<value_type> >(i,raw));
            raw.clear();
        }
        result.load(candidate);
    }
    else{
        throw "Please input matrixs with right col number and raw number!";
    }
    return result;
}

//Override operator +
//Two matrices plus operation
template<class value_type>
Matrix<value_type> Matrix<value_type>::operator + (Matrix<value_type>& B){
    //result: output
    //candidate: medium value
    //raw: row of matrix B
    map<int,Vector<value_type> > candidate;
    Vector<value_type> raw;
    Matrix<value_type> result;
    if(raw_num==B.raws()&&col_num==B.cols()){
        for(int i=0;i<raw_num;i++){
            raw=B[i]+Data[i];
            candidate.insert(pair<int,Vector<value_type> >(i,raw));
        }
        result.load(candidate);
    }
    else{
        throw "Please input matrixs with right col number and raw number!";
    }
    return result;
}

//Matrix transposition
//Complexity: O(N^2)
template<class T>
Matrix<T> Matrix<T>::transposition(){
    typedef Vector<T> raw;
    typedef map<int,raw> matrix;
    //result: the Data of output matrix R
    //R: output matrix
    //candidate: rows of primitive matrix
    map<int,Vector<T> > result;
    Matrix<T> R;
    Vector<T> candidate;
    for(int i=0;i<col_num;i++){
        for(int j=0;j<raw_num;j++){
            candidate.push((*this)(j,i));
        }
        result.insert(pair<int,raw>(i,candidate));
        candidate.clear();
    }
    R.load(result);
    return R;
}

//Obtain the cofactor
template<class T>
Matrix<T> Matrix<T>::cofactor(int m,int n){
    //element: row of P
    //cofactor: output
    map<int,Vector<T> > P;
    Vector<T> element;
    Matrix<T> Cofactor;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            element.push((*this)(i,j));
        }
        for(int j=n+1;j<(*this).cols();j++){
            element.push((*this)(i,j));
        }
        P.insert(pair<int,Vector<T> >(i,element));
        element.clear();
    }
    for(int i=m+1;i<Data.size();i++){
        for(int j=0;j<n;j++){
            element.push((*this)(i,j));
        }
        for(int j=n+1;j<(*this).cols();j++){
            element.push((*this)(i,j));
        }
        P.insert(pair<int,Vector<T> >(i-1,element));
        element.clear();
    }
    Cofactor.load(P);
    return Cofactor;
}

//calculate determinant
template<class T>
double Matrix<T>::det(){
    typedef Matrix<T> matrix;
    queue<matrix> cofactors;
    double result=0;
    int count=0;
    if(raw_num==col_num&&Data.size()>2){
        for(int i=0;i<raw_num;i++){
            Matrix<T>* P=new Matrix<T>;
            *P=(*this).cofactor(i,0);
            cofactors.push(*P);
        }
        for(double value=cofactors.front().det();cofactors.size()!=0;value=cofactors.front().det()){
            result+=(*this)(count,0)*value*pow(-1,count);
            count++;
            cofactors.pop();
        }
    }
    else if(raw_num==col_num&&Data.size()==2){
        result=(*this)(0,0)*(*this)(1,1)-(*this)(0,1)*(*this)(1,0);
    }
    else if(raw_num!=col_num){
        throw "error!";
    }
    return result;
}

