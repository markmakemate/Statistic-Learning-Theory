#include<iostream>
#include<cstdlib>
using namespace std;
template<class table>
struct BiNode {
	table data;    //data, a table object with one row and k columns
	table split_point;   //split point, a table object with single element
	Biode<table>* left;    //left child pointer
	BSTreeNode<table>* right;    //right child pointer
	BSTreeNode<table>* father;   //father pointer
	int depth;    //node's depth
	BSTreeNode(table x,table point,int d) :data(x), split_point(point),depth(d),left(NULL), right(NULL){}
};   //Declaration  of Binary search tree node
