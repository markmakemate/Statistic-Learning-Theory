#include<iostream>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<vector>
//This is the code implements of kd tree
//kd tree is applied to search k-nearest neighbor points in an efficient way
using namespace std;
template<class Elemtype>
struct BSTreeNode {
	Elemtype data;
	BSTreeNode<Elemtype>* left;
	BSTreeNode<Elemtype>* right;
	BSTreeNode<Elemtype>* father;
	int depth;
	BSTreeNode(Elemtype x,int d) :data(x), depth(d),left(NULL), right(NULL){}
};   //Declaration  of Binary search tree node

class kd_Tree {
	typedef BSTreeNode<vector<double> >* node;
private:
	int Num_of_Samples;
	int Dimension;
public:
	kd_Tree();
	kd_Tree(int N, int k);
	node Generator(vector<double>* Input,int spliting_point=0,int depth=0,node T=NULL);
	vector<double>* QuickSort(vector<double>* Input, int spliting_point,int begin=0,int end=1);
	int Partition(vector<double>* Input, int spliting_point, int begin = 0,int end=1);
	vector<double> kd_Searching(node T, vector<double> searching_point);
	vector<double>* Swap(vector<double>* Input, int p1, int p2);
	node getLeaf(node T,vector<double> searching_point);
};

kd_Tree::kd_Tree(){
	Num_of_Samples=0;
	Dimension=0;
}
kd_Tree::kd_Tree(int N,int k){
	Num_of_Samples=N;
	Dimension=k;
}

BSTreeNode<vector<double> >* kd_Tree::Generator(vector<double>* Input, int spliting_point, int depth,BSTreeNode<vector<double> >* T) {
	typedef BSTreeNode<vector<double> > node;
	typedef vector<double>* Set;
	Set* subsets = new Set[2];
	*subsets = new vector<double>[Num_of_Samples / 2];
	*(subsets + 1) = new vector<double>[Num_of_Samples / 2];
	Input = QuickSort(Input, spliting_point,0,Num_of_Samples);
	if (T == NULL) {
		T =new node( *(Input + Num_of_Samples / 2 - 1),depth);
	}
	else {
		for (int i = 0; i < Num_of_Samples / 2; i++) {
			*(subsets + i)[0] = *(Input + i);
			*(subsets + i)[1] = *(Input + i + Num_of_Samples / 2);
		}
		T->left->father = T;
		T->right->father = T;
		spliting_point = depth % Dimension;
		depth++;
		T->left = Generator(subsets[0], spliting_point, depth,T->left);
		T->right = Generator(subsets[1], spliting_point, depth,T->right);
	}
	T->father = NULL;
	return T;
}
vector<double>* kd_Tree::QuickSort(vector<double>* Input, int spliting_point,int begin,int end) {
	int p = Partition(Input, spliting_point,begin,end);
	if (begin < end) {
		Input = QuickSort(Input, spliting_point, begin, p - 1);
		Input = QuickSort(Input, spliting_point, p + 1, end);
	}
	return Input;
}
int kd_Tree::Partition(vector<double>* Input, int spliting_point, int begin, int end) {
	vector<double> x = *(Input + end);
	int p = begin - 1;
	for (int i = begin; i < end; i++) {
		if ((*(Input + i)).at(spliting_point) < x.at(spliting_point)) {
			p++;
			Input=Swap(Input, i, p);
		}
	}
	p++;
	Swap(Input, p, end);
	return p;
}
vector<double>* kd_Tree::Swap(vector<double>* Input, int p1, int p2) {
	vector<double> Temp;
	Temp = *(Input + p1);
	*(Input + p1) = *(Input + p2);
	*(Input + p2) = Temp;
	return Input;
}
vector<double> kd_Tree::kd_Searching(BSTreeNode<vector<double> >* Tree, vector<double> searching_point) {
	typedef BSTreeNode<vector<double> >* node;
	typedef vector<double> Set;
	vector<double>::iterator it;
	int depth_1,depth_2,point_1,point_2;
	double distance_1,distance_2;
	node leaf;
	vector<double> result;
	leaf=getLeaf(Tree,searching_point);
	while(leaf!=Tree){
		it=(leaf->data).begin();
		depth_1=leaf->depth;
		point_1=depth_1%Dimension;
		depth_2=leaf->father->depth;
		point_2=depth_2%Dimension;
		distance_1=abs(*(it+point_1)-searching_point.at(point_1));
		distance_2=abs(*(it+point_2)-searching_point.at(point_2));
		if(distance_1>distance_2){
			leaf=leaf->father;
		}
		else{
			result=kd_Searching(leaf->father,searching_point);
		}
	}
	result=leaf->data;
	return result;
}
BSTreeNode<vector<double> >* kd_Tree::getLeaf(BSTreeNode<vector<double> >* Tree,vector<double> searching_point){
	typedef BSTreeNode<vector<double> >* node;
	int depth,point;
	node leaf=Tree;
	vector<double>::iterator it;
	while(leaf!=NULL){
		it=(leaf->data).begin();
		depth=leaf->depth;
		point=depth%Dimension;
		if(*(it+point)<searching_point.at(point)){
			leaf=leaf->left;
		}
		else{
			leaf=leaf->right;
		}
	}
	return leaf;
}