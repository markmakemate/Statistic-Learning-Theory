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
template<class sample_index,class prop_type,class value_type>
class Table{
    typedef Raw<sample_index,value_type> raw;
    typedef Column<prop_type,value_type> column;
    typedef map<prop_type,raw> table_column;
    typedef map<sample_index,column> table_raw;
public:
    Table();
    virtual void build();
    virtual void push();
    virtual void pop();
    virtual int dim();
    virtual int num();
    virtual raw operator[](const sample_index& position);
    virtual column operator[](const prop_type& position);
};

#include "Table_Raw.h"
#include "Table_Column.h"
