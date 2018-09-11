#ifndef DECISIONTREE_H
#define DECISIONTREE_H
#include<vector>
#include<iostream>
#include<cstdlib>
#include<stack>
#include<map>
#include<cmath>
//A head file including the code implement of ID3, C4.5 and CART algorithms
//Assuming that the input data has been pre-processed. 
//Input data have been pre-processed through data cleaning, data integration and data transformating.
using namespace std;
template<class Elemtype>
struct TreeNode{
    Elemtype data;
	double gini;
	string Tag;
    TreeNode<Elemtype>* left;
    TreeNode<Elemtype>* right;
    TreeNode<Elemtype>* father;
    TreeNode(Elemtype x,double g):data(x),Tag(sign),left(NULL),right(NULL),father(NULL),gini(g),Tag("UNVISITED"){}
};
class TableProcessor{
	typedef map<string, double>* Table;
	typedef map<string, double> property;
	typedef int end_position;
protected:
	map<property,end_position> Partitioner(Table __Input,int dimension);
	map<property,Table*> Classifier(Table __Input, map<string,double> gini);
	void swap(Table __Input,int p1,int p2);
	Table* QuickSort(Table __Input,int dimension,double criterion,int begin=0,int end=1);
	int Partition(Table __Input,int dimension,int begin,int end);
};
class DecisionTree:protected TableProcessor{
	typedef map<string, double>* Table
	typedef TreeNode<map<string,double> >* node;
	typedef map<string, double> property;
private:
	node root;
	int sample_num;
protected:
    DecisionTree(int Sample_num);
	map<property,double> Gini(Table _Input);
	double Entropy(Table __Input);
	node Regression_Tree(Table __Input,node T = NULL,double valve=0.1);
	node Classification_Tree(Table __Input,node T = NULL, double valve = 0.1)
	map<property, Table*> Least_Square(Table __Input);
	double Conditional_Entropy(Table __Input,string property);
	double Info_Gain(Table __Input);
public:
    DecisionTree(int Sample_num);
    node ID3(Table __Input,node T = NULL,double valve=0.1);
    node C4.5(Table __Input,node T=NULL,double valve=0.1);
    node CART(Table __Input,int selection, node T = NULL,double valve=0.1);
};

DecisionTree::DecisionTree(int Sample_num) {
	root = NULL;
	sample_num = Sample_num;
}

//selection=0: Regression Tree
//selection==1: Classification Tree
TreeNode<map<string, double> >* DecisionTree::CART(map<string, double>* __Input, int selection, TreeNode<map<string, double> >* T,double valve) {
	if (selection == 0) {
		if(spliting_criterion.cols()==2){
			return Regression(__Input, T, valve);
		}
		else {
			throw "Please enter the right spliting criterion(for regression tree)!";
		}
	}
	else {
		if(spliting_criterion.cols()==1){
			return Classification(__Input, T, valve);
		}
		else {
			throw "Please enter the right spliting criterion (for classfication tree)!";
		}
	}
}
TreeNode<map<string, double> >* DecisionTree::Regression_Tree(map<string, double>* __Input, TreeNode<map<string, double> >* T,double valve) {
	typedef TreeNode<map<string, double> >* node;
	typedef TreeNode<map<string, double> > Node;
	typedef map<string,double>* Table;
	typedef map<string, double> property;
	property::iterator it;
	Table* Subspace;
	Table R1;
	Table R2;
	map<property,double> gini;
	gini=Gini(__Input);
	map<property,Table*> LS;
	it=Least_Square(__Input).begin();
	Subspace=it->second;
	R1=Subspace[0];
	R2=Subspace[1];
	if(T==NULL){
		T=new Node(it->first,gini.begin()->second);
	}
	if((gini.begin()->second)>valve){
		T->left=Regression_Tree(R1,T->left,valve);
		T->right=Regression_Tree(R2,T->right,valve);
	}
	return T;
}
TreeNode<map<string, double> >* DecisionTree::Classification_Tree(map<string, double>* __Input, TreeNode<map<string, double> >* T, double valve) {
	typedef TreeNode<map<string, double> >* node;
	typedef TreeNode<map<string, double> > Node;
	typedef map<string,double> value;
	typedef map<string,double>* Table;
	Table* Subspace;
	Table R1;
	Table R2;
	value gini;
	gini=Gini(__Input);
	value LS;
	LS=this->Classifier(__Input,gini);
	Subspace=LS.begin().second;
	R1=Subspace[0];
	R2=Subspace[1];
	if(T==NULL){
		T=new Node(LS.begin().first,gini.begin().second);
	}
	if(gini.begin().second>valve){
		T->left=Classification_Tree(R1,T->left,valve);
		T->right=Classification_Tree(R2,T->right,valve);
	}
	return T;
}

