#include<iostream>
#include<map>
#include<iterator>
#include<queue>
#include "Table.h"
using namespace std;
//Raw-oriented Table
//Subclass of Table
template<class value_type>
class Table_Raw:public Table<value_type>{
    typedef map<int,value_type> raw;
    typedef map<int,raw> table;
private:
    table Data;
    int dimension;
    int sample_num;
    int label;
public:
    void set_label(int label);
    void load(table& Input);
    void push(raw& sample);
    void push(value_type& value){
        Data.insert(pair<int,value_type>(0,value));
    }
    void insert(int index,raw sample){
        if(Data.find(index)==Data.end()){
            Data.insert(pair<int,raw>(index,sample));
        }
        else{
            cout<<"Key has existed!";
        }
    }
    void pop(int sample);
    void refix();
    void clear(){
        Data.clear();
        dimension=0;
    }
    int dim(){
        return dimension;
    }
    int num(){
        return Data.size();
    }
    int label(){
        return label;
    }
    raw operator[](int& position){
        return Data[position];
    }
    value_type operator()(int Raw,int Column){
        return Data[Raw][Column];
    }
    Table<T> operator + (Table<T>& B);
    Table<T> operator - (Table<T>& B);
    void transposition();
    Table<value_type>* split(int& sample,int& attribute);
    virtual void QuickSort();
    virtual void gini();
    virtual void entropy();
    virtual void info_gain();
    virtual void mean();
    virtual void var();
};
template<class value_type>
void Table_Raw<value_type>::set_label(int& l){
    label=l;
}
template<class value_type>
void Table_Raw<value_type>::load(table& Input){
    Data=Input;
    dimension=Input[0].size();
}
template<class value_type>
void Table_Raw<value_type>::push(map<int,value_type>& sample){
    int N=Data.size();
    Data.insert(pair<int,map<int,value_tyoe> >(N,sample));
}
template<class value_type>
void Table_Raw<value_type>::pop(int sample){
    Data.erase(sample);
}
template<class T>
void Table_Raw<T>::clear(){
    Data.clear();
    dimension=0;
}
template<class T>
Table<T>* Table_Raw<T>::split(int& sample,int& attribute){
    typedef map<int,value_type> raw;
    raw candidate;
    T value=(*this)(sample,attribute);
    Table<T>* subtable=new Table<T>[2];
    for(int i=0;i<sample;i++){
        if((*this)(i,attribute)<=value){
            candidate=(*this)[i];
            subtable[0].push(candidate);
        }
        else{
            candidate=(*this)[i];
            subtable[1].push(candidate);
        }
    }
    for(int i=sample+1;i<(*this).num();i++){
        if((*this)(i,attribute)<=value){
            candidate=(*this)[i];
            subtable[0].push(candidate);
        }
        else{
            candidate=(*this)[i];
            subtable[1].push(candidate);
        }
    }
    return subtable;
}
template<class T>
void Table_Raw<T>::transposition(){
    typedef map<int,value_type> raw;
    typedef map<int,raw> table;
    raw candidate;
    table result;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<(*this).num();j++){
            candidate.insert(pair<int,value_type>(j,(*this)(j,i)));
        }
        result.insert(pair<int,raw>(i,candidate));
        candidate.clear();
    }
    Data.swap(result);
}

//override operator +
template<class T>
Table<T> Table_Raw<T>::operator + (Table<T>& B){
    typedef map<int,T> raw;
    Table<T> result;
    raw candidate;
    int count;
    for(int i=0;i<B.num();i++){
        raw::iterator it_1=(B[i]).begin();
        count=0;
        for(raw::iterator it=((*this)[i]).begin();it!=((*this)[i]).end();it++){
            candidate.insert(pair<int,T>(count,*(it)+(*(it_1))));
            it_1++;
            count++;
        }
        result.push(candidate);
        candidate.clear();
    }
    return result;
}

//override operator -
template<class T>
Table<T> Table_Raw<T>::operator - (Table<T>& B){
    typedef map<int,T> raw;
    Table<T> result;
    raw candidate;
    int count;
    for(int i=0;i<B.num();i++){
        raw::iterator it_1=(B[i]).begin();
        count=0;
        for(raw::iterator it=((*this)[i]).begin();it!=((*this)[i]).end();it++){
            candidate.insert(pair<int,T>(count,*(it)-(*(it_1))));
            it_1++;
            count++;
        }
        result.push(candidate);
        candidate.clear();
    }
    return result;
}
#include "Table_Algo.h"