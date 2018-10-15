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
#include "Table.h"