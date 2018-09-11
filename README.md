# Statistic-Learning-Theory
## This project is the code implement of AI algorithms

# Contents

## 1. kNN Algorithm
* kd Tree
* Stroage Model: template<class Elemtype> struct TreeNode{}
 
## 2. Decision Tree
* Storage Model: map<string,double>* as Table
* Store subspace: map<vector<double>,Table*>
* The progress of Least Square:
 Calculating the sum of elements in Y;
 Searching least square starting from j=1;
 Traversal j=2,3,....,N;
 Complexity: O(N^2);
 Solving least square by dynamic programming
* Gini Index:
 Counting classes' capacity by partition strategy;
 Complexity of counting: O(N);
 Store classfication: map<property,count>;
 Complexity of calculating Complexity of Gini: O(kN), k is the dimension
* Prunning:
 Postorder Traversal to calculate Gini and loss function for every node;
 leaf nodes will be stored in a queue;
 Postorder Traversal searching and prunning from leaf nodes;
 * CART Algorithm Complexity: O(kN+logN) for big data: O(N+logN);
 
## 3. Max Entropy and Logestic Regression
* IIS Algorithm
* BFGS Algorithm
* DFP Algorithm

## 4. SVM Algorithm
* SMO Algorithm
* Using Generic Algorithm for SVM
* Using Particle Swarm Optimization for SVM
* Using Simulated Annealing Algorithm for SVM

## 5. AdaBoost
* Boosting Tree

## 6. Random Forest
* N CART Trees

## 7.EM Algorithm
* GMM(Gaussian Mixture Model)
* GEM(Generalized EM Algorithm)

## 8. HMM(Hidden Markov Model)
* Propability Calculation Algorithm(forward+backward)
* Learning Algorithm(Baum-Welch)
* Forecasting Algorithm(Approximation Algorithm, Viterbi Algorithm)

## 9. CRF(Conditional Random Field)
* Probability Calculation Algorithm(forward+backward)
* Learning Algorithm(IIS+BFGS)
* Forecasting Algorithm(Viterbi Algorithm)

# Introduction to ML Algorithms
## Chapter 1 kNN
### 1. Basic Theory
