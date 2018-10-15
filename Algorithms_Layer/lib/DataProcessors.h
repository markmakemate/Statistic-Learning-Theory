#ifndef DATAPROCESSORS_H
#define DATAPROCESSORS_H
#include<iostream>
#include<map>
#include<iterator>
using namespace std;
template<class prop_type,class value_type>
class Raw{
    typedef map<prop_type,value_type> raw;
private:
    raw sample;
    int dimension;
public:
    Raw();
    void load(const raw& Input);
    void push(prop_type& character,value_type& value) const;
    void pop(const prop_type& character);
    int dim();
};
template<class prop_type,class value_type>
Raw<prop_type,value_type>::Raw(){
    sample=NULL;
    dimension=0;
}
template<class prop_type,class value_type>
void Raw<prop_type,value_type>::load(const map<prop_type,value_type>& Input){
    sample=Input;
}
template<class prop_type,class value_type>
void Raw<prop_type,value_type>::push(prop_type& character,value_type& value) const{
    sample.insert(make_pair(character,value));
}
template<class prop_type,class value_type>
void Raw<prop_type,value_type>::pop(const prop_type& character){
    sample.erase(character);
}
template<class prop_type,class value_type>
int Raw<prop_type,value_type>::dim(){
    dimension=sample.size();
    return dimension;
}

template<class sample_index,class value_type>
class Column{
    typedef map<sample_index,value_type> column;
private:
    column character;
    int number;
public:
    Column();
    void load(const column& Input);
    void push(sample_index& index,value_type& value) const;
    void pop(const sample_index& index);
    int num();
};
template<class sample_index,class value_type>
Column<sample_index,value_type>::Column(){
    character=NULL;
    number=0;
}
template<class sample_index,class value_type>
void Column<sample_index,value_type>::load(const column& Input){
    character=Input;
}
template<class sample_index,class value_type>
void Column<sample_index,value_type>::push(sample_index& index,value_type& value) const{
    character.insert(make_pair(index,value));
}
template<class sample_index,class value_type>
void Column<sample_index,value_type>::pop(const sample_index& index){
    character.erase(index);
}
template<class sample_index,class value_type>
int Column<sample_index,value_type>::num(){
    number=character.size();
    return number;
}
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


//Raw-oriented Table
//Subclass of Table
template<class sample_index,class prop_type,class value_type>
class Table_Raw:public Table<sample_index,prop_type,value_type>{
    typedef Raw<prop_type,value_type> raw;
    typedef map<sample_index,raw> table;
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
};

//Column-Oriented Table
//Subclass of Table
template<class sample_index,class prop_type,class value_type>
class Table_Column:public Table<sample_index,prop_type,value_type>{
    typedef map<prop_type,map<sample_index,value_type> > table;
    typedef Column<sample_index,value_type> column;
private:
    table Data;
    int dimension;
public:
    Table_Column();
    Table_Column(const table& Input);
    column operator[](const prop_type& position){
        return Data.at(position);
    }
    int dim();
    table QuickSort(prop_type& character,int begin=0,int end=1);
    table Partition(prop_type& character,int begin=0,int end=1);
    double Gini(prop_type character,value_type value);
    double Entropy(prop_type character);
    map<value_type,double> Conditional_Entropy(prop_type Y,prop_type X);
    map<value_type,double> Info_Gain(prop_type Y,prop_type X);
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
        return sets.end();
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



//DataLoader class
template<class Set>
class DataLoader{
    typedef Collection<Set> collection;
public:
    collection dataloader;
    DataLoader();
    DataLoader(const collection& Input);
    void buil(const collection& Input);
    void push(const Set& dataset);
    void pop(string name);
    Set operator[](string name){
        return dataloader[name];
    }
};


#endif
