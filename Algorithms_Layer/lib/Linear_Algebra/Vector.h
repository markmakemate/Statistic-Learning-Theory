#ifndef VECTOR_H
#define VECTOR_H
#include<queue>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
//Vector class
template<class value_type>
class Vector{
    typedef map<int,value_type> raw;
private:
    raw Data;
    int dimension;
public:
    Vector(){
        dimension=0;
    }
    Vector(const raw& Input){
        Data=Input;
        dimension=Data.size();
    }
    void load(const raw& Input){
        Data=Input;
        dimension=Data.size();
    }
    int dim(){
        return dimension;
    }
    void push(value_type element){
        Data.insert(pair<int,value_type>(dimension,element));
        dimension++;
    }
    void pop(int& index);
    void clear(){
        Data.clear();
        dimension=0;
    }
    value_type operator[](int index){
        return Data[index];
    }
    value_type operator*(Vector<value_type>& B){
        value_type result;
        if(dimension==B.dim()){
            for(int i=0;i<dimension;i++){
                result+=Data[i]*B[i];
            }
        }
        else{
            throw "error!";
        }
        return result;
    }
    Vector<value_type> operator + (Vector<value_type>& B){
        Vector<value_type> result;
        value_type value;
        if(dimension==B.dim()){
            for(int i=0;i<dimension;i++){
                value=B[i]+Data[i];
                result.push(value);
            }
        }
        else{
            throw "error!";
        }
        return result;
    }
    Vector<value_type> operator - (Vector<value_type>& B){
        Vector<value_type> result;
        value_type value;
        if(dimension==B.dim()){
            for(int i=0;i<dimension;i++){
                value=Data[i]-B[i];
                result.push(value);
            }
        }
        else{
            throw "error!";
        }
        return result;
    }
    value_type norm(int order=2){
        value_type value=0;
        for(int i=0;i<(*this).dim();i++){
            value+=pow((*this)[i],order);
        }
        return pow(value,1/order);
    }
};
#endif