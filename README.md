# Statistic-Learning-Theory
Statistic Learning Theory Code Implement
Introduction
1. kNN Algorithm
* kd Tree
* Stroage Model: template<class Elemtype> struct TreeNode{}
2. Decision Tree
* Storage Model: map<string,double>* as Table
* Store subspace: map<vector<double>,Table*>
* The progress of Least Square:
(1) Calculating the sum of elements in Y
(2) Searching least square starting from j=1
(3) Traversal j=2,3,....,N
(4) Complexity: O(N^2)
(5) Solving least square by dynamic programming
* Gini Index:
(1) Counting classes' capacity by partition strategy
(2) Complexity of counting: O(N)
(3) Store classfication: map<property,count>
(4) Complexity of calculating Complexity of Gini: O(kN), k is the dimension
* Prunning:
(1) Postorder Traversal to calculate Gini and loss function for every node
(2) Postorder Traversal searching and prunning
