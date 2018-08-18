#ifndef DECISIONTREE_H
#define DECISIONTREE_H
#include<vector>
#include<iostream>
#include<cstdlib>
#include"Eigen/Eigen/Dense"
#include<stack>
//A head file including the code implement of ID3, C4.5 and CART algorithms
//Assuming that the input data has been pre-processed. 
using namespace std;
using namespace Eigen;
template<class Elemtype>
struct TreeNode{
    Elemtype data;
	int Tag;
    TreeNode<Elemtype>* left;
    TreeNode<Elemtype>* right;
    TreeNode<Elemtype>* father;
    TreeNode(Elemtype x,int sign):data(x),Tag(sign),left(NULL),right(NULL),father(NULL){}
};

class DecisionTree{
    typedef TreeNode<MatrixXd>* node;
private:
	node root;
public:
    DecisionTree();
    node ID3(vector<VectorXd> __Input,vector<MatrixXd> __Input_in_Class,vector<Vector2i> __Property, node T = NULL,double valve=0.1);
    node C4.5(MatrixXd __Input,node T=NULL);
    node CART(MatrixXd __Input,int selection, node T = NULL);
    double Gini();
    double Entropy(int* Class,int Set_num);
    double* Conditional_Entropy(int* Class_num, int* SubSet_num, int Set_num);
    double* Info_Gain(double Entropy,double* Conditional_Entropy);
	int Find_biggest_capacity(vector<MatrixXd> __P__);
	int* getSubSetNum(vector<VectorXd> __Input, vector<Vector2i> __Property);
	double max(double* Info_Gain);
	int getMax(double* Infor_Gain);
	stack<MatrixXd> Division(vector<VectorXd> __Input, vector<Vector2i> __Property);
	vector<VectorXd> Transform(MatrixXd SubNode);
};

DecisionTree::DecisionTree() {
	root = NULL;
}

//__Input data have been pre-processed which satisfies:
//[1] Every elements of vector are arranged as the index of samples;
//[2] Every VectorXd's elements are sorted as properties' index;
//[3] The last element of each VectoXd represents the class of sample.
//Input_in_class has been pre-processed so that the samples belong to each class have been stored in a MatrixXd.
TreeNode<MatrixXd>* DecisionTree::ID3(vector<VectorXd> __Input,vector<MatrixXd> Input_in_Class,vector<Vector2i> __Property,TreeNode<MatrixXd>* T,int valve) {
	typedef TreeNode<MatrixXd> node;
	int* class_num = new int[Input_in_Class.size()];  
	//Capacity of each class. 
	int Set_num = __Input.size();
	//Number o data sets;
	int* SubSet_num = getSubSetNum(__Input,__Property);
	//Number of each subset
	stack<MatrixXd> SubNode;
	//Sub nodes container
	for (int i = 0; i < Input_in_Class.size(); i++) {
		*(class_num + i) = Input_in_Class.at(i).cols;
	}//Calculate each class's  capacity.
	if (Input_in_Class.size() == 1) {
		T = new node(Input_in_Class.at(0),(Input_in_Class.at(0))(Input_in_Class.at(0).cols(),0));
	}
	else if(__Property.size()==0){
		int tag = Find_biggest_capacity(Input_in_Class);
		T = new node(Input_in_Class.at(tag), tag);
	}
	else {
		if (max(Info_Gain(Entropy(class_num, Set_num), Conditional_Entropy(class_num, SubSet_num, Set_num)))<valve) {
			int tag = Find_biggest_capacity(Input_in_Class);
			T = new node(Input_in_Class.at(tag), tag);
		}
		else {
			double* info_gain = Info_Gain(Entropy(class_num, Set_num), Conditional_Entropy(class_num, SubSet_num, Set_num));
			SubNode = Division(__Input, __Property);
			 __Property.erase(__Property.begin() + getMax(info_gain));
			T->left = ID3(Transform(SubNode.top()), Input_in_Class, __Property, T->left, valve);
			SubNode.pop();
			T->right = ID3();
		}
	}
	return T;
}

TreeNode<MatrixXd>* DecisionTree::CART()
