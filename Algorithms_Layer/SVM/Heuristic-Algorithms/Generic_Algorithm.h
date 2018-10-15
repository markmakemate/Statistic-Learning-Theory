#ifndef GENERICALGORITHM_H
#define GENERICALGORITHM_H
#include<iostream>
#include<cstdlib>
#include<vector>
#include "../SVM.h"
#include "Heuristic_Algorithms.h"
using namespace std;
template<class table>
class Generic_Algorithm:public Heuristic_Algorithms<table>
{
private:
    bool terminate(double valve);
    vector<double>* population;
    vector<double> child;
    vector<double>* parents;
    double fitness(vector<double> weight,double bias);
public:
    void initial();
    void select();
    void cross();
    void variate();
    void update();
    void GA(double valve=0.001);
};
template<class table>
void Generic_Algorithm<table>::GA(double valve)
{
    initial();
    while(!terminate(valve)){
        select();
        cross();
        variate();
        update();
    }
}

#endif