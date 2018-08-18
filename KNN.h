#include<iostream>
#include<cstdlib>
#include<queue>
#include<cmath>
#include"Eigen/Eigen/Dense"
//This is the code implements of kd tree
//kd tree is applied to search k-nearest neighbor points in an effective way
using namespace Eigen;
using namespace std;
template<class Elemtype>
struct BSTreeNode {
	Elemtype data;
	BSTreeNode* left;
	BSTreeNode* right;
	BSTreeNode(Elemtype x) :data(x), left(NULL), right(NULL) {}
};   //Declaration  of Binary search tree node

class kd_Tree {
	typedef BSTreeNode<VectorXd>* node;
private:
	int Num_of_Samples;
	int Dimension;
public:
	kd_Tree();
	kd_Tree(int N, int k);
	node Build_kd_Tree(node __Tree__,MatrixXd __TrainingDataSet__,int end,int begin=0,int depth=1);
	queue<VectorXd> KNN_Searching(VectorXd __ObjectivePoint__, node __kdTree__=NULL);
	node Insertion(node T,VectorXd __Median__,int __Criterian__);
	MatrixXd QuickSort(MatrixXd __Set__,int __Criterian__,int __begin__,int __end__);
	int Partition(MatrixXd __Set__,int __Criterian,int __begin__,int __end__);
	MatrixXd Swap(MatrixXd __Set__,int p1,int p2);
};

kd_Tree::kd_Tree(){
	Num_of_Samples=0;
	Dimension=0;
}
kd_Tree::kd_Tree(int N,int k){
	Num_of_Samples=N;
	Dimension=k;
}

BSTreeNode<VectorXd >* kd_Tree::Build_kd_Tree(BSTreeNode<VectorXd >* T,MatrixXd __TrainingDataSet__,int end,int begin,int depth){
	Dimension=(__TrainingDataSet__).rows();
	Num_of_Samples=(__TrainingDataSet__).cols();
	__TrainingDataSet__=QuickSort(__TrainingDataSet__,depth%Dimension,begin,end);
	int median_p=ceil((end+begin)/2)-1;
	VectorXd median(Dimension);
	for(int i=0;i<Dimension;i++){
		median(i)=(__TrainingDataSet__)(i,median_p);
	}
	if(median_p!=0){
		T=Insertion(T,median,depth%Dimension);
	    T->left=Build_kd_Tree(T->left,__TrainingDataSet__,median_p-1,begin=0,depth+=1);
	    T->right=Build_kd_Tree(T->right,__TrainingDataSet__,Num_of_Samples-1,begin=median_p+1,depth+=1);
	}
	return T;
}

BSTreeNode<VectorXd>* kd_Tree::Insertion(BSTreeNode<VectorXd>* r,VectorXd __Median__,int __Criterian__){
	if(r==NULL){
		r=new BSTreeNode<VectorXd>(__Median__);
	}
	else if(__Median__(__Criterian__)<r->data(__Criterian__)){
		r->left=Insertion(r->left,__Median__,__Criterian__);
	}
	else{
		r->right=Insertion(r->right,__Median__,__Criterian__);
	}
	return r;
}

queue<VectorXd> kd_Tree::KNN_Searching(VectorXd __ObjectivePoint__,node __kdTree__){

}
MatrixXd kd_Tree::QuickSort(MatrixXd __Set__,int __Criterian__,int __begin__,int __end__){
	int Position=Partition(__Set__,__Criterian__,__begin__,__end__);
	if(__begin__!=__end__){
		__Set__=QuickSort(__Set__,__Criterian__,__begin__,Position-1);
	    __Set__=QuickSort(__Set__,__Criterian__,Position+1,__end__);
	}
	return __Set__;
}

int kd_Tree::Partition(MatrixXd __Set__, int __Criterion__, int __begin__, int __end__) {
	double x = __Set__(__Criterion__, __end__);
	int position = __begin__ - 1;
	for (int i = __begin__; i < __end__ - 1;i++) {
		if (__Set__(__Criterion__, i) <= x) {
			position++;
			__Set__=Swap(__Set__, position, i);
		}
	}
	__Set__ = Swap(__Set__, position + 1, __end__);
	return position;
}
MatrixXd kd_Tree::Swap(MatrixXd __Set__, int p1, int p2) {
	int row = __Set__.rows();
	VectorXd temp = __Set__.block(0, p1,row,1);
	for (int i = 0; i < __Set__.rows(); i++) {
		__Set__(i, p1) = __Set__(i, p2);
		__Set__(i, p2) = temp(i);
	}
	return __Set__;
}