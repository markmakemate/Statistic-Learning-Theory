#ifndef SVM_H
#define SVM_H
#include<iostream>
#include "DataProcessor.h"
#include "../Linear_Algebra/Matrix.h"
using namespace std;

//SVM class
//Constructor: initialize alpha, weight and set Data equals Input table object
//SMO: Sequence minimization optimize algorithm
//initial: initialize weight & bias
//update: update weight adn bias
//GA: interface of Generic Algorithm
//SAA: interface of Simulate Aneal Algorithm
//PSA: interface of Particle Swarm Algorithm
template<class table,class value_type>
class SVM:public Matrix<value_type>{
private:
    bool Terminate_Condition();
public:
    vector<value_type> alpha;
    value_type bias;
    table Data;
    SVM();
    SVM(const table& Table);
    void SMO();
    void initial();
    void update();
    virtual void GA();
    virtual void SAA();
    virtual void PSA();
};
template<class table,class value_type>
void SVM::initial(){
    vector<value_type>::iterator it;
    for(it=this->alpha.begin();it!=this->alpha.end();++it){
        *it=0;
    }
    this->bias=0;
}
//
template<class table,class value_type>
class Heuristic_Algorithm:public SVM<table,value_type>{
public:
    void GA();
    void SAA();
    void PSA();
    
    
};
#endif
