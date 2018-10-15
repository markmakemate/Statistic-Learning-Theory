#ifndef SIGN_H
#define SIGN_H
#include<iostream>
using namespace std;
template<class value_type>
class Sign{
public:
    int operator()(const value_type value){
        int sign=0;
        if(value<0){
            sign=-1;
        }
        else{
            sign=1;
        }
        return sign;
    }
};
#endif