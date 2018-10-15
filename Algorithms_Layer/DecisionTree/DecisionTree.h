#ifndef DECISIONTREE_H
#define DECISIONTREE_H
#include<vector>
#include<iostream>
#include<cstdlib>
#include<stack>
#include<map>
#include<cmath>
#include "TreeNode.h"
//Decision Tree class
using namespace std;
template<class table>
class DecisionTree{
private:
    table Table;
	table spliting_point;
protected:
    BiNode<table>* Regression_Tree(BiNode<table>* r=NULL,table subtable=NULL);
	BiNode<table>* Classification_Tree(BiNode<table>* r=NULL,table subtable=NULL);
	table* Least_Square(table SubTable);
public:
	DecisionTree();
	DecisionTree(const table& Input);
	void load(const table& Input);
	BiNode<table>* CART(int selection=0);
	Node<table>* ID3();
	Node<table>* C4_5();
};
template<class table>
DecisionTree<table>::DecisionTree(){
	Table=NULL;
}
template<class table>
DecisionTree<table>::DecisionTree(const table& Input){
	Table=Input;
}
template<class table>
void DecisionTree<table>::load(const table& Input)[
	Table=Input;
]
template<class table>
BiNode<table>* DecisionTree<table>::CART(int selection){
	if(selection==0){
		return this->Regression_Tree();
	}
	else{
		return this->Classification_Tree();
	}
}
template<class table>
BiNode<table>* DecisionTree<table>::Regression_Tree(BiNode<table>* r,table subtable){
	table* subspace;
	if(r==NULL){
		subspace=Least_Square(Table);
		r=new BiNode<table>(spliting_point);
		Regression_Tree(r->left,*subspace);
		Regression_Tree(r->right,*(subspace+1));
	}
	return r;
}
template<class table>
BiNode<table>* DecisionTree<table>::Classification_Tree(BiNode<table>* r,table subtable){
	table* subspace;
	if(r==NULL){
		
	}
}
#endif

