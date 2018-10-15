#include<iostream>
#include<map>
#include<iterator>
using namespace std;
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

