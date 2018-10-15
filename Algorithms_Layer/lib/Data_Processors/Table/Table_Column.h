#include<iostream>
#include<map>
#include<iterator>
#include "Table.h"
#include "Raw.h"
#include "Column.h"
#include "Table_Raw.h"
using namespace std;
//Column-Oriented Table
//Subclass of Table
template<class sample_index,class prop_type,class value_type>
class Table_Column:public Table<sample_index,prop_type,value_type>{
    typedef map<prop_type,map<sample_index,value_type> > table;
    typedef Table_Raw<sample_index,prop_type,value_type> table_raw;
    typedef Column<sample_index,value_type> column;
private:
    table Data;
    table_raw Data_Raw;
    int dimension;
public:
    Table_Column();
    Table_Column(const table& Input);
    column operator[](const prop_type& position){
        return Data.at(position);
    }
    void build(const table& Input);
    int dim();
    void transposition();
    void push(const column& Input);
    void pop(const sample_index& index);
    table QuickSort(prop_type& character,int begin=0,int end=1);
    table Partition(prop_type& character,int begin=0,int end=1);
    double Gini(prop_type character,value_type value);
    double Entropy(prop_type character);
    map<value_type,double> Conditional_Entropy(prop_type Y,prop_type X);
    map<value_type,double> Info_Gain(prop_type Y,prop_type X);
};