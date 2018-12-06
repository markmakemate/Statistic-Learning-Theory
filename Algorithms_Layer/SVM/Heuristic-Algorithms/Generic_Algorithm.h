#ifndef GENERICALGORITHM_H
#define GENERICALGORITHM_H
#include<iostream>
#include<cstdlib>
#include<vector>
#include "../SVM.h"
#include "encode.h"
#include "Heuristic_Algorithms.h"
using namespace std;
template<class table>
class Generic_Algorithm:public Heuristic_Algorithms<table>
{
private:
    bool terminate(double valve);
    vector<double>* population;
    vector<double> child;
    vector<double>* parent;
    double fitness(vector<double> alpha,double bias);
public:
    Generic_Algorithm();   //Constructor
    void initial(int number=1000);   //initialize population
    void select();    //select a pair of seeds
    void cross();     //cross operation
    void variate();   //variate operation
    void update();    //update population
    void encode();    //encode gene
    void decode();    //decode gene
    vector<double> GA(double valve=0.001,int number=1000);   //Start Generic Algorithm, number is the quantity of population
};
template<class table>
vector<double> Generic_Algorithm<table>::GA(double valve,int number)
{
    initial(number);
    while(!terminate(valve)){
        select();
        encode();
        cross();
        variate();
        decode();
        update();
    }
    return child;
}
template<class table>
void Generic_Algorithm<table>::initial(int number){
    population=new vector(Data.num())[number];
    
}
#endif