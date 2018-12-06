#include "./TreeNode.h"
#include "DecisionTree.h"
using namespace std;
template<class table>
class Pruning::public DecisionTree<table>{
    typedef pair<int,double> elem
private:
    double loss;
public:
    void pruning(BiNode<elem>* r=NULL){
        BiNode<elem>* p=r;
        BiNode<elem>* q;
        while(p!=NULL){
            pruning(p->left);
            pruning(p->right);
            pruning(p);
        }
        q=p->father;
        
        
    }
    	//selection=0:Biclass classification/regression
	//selection=1:Multi-class
    double g(BiNode<elem>* node){
        return (C(*node)-C(node))/(node->count()-1);
    }
    double C(BiNode<elem> node){
        return node.loss;
    }
    double C(BiNode<elem>* node){
        node.loss=loss_function(get<0>(node.point),get<1>(node.point));
        node.loss_all=(node.left)->loss_all+(node.right)->loss_all;
        return node.loss_all;
    }
    double loss_function(int attribute,double value){

    }
};