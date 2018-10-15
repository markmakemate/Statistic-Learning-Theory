#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H
#include<queue>
#include<map>
#include<iostream>
using namespace std;
//Vector class
template<class value_type>
class Vector{
    typedef map<int,value_type> raw;
private:
    raw Data;
    int dimension;
public:
    Vector();
    Vector(const raw& Input);
    void load(const raw& Input);
    int dim();
    value_type operator[](const int& index);
    double operator*(Vector& B);
};
//Matrix class
template<class value_type>
class Matrix{
    typedef Vector<value_type> raw;
    typedef map<int,raw> matrix;
private:
    matrix Data;
    int raw_num;
    int column_num;
public:
    Matrix();
    Matrix(matrix& Input);
    void load(matrix& Input);
    void Transposition();
    Matrix inverse();
    int raws();
    int cols();
    raw operator[](const int& raw_index);
    value_type operator () (const int& raw_index,const int& col_index);
    Matrix operator * (const Matrix& B);
    Matrix operator + (const Matrix& B);
    Matrix operator * (const value_type& paramas);
    queue<value_type> eigen_value();
    Vector<value_type> eigen_vector();
};

#endif