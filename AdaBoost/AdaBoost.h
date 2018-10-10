#ifndef ADBOOST_H
#define ADBOOST_H
#include<iostream>
#include<vector>
using namespace std;
template<class classifier,class value_type>
class AdaBoost{
private:
    vector<value_type> weight;
    classifier* G;
    classifier init_G;
    double* paramas;
    double* errors; 
public:
    AdaBoost();
    AdaBoost(const classifier& Input);
    virtual void initial_weight();
    virtual void update_weight();
    virtual void getParama();
    virtual void getError();
    virtual void forward();
    virtual value_type operator()(const vector<value_type>& Input);
    friend int sign(value_type value);
};
template<class classifier,class value_type>
class Boosting_Tree:public AdaBoost<classifier,value_type>{
public:
    Boosting_Tree();

};
#endif