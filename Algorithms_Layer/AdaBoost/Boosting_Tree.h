#ifndef BOOSTINGTREE_H
#define BOOSTINGTREE_H
#include<iostream>
#include "AdaBoost.h"
template<class classifier,class table>
class BoostingTree:public AdaBoost<classifier,table>{
public:
    BoostingTree();

};
#endif