#include<iostream>
#include<cstdlib>
#include<map>
#include "Matrix.h"
#include "Vector.h"
using namespace std;
int main(){
    map<int,double> L;
    Vector<double> V;
    typedef Vector<double> vector;
    map<int,vector > T;
    for(int i=0;i<7;i++){
        L.insert(pair<int,double>(i,2.2*i));
    }
    V.load(L);
    for(int i=0;i<7;i++){
        T.insert(pair<int,Vector<double> >(i,V));
    }
    Matrix<double> H;
    H.load(T);
    cout<<H(6,2)<<endl;
    L.clear();
    for(int i=0;i<7;i++){
        L.insert(pair<int,double>(i,3.5*i));
    }
    V.clear();
    V.load(L);  //构造向量V
    T.clear();  
    for(int i=0;i<7;i++){
        T.insert(pair<int,vector >(i,V));
    }
    Matrix<double> M;
    M.load(T);   //构造矩阵M
    cout<<M(6,2)<<endl;
    Matrix<double> N=H*M;
    cout<<N(6,0)<<endl;
    cout<<N(0,6)<<endl;
    N=N.transposition();
    cout<<N(0,6)<<endl;
    cout<<N(6,0)<<endl;
    Vector<double> O;
    for(int i=0;i<7;i++){
        O.push(i*0.9);
    }
    cout<<O[4]<<endl;
    cout<<N.det()<<endl;
    return 0;
}