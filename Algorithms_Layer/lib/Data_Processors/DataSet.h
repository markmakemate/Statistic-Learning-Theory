#include<iostream>
#include<map>
#include<iterator>
using namespace std;
//DataSet class
//Constructor's parameter: Collection<Set> object
//Collection: Key-Value storage, storing Table objects
//table: Table data type
//build: Build a DataSet object
//push: insert a new Table object
//pop: delete a fixed Table object
template<class table>
class DataSet{
    typedef Collection<table> collection;
public:
    collection dataset;
    DataSet();
    DataSet(const collection& Input);
    void build(const collection& Input);
    void push(const table& Input);
    void pop(string name);
    table operator[](string name){
        return dataset[name];
    }
};
