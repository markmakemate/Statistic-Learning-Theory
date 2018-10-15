#ifndef HEURISTICALGORITHMs_H
#define HEURISTICALGORITHMs_H
#include<iostream>
#include<cstdlib>
#include<vector>
#include "../SVM.h"
using namespace std;
template<class table>
class Heuristic_Algorithms:public SVM<table>
{
public:
    virtual void GA();
    virtual void SAA();
    virtual void PSA();
};
#include "Generic_Algorithm.h"
#include "Simulated_Aneal.h"
#endif
