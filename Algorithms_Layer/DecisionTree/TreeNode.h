#ifndef TREENODE_H
#define TREENODE_H
#include<iostream>
#include<cstdlib>
using namespace std;
template<class T>
struct BiNode{
    pair<int,T> point;
    double loss;
    double loss_all;
    BiNode* left;
    BiNode* right;
    BiNode* father;
    BiNode(pair<int,T> x):point(x),left(NULL),right(NULL),loss(0),loss_all(0){}
    int count(){
        int result=0;
        if(this!=NULL){
            result+=(this->left).count();
            result+=(this->right).count();
            result++;
        }
        return result;
    }//Post traversal to calculate the number of nodes of this BiNode
};
template<class data_type>
struct Node{
    data_type Data;
    Node<data_type>* first_child;
    Node<data_type>* next_sibling;
    Node(data_type x):Data(x),first_child(NULL),next_sibling(NULL){}
};
#endif