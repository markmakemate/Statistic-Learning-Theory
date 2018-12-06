#ifndef DECISIONTREE_H
#define DECISIONTREE_H
#include<vector>
#include<iostream>
#include<cstdlib>
#include<stack>
#include<map>
#include<cmath>
#include "TreeNode.h"

#define INF 1.79769313486231e+307
//Decision Tree class
using namespace std;

template<class table>
class DecisionTree{
	typedef pair<int,double> elem;
	typedef BiNode<elem>* binode;
	typedef Node<table>* node;
private:
    table Table;
	elem spliting_point;
	double valve_ls;
	double valve_gini;
	static binode biroot;
	static node root;
protected:
    binode Regression_Tree(int Y,binode r=NULL,table* subtable=NULL);
	binode Classification_Tree(int Y,binode r=NULL,table* subtable=NULL);
	table* Least_Square(table SubTable,int Y);
	table* split(table& subtable,int Y);
	bool terminate(table& space,int selection=0);

public:
	DecisionTree();
	DecisionTree(table& Input);
	void load(table& Input);
	void set_valve(double value_ls,double value_gini){
		valve_ls=value_ls;
		valve_gini=value_gini;
	}
	binode CART(int Y,binode r=NULL,int selection=0);
	//selection=0: regression tree
	//selection=1: classification tree
	node ID3(node r=NULL);
	node C4_5(node r=NULL);
	virtual void pruning();
};
template<class table>
DecisionTree<table>::biroot=NULL;
template<class table>
DecisionTree<table>::root=NULL;
template<class table>
DecisionTree<table>::DecisionTree(){
	valve_ls=-1*INF;
	valve_gini=-1*INF;
}
template<class table>
DecisionTree<table>::DecisionTree(table& Input){
	Table=Input;
	valve_ls=-1*INF;
	valve_gini=-1*INF;
}
template<class table>
void DecisionTree<table>::load(table& Input){
	Table=Input;
}
template<class table>
void DecisionTree<table>::CART(int Y,BiNode<table>* r,int selection){
	if(selection==0){
		biroot = Regression_Tree(Y,r);
		pruning(biroot);
	}
	else{
		biroot = Classification_Tree(Y,r);
		pruning(biroot);
	}
}
template<class table>
BiNode<pair<int,double> >* DecisionTree<table>::Regression_Tree(int Y,BiNode<table>* r,table* subtable){
	table* subspace;
	if(r==NULL&&subtable==NULL&&!terminate(Table)){
		subspace=Least_Square(Table,Y);
		r=new BiNode<table>(spliting_point);
		r->left->father=r;
		r->right->father=r;
		r->left=leftRegression_Tree(r->left,*subspace);
		r->right=Regression_Tree(r->right,*(subspace+1));
	}
	else if(r==NULL&&subtable!=NULL&&!terminate(*subtable)){
		subspace=Least_Square(*subtable);
		r=new BiNode<table>(spliting_point);
		r->left->father=r;
		r->right->father=r;
		r->left=Regression_Tree(r->left,*subspace);
		r->right=Regression_Tree(r->right,*(subspace+1));
	}
	else if(r!=NULL&&!terminate(*subtable)){
		BiNode<table>* p=r;
		subspace=Least_Square(*subtable);
		while(p!=NULL){
			if(p->property(0,0)<spliting_point(0,0)){
				p=p->right;
			}
			else{
				p=p->left;
			}
		}
		p=new BiNode<table>(spliting_point);
		p->left->father=p;
		p->right->father=p;
		p->left=Regression_Tree(p->left,*subspace);
		p->right=Regression_Tree(p->right,*(subspace+1));
	}
	return r;
}
template<class table>
BiNode<pair<int,double> >* DecisionTree<table>::Classification_Tree(int Y,BiNode<table>* r,table* subtable){
	table* subspace;
	if(r==NULL&&subtable==NULL&&!terminate(Table,1)){
		subspace=split(Table,Y);
		r=new BiNode<table>(spliting_point);
		r->left->father=r;
		r->right->father=r;
		r->left=Classification_Tree(r->left,*subspace);
		r->right=Classification_Tree(r->right,*(subspace+1));
	}
	else if(r==NULL&&subtable!=NULL&&!terminate(*subtable,1)){
		subspace=split(*subtable,Y);
		r=new BiNode<table>(spliting_point);
		r->left->father=r;
		r->right->father=r;
		r->left=Classification_Tree(r->left,*subspace);
		r->right=Classfication_Tree(r->right,*(subspace+1));
	}
	r=prunning(r);
	return r;
}
template<class table>
table* DecisionTree<table>::Least_Square(table space,int Y){
	table* subspace;
	spliting_point.clear();
	pair<int,int> point;
	double var,var_1,var_2;
	double Min=INF;
	for(int i=0;i<space.num();i++){
		for(int s=0;s<space.dim();s++){
			subspace=new table[2];
			subspace=space.split(i,s);
			var_1=subspace[0].var(Y);
			var_2=subspace[1].var(Y);
			var=var_1+var_2;
			if(var<Min){
				Min=var;
				point=pair<int,int>(i,s);
			}
		}
	}
	tag=get<1>(point);
	spliting_point.push((*this)(get<0>(point),get<1>(point)));
	return subspace;
}
template<class table>
bool DecisionTree<table>::terminate(table& subspace,int selection){
	if(selection==0){
		
	}
}
template<class T>
void DecisionTree<T>::prunning(int selection){
	typedef pair<int,double> elem;
	BiNode<elem>* p=r;
	BiNode<elem>* q;
	while(p!=NULL){
		if(selection==0){
		    pruning(p->left);
		    pruning(p->right);
			pruning(p);
		}
		
	}
	q=p->father;
	if(selection==0){
		
	}
}

#include "Prunning.h"

#endif

