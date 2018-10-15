#include<iostream>
#include<map>
#include<iterator>
using namespace std;
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
#include "Table.h"