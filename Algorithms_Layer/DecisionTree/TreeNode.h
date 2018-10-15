#ifndef TREENODE_H
#define TREENODE_H
#include<iostream>
#include<cstdlib>
using namespace std;
template<class prop_type>
struct BiNode{
    prop_type property;
    BiNode<data_type>* left;
    BiNode<data_type>* right;
    BiNode(prop_type x):property(x),left(NULL),right(NULL){}
};
template<class data_type>
struct Node{
    data_type Data;
    Node<data_type>* first_child;
    Node<data_type>* next_sibling;
    Node(data_type x):Data(x),first_child(NULL),next_sibling(NULL){}
};
#endif