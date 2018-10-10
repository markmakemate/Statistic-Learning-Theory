#ifndef DATAPROCESSORS_H
#define DATAPROCESSORS_H
#include<iostream>
#include<map>
#include<iterator>
//Table class
//sample_index: data type of the index of a sample
//prop_type: data type of the properties
//value_type: data type of the value
//build: build a Table object
//push: insert a new sample
//pop: delete a fixed sample
//dimension: a Table object's dimension
//num: number of samples of a Table's object
using namespace std;
template<class sample_index,class prop_type,class value_type>
class Table{
    typedef map<sample_index,map<prop_type,value_type> > table;
    typedef map<sample_index,map<prop_type,value_type> > raw
    typedef map<prop_type,value_type> sample_detail;
protected:
    table Data;
    Table();
    void build(table& Input);
    void push(raw& sample);
    void pop(sample_index position);
    int dimension();
    int num();
    sample_detail operator[](sample_index position){
        return Data.at(position);
    }
};

//Collection class
//update: update data of the key name
//push: insert a new container
//pop: delete a container
//privide an iterator to visit all containers in a Collection object
template<class container>
class Collection{
    typedef map<string,container> collection;
    typedef typename collection::iterator iterator;
    
public:
    collection sets;
    Collection();
    ~Collection();
    void update(string name,container Input);
    void push(string name,container Input);
    void pop(string name);
    container operator[](string name){
        return sets.at(name);
    }
    iterator begin(){
        return sets.begin();
    }
    iterator end(){
        return sets.end()
    }
};


//DataSet class
//Constructor's parameter: Collection<Set> object
//Collection: Key-Value storage, storing Table objects
//table: Table data type
//build: Build a DataSet object
//push: insert a new Table object
//pop: delete a fixed Table object
template<class table>
class DataSet{
    typedef Collection<table> Collection;
public:
    Collection dataset;
    DataSet();
    DataSet(const Collection& Input);
    void build(const Collection& Input);
    void push(const table& Input);
    void pop(string name);
    table operator[](string name){
        return dataset[name];
    }
};



//DataLoader class
template<class Set>
class DataLoader{
    typedef Collection<Set> Collection;
public:
    Collection dataloader;
    DataLoader();
    DataLoader(const Collection& Input);
    void buil(const Collection& Input);
    void push(const Set& dataset);
    void pop(string name);
    Set operator[](string name){
        return dataloader[name];
    }
};


//Transformer class: Transform Table object to Matrix object, subclass of Matrix
//load: load a table
//transform: start transform
template<class table,class value_type>
class Transformer:public Matrix<value_type>{
public:
    table data;
    Transformer();
    ~Transformer();
    Transformer(table& Input);
    void load(table& data);
    void transform();
};
#endif

