#ifndef SVM_H
#define SVM_H
#include<iostream>
#include "../lib/Linear_Algebra.h"
using namespace std;
//SVM class
//Constructor: Input kernal function matrix and data table
//Kernal function matrix must be imported. 
//SMO: Sequence minimization optimize algorithm
//initial: initialize weight & bias
//update: update weight adn bias
//GA: interface of Generic Algorithm
//SAA: interface of Simulate Aneal Algorithm
//PSA: interface of Particle Swarm Algorithm
template<class table>
class SVM{
protected:
    bool terminate(double valve);
    table Data;
    vector<double> alpha;
    double bias;
    Matrix<double> Kernal;
public:;
    SVM(const Matrix<double>& kernal,const table& Table=NULL);
    void load(const table& Table);
    void SMO(double valve=0.001);
    void initial();
    void update();
    virtual void GA();
    virtual void SAA();
    virtual void PSA();
};
template<class table>
void SVM<table>::initial(){
    vector<double>::iterator it;
    for(it=alpha.begin();it!=alpha.end();++it){
        *it=0;
    }
    bias=0;
}
#include "./Heuristic-Algorithms/Heuristic_Algorithms.h"
#endif
