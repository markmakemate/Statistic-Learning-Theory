# Statistic-Learning-Theory
##This project is the code implement of AI algorithms:

#Introduction of the project:

##1. kNN Algorithm
* kd Tree
* Stroage Model: template<class Elemtype> struct TreeNode{}
##2. Decision Tree
* Storage Model: map<string,double>* as Table
* Store subspace: map<vector<double>,Table*>
* The progress of Least Square:
 Calculating the sum of elements in Y \n
 Searching least square starting from j=1 \n
 Traversal j=2,3,....,N \n
 Complexity: O(N^2) \n
 Solving least square by dynamic programming \n
* Gini Index:
 Counting classes' capacity by partition strategy \n
 Complexity of counting: O(N) \n
 Store classfication: map<property,count> \n
 Complexity of calculating Complexity of Gini: O(kN), k is the dimension \n
* Prunning:
 Postorder Traversal to calculate Gini and loss function for every node \n
 Postorder Traversal searching and prunning \n
