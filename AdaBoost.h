#ifndef ADABOOST_H
#define ADABOOST_H
#include<iostream>
#include<Eigen/Eigen/Dense>
#include<vector>
using namespace std;
using namespace Eigen;
template<class Elemtype>
struct TreeNode{
    Elemtype data;
    TreeNode<Elemtype>* left;
    TreeNode<Elemtype>* right;
    TreeNode<Elemtype>* father;
    TReeNode(Elemtype x):data(x),left(NULL),right(NULL),father(NULL){}
};
template<class Elemtype>
class AdaBoost{
public:
     AdaBoost();
     vector<double> Initialize_Weight();
     vector<double> Update_Weight();
     TreeNode<Elemtype>* Boost_Tree(string selection);

};




#endif