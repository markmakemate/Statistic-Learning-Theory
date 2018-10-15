#include<iostream>
#include<map>
#include<iterator>
#include "Table.h"
#include "Raw.h"
#include "Column.h"
#include "Table_Column.h"
using namespace std;
//Raw-oriented Table
//Subclass of Table
template<class sample_index,class prop_type,class value_type>
class Table_Raw:public Table<sample_index,prop_type,value_type>{
    typedef Raw<prop_type,value_type> raw;
    typedef map<sample_index,raw> table;
    typedef Table_Column<sample_index,prop_type,value_type> table_column;
private:
    table Data;
    int dimension;
public:
    Table_Raw();
    void build(const table& Input);
    void push(const raw& sample);
    void pop(const sample_index& position);
    int dim();
    int num();
    raw operator[](const sample_index& position){
        return Data.at(position);
    }
    void transposition();
};