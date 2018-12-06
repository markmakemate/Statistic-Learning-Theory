#ifndef SVM_H
#define SVM_H
#include<iostream>
#include<map>
#include<vector>
#include<cstdlib>
#include "../lib/Linear_Algebra/Matrix.h"
using namespace std;
//SVM class:
//Constructor: Input kernal function matrix and data table
//Kernal function matrix must be imported. 
//SMO: Sequence minimization optimize algorithm
//initial: initialize weight & bias
//update: update weight and bias
//GA: interface of Generic Algorithm
//SAA: interface of Simulate Aneal Algorithm
//PSA: interface of Particle Swarm Algorithm
template<class table>
class SVM{
private:
    bool terminate(double valve);
    table Data;
    static vector<double> alpha;
    static vector<double> weight;
    map<int,double> optim_variable;
    static double bias;
    Matrix<double> Kernal;
    static Sign<double> sign;
public:
    SVM(Matrix<double>& kernal, table* Table=NULL);
    void load(table& Table);
    void SMO(valve=0.001);
    void training(int selection=0);
    //selection=0: SMO
    //selection=1: Generic Algorithm
    //selection=2: Simulate Aneal Algorithm
    //selection=3: Particle Swarm Algorithm
    void select();
    void initial();
    void update();
    virtual void GA();
    virtual void SAA();
    virtual void PSA();
    int operator()(table sample){
        
    }
};
template<class table>
SVM<table>::SVM(Matrix<double>& kernal,table* Table){
    Kernal=kernal;
    if(Table!=NULL){
        Data=*Table;
    }
    initial();
}
template<class table>
static void SVM<table>::initial(){
    vector<double>::iterator it;
    for(it=alpha.begin();it!=alpha.end();++it){
        *it=0;
    }
    bias=0;
}
template<class table>
void SVM<table>::load(table& Table){
    Data=Table;
}
template<class table>
static void SVM<table>::update(){
   map<int,double>::iterator it;
   for(it=optim_variable.begin();it!=optim_variable.end();it++){
       
   }
}
#include "./Heuristic-Algorithms/Heuristic_Algorithms.h"
#endif