map<map<string,double>,map<string,double>**> DecisionTree::Least_Square(map<string, double>* __Input){
	typedef map<string, double>* Table;
	typedef map<string,double> value;
	map<string,double>::iterator it;
	map<value,Table*> result;
	Table* subspace=NULL;
	Table R1;
	Table R2;
	double min=10;
	double x,sum;
	int dimension=(*(__Input)).size();
	int length=sizeof(__Input)/sizeof(*(__Input));
	for(int i=0;i<dimension;i++){
		for(int j=0;j<sample_num;j++){
			it=(*(__Input+j)).begin();
			x=(*(it+i)).second;
			subspace=this->QuickSort(__Input,dimenson,x);
			R1=subspace[0];
			R2=subspace[1];
			sum=sum(subspace);
			if(sum<min){
				min=sum;
				result.clear();
				result.insert(make_pair((*(it+i)).first,x));
			}
		}
	}
	return result;
}

map<map<string,double>,double> DecisionTree::Gini(map<string,double>* __Input){
	typedef map<string,double> value;
	typedef map<value,double> container;
	typedef map<value,int> classified;
	classified space;
	container result;
	int length=sizeof(__Input)/sizeof(*(__Input));
	int dimension=(*(__Input)).size();
	for(int i=0;i<length;i++){
		for(int j=0;j<dimension;j++){

		}
	}
	
}
map<map<string,double>,int> TableProcessor::Partitioner(map<string,double>* __Input,int dimension){
	typedef map<string,double> value;
	value::iterator it;
	value::iterator candidate;
	int position=1;
	value result;
	double x;
	length=sizeof(__Input)/sizeof(*(__Input));
	while(position<length){
		it=(*(__Input+position-1)).begin();
	    x=(*(it+dimension)).second;
		for(int j=position;j<length;j++){
			candidate=(*(__Input+j)).begin();
			if(candidate->second==x){
				swap(__Input,position,j);
				position++;
			}
		}
		result.insert(make_pair(*(__Input+position),position));
		position++;
	}
	return result;
}

void TableProcessor::swap(map<string,double>* __Input,int p1,int p2){
	typedef map<string,double> value;
	value temp;
	temp=*(__Input+p1);
	*(__Input+p1)=*(Input+p2);
	*(__Input+p2)=temp;
	delete temp;
}

map<string, double>** TableProcessor::QuickSort(map<string, double>* __Input,int dimension,double criterion,int begin,int end){
	int q=0;
	end=sizeof(__Input)/sizeof(*(__Input))-1;
	map<string, double>* result[2]=new map<string,double>(end+1);
	if(begin<end){
		int p=this->Partition(__Input,int dimension,double criterion,begin,end);
	    __Input=QuickSort(__Input,criterion,criterion, begin, p-1);
	    __Input=QuickSort(__Input,dimension,criterion, begin, p+1);
	}
	for(int i=0;i<end+1;i++){
		if(*(__Input+i)<=criterion){
			result[i][1]=*(__Input+i);
			q++;
		}
		else{
			result[i-q][2]=*(__Input+i);
		}
	}
	return result;
}

int TableProcessor::Partition(map<string, double>* __Input,int dimension,int begin,int end){
	typedef map<string,double> value;
	int length=sizeof(__Input)/sizeof(*__Input);
	value::iterator it;
	value::iterator candidate;
	it=(*(__Input+end)).begin();
	double x=(*(it+dimension)).second;
	int p=begin-1;
	for(int i=0;i<end;i++){
		candidate=(*(__Input+i)).begin();
		if((*(candidate+dimension)).second<x){
			p++;
			this->swap(__Input,i,p);
		}
	}
	this->swap(__Input,p+1,end);
	return p++;
}



#endif

