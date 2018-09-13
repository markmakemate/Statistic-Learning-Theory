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

# Discussion
## 1. SVM Algorithm  with Generic Algorithm
### (1) Generic Algorithm
Generic Algorithm is a type of heuristic algorithm aiming to find an approximate optimal solution. The main features is:
* Operating structural objects directly without the limitation of derivative and continuity
* Hidden parallelity and better global searching ability
* Searching optimal point with probability method, obtaing searching direction without any given rule automatically<br/>
<br/>The main progress is:
* Generating species(samples) randomly
* Calculating fitness function/objective function and discriminating if the optimal criterion is satisfied. 
* Selecting parents(two samples) which own the highest fitness value, then eliminating the lowest ones. 
* Crossover(binary encode/float encode/character encode/generic programming method)
* Mutation<br/>
### (2) SVM implemented by GA
Essentially, SVM is to solve a constraint quadratic convex optimization. So, we merely extend GA to search a optimum point with constraint conditions. <br/>
However, the optimum solution may fail to be found. We should replace it by an approximate one. 
### (3) Extension to another evolutionary algorithms
PAA and SAA are all algorithms searching for the optimum point like GA.

## 2. 
