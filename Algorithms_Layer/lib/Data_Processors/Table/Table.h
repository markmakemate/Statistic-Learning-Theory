#include<iostream>
#include<map>
#include<iterator>
using namespace std;
//Table class
//sample_index: data type of the index of a sample
//prop_type: data type of the properties
//value_type: data type of the value
//build: build a Table object
//push: insert a new sample
//pop: delete a fixed sample
//dimension: a Table object's dimension
//num: number of samples of a Table's object
template<class value_type>
class Table{
public:
    virtual void load();
    virtual void push();
    virtual void pop();
    virtual void clear();
    virtual int dim();
    virtual int num();
    virtual void operator[](const int& index);
    virtual void operator()(const int& raw,const int& col);
    virtual void operator + (void* B);
    virtual void operator - (void* B);
    virtual void split();
    virtual int label();
    virtual void refix();
    virtual void QuickSort();
    virtual void gini();
    virtual void entropy();
    virtual void info_gain();
    virtual void mean();
    virtual void var();
};
#include "Table_Raw.h"
