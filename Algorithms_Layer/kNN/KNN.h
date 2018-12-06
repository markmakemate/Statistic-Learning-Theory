#include<iostream>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<vector>
#include "BiNode.h"
#include "../lib/Sign.h"
#define INF 1.78e+307
//This is the code implements of kd tree
//kd tree is applied to search k-nearest neighbor points in an efficient way
using namespace std;
template<class table>
double distance(table a,table b,int lp){
	table c;
	int dim;
	double result=INF;
	if(a.dim()==b.dim()){
		c=a-b;
		dim=a.dim();
		for(int i=0;i<dim;i++){
			result+=abs(pow((a(0,i)-b(0,i),lp)));
		}
		result=pow(result,1/lp);
	}
	else{
		throw "dimension error";
	}
	return result;

}
template<class table>
class kd_Tree {
	typedef BiNode<table>* node;
private:
	table Data;   //Data Set
	table spliting_point;   //split point
	static node root;   //root of kd-tree
	table nearest;   //nearest point
	double nearest_distance //nearest distance
	queue<table> nearests //nearest points
public:
    kd_Tree(){}
	kd_Tree(table& Input);
	void load(table& Input);
	node training(node r=NULL,table* subtable=NULL,int depth=0);
	void searching(node r=root,table& point);
	int operator(queue<node> points);
};
template<class table>
kd_Tree<table>::root=NULL;
template<class table>
kd_Tree::kd_Tree(table& Input){
	Data=Input;
	nearest_distance=INF;
}
template<class table>
void kd_Tree<table>::load(table& Input){
	Data=Input;
}

//training a kd tree
template<class table>
BiNode<table>* kd_Tree<table>::training(BiNode<table>* r,table* subtable,int depth){
	spliting_point.clear();
	table* subspace;
	if(r==NULL&& subtable==NULL){
		int dim=Data.dim();
	    int N=Data.num();
		Data.QuickSort(depth%(dim-1));    //Sort Data based on depth mod (dim-1) attributes
		spliting_point.push(Data(N/2,depth%(dim-1)));   //create the split point
		r=new BiNode<table>(Data[N/2],spliting_point,depth);
		r->left->father=r;   //set father node of r->left
		r->right->father=r;  //set father node of r->right
		subspace=Data.split(N/2,depth%(dim-1));   //split Data into two tables based on Data(N/2, (depth mode dim-1))
		r->right=training(r->right,&(subspace[1]),depth++);   //recursively training r->right
		r->left=training(r->left,&(subspace[0]),depth++);   //recursively training r->left
	}
	//The progress is as above, however, Data is replaced by subtable
	//cirumstance of subtable!=NULL
	else if(r==NULL&&subtable!=NULL){
		subtable->QuickSort(depth%(dim-1));
		int dim=subtable->dim();
		int N=subtable->num();
		spliting_point.push((*subtable)(N/2,depth%(dim-1)));
		r=new BiNode<table>((*subtable)[N/2],spliting_point,depth);
		r->left->father=r;
		r->right->father=r;
		subspace =subtable->split(N/2,depth%(dim-1));
		r->left=training(r->left,subspace,depth++);
		r->right=training(r->right,subspace+1,depth++);
	}
	else if(r!=NULL&&subtable==NULL){
		BiNode<table>* p=r;
		int dim=Data.dim();
	    int N=Data.num();
		while(p!=NULL){
			Data.QuickSort(depth%(dim-1));
			spliting_point.push(Data(N/2,depth%(dim-1)));
			if(spliting_point(0,0)<(p->data)(0,0)){
				p=p->left;
			}
			else{
				p=p->right;
			}
			depth++;
		}
		p=new BiNode<table>(Data[N/2]spliting_point,depth);
		p->left->father=p;
		p->right->father=p;
		subspace=Data.split(N/2,depth%(dim-1));
		p->left=training(p->left,subspace,depth++);
		p->right=training(p->right,subspace+1,depth++);
	}
	else if(r!=NULL&& subtable!=NULL){
		BiNode<table>* p=r;
		int dim=subtable->dim();
	    int N=subtable->num();
		while(p!=NULL){
			subtable->QuickSort(depth%(dim-1));
			spliting_point.push((*subtable)(N/2,depth%(dim-1)));
			if(spliting_point(0,0)<(p->data)(0,0)){
				p=p->left;
			}
			else{
				p=p->right;
			}
			depth++;
		}
		p=new BiNode<table>((*subtable)[N/2],spliting_point,depth);
		p->left->father=p;
		p->right->father=p;
		subspace=subtable->split(N/2,depth%(dim-1));
		p->left=training(p->left,subspace,depth++);
		p->right=training(p->right,subspace+1,depth++);
	}
	return r;
}

//search in kd tree with a point
template<class table>
void kd_Tree<table>::searching(BiNode<table>* r,table& node){
	BiNode<table>* p=r;
	BiNode<table>* q=NULL;
	BiNode<table>* t=NULL;
	while(p!=NULL){
		if(p->split_point(0,0)>node(0,p->depth%(node.dim()-1))){
			p=p->left;
		}
		else{
			p=p->right;
		}
	}
	p=p->father;
	double d=distance(p->data,node);
	if(d<nearest_distance){
		nearest_distance=d;
	}
	q=p->father;
	if(q->left==p&&q!=root){
		t=q->right;
		d=distance(t->data,node);
		if(d<nearest_distance){
			nearest_distance=d;
			nearests.clear();
			nearests.push(t->data);
			searching(t,node);
		}
		else if(d==nearest_distance){
			nearests.push(t->data);
			searching(t,node);
		}
		else{
			t=t->father;
			searching(t,node);
		}
	}
}