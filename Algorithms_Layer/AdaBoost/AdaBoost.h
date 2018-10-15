#ifndef ADBOOST_H
#define ADBOOST_H
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include "Boosting_Tree.h"
#include "Sign.h"
#include "Base.h"
using namespace std;
template<class classifier,class table>
class AdaBoost:protected Loader<classifier>{
private:
    vector<double> weight;
    queue<classifier> G;
    classifier init_G;
    queue<double> paramas;
    double error;
    double norm;
    int step,label;
    Sign<float> sign; 
    table Data;
public:
    AdaBoost();
    AdaBoost(const table& Input,int& label);
    void load(const table& Input,int& label);
    void initial_weight();
    void update_weight();
    void update_parama();
    void update_norm();
    void update_error();
    void forward(double valve=0.01);
    int operator()(const vector<double>& value){
        float final_classifier=0;
        for(int i=0;i<step;i++){
            final_classifier+=paramas.front()*G.front()(value);
            G.push_back(G.front());
            G.pop();
            paramas.push_back(paramas.front());
            paramas.pop();
        }
        return sign(final_classifier);
    }
    friend int Index_function(int value_1,int value_2);
};
template<class classifier,class table>
AdaBoost::AdaBoost(){
    step=0;
    error=1;
}
template<class classifier,class table>
AdaBoost<classifier,table>::AdaBoost(const table& Input,int& Label){
    step=0;
    error=1
    Data=Input;
    label=Label;
}
template<class classifier,class table>
void AdaBoost<classifier,table>::load(const table& Input,int& Label){
    Data=Input;
    label=Label;
}
template<class classifier,class table>
void AdaBoost<classifier,table>::initial_weight(){
    int N=Data.num();
    vector<double> candidate(N,1/N);
    weight.swap(candidate);
    delete candidate;
}
template<class classifier,class table>
void AdaBoost<classifier,table>::update_weight(){
    vector<double>::iterator it;
    int i=0;
    update_norm();
    for(it=weight.begin();it!=weight.end();++it){
        *it=(*it/norm)*exp(-1*paramas.back()*label*G.back()(Table[i]));
    }
}
template<class classifier,class table>
void AdaBoost<classifier,table>::update_error(){
    int N=Data.num();
    error=0;
    for(int i=0;i<N;i++){
        error+=weight.at(i)*I(G.back()(Table[i]),this->label);
    }
}
template<class classifier,class table>
void AdaBoost<classifier,table>::update_parama(){
    double alpha;
    alpha=(1/2)*log((1-error)/error);
    paramas.push_back(alpha);
}
template<class classifier,class table>
void AdaBoost<classifier,table>::update_norm(){
    int N=weight.size();
    norm=0;
    for(int i=0;i<N;i++){
        norm+=weight.at(i)*exp(-1*paramas.back()*this->label*G.back()(Table[i]));
    }
}
template<class classifier,class table>
void AdaBoost<classifier,table>::forward(double valve){
    initial_weight();
    while(error>valve){
        init_G.load(Table);
        init_G.setWeight(this->weight);
        init_G.training();
        G.push_back(init_G);
        update_error();
        update_paramas();
        update_norm();
        update_weight();
    }
}
int Index_function(int value_1,int value_2){
    int sign;
    if(value_1==value_2){
        sign=1;
    }
    else{
        sign=-1;
    }
    return sign;
}
#endif