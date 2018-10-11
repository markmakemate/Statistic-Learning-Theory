# Statistic-Learning-Theory
## This project will integrates AI algorithms, Big Data platform and application
* AI Algorithms: C++
* Big Data platform: Java
* Application Layer: Python
## Objective: 
* Create an effective Artificial Intelligence application system for most conditions
* Framework is as simple as possible
* Extensionability should be satisfied
* **Feature enginneering and data preprocess are not took into account.**
## Features:
* **Implementing without any Third-party Library, only STL imported**
* **Some Algorithms optimized for better performance**
* **Create a DLL so that Python can import**
* **Extensionability**: Parallel/Distributed Calculation
* **Database system supported**: Key-Value, relation DB, distributed DB
* **Implement Linear Algebra(Table, Raw, Column)Class in C++**
* **Three layers divided: Application Layer, Data Layer, Algorithm Layer**
## References:
1. *Statistic Learning Method*, Hang Li, Tsinghua University Press<br/>
2. *Pattern Classification*, Richard Duda<br/>
3. *Introduction to data mining*, <br/>
4. *C++ Refrences*<br/>
5. *C++ Primer Plus*,Stephen Prata,2015<br/>
6. *The Annotated STL Sources(using SGI STL)*,Jie Hou, HUST Press.<br/>
7. *Design Patterns: Elements of Reusable Object-Oriented Software*,Erich Gamma & Richard Helm &  Ralph Johnson, China Mechine Press,2007
## Design Patterns: 
1. Construct pattern<br/>
2. Fatory pattern<br/>
3. iterator<br/>
4. decorator<br/> 
5. MVC<br/>
## Framework:
1. Data I/O: <br/>
![image](https://github.com/markmakemate/Statistic-Learning-Theory/blob/master/Framework.png)
2. Classifiers' Collection: <br/>
![image](https://github.com/markmakemate/Statistic-Learning-Theory/blob/master/Classifiers'_collection.png)
3. Framework of software: <br/>
![image](https://github.com/markmakemate/Statistic-Learning-Theory/blob/master/MVC.png)
5. The whole framework: <br/>
![image](https://github.com/markmakemate/Statistic-Learning-Theory/blob/master/Framework_1.png)

## Tips:
1. We assume that the input data have been **preprocessed**(*cleaning, transformation, reduction, integration*) <br/>
2. **Feature enginneering is not considered in**.<br/>
3. Table class is a data container which represents a data table in an abstract way<br/>
4. Collection class is a set contains many Table objects which have been labeled<br/>
5. DataSet class is a set contains many Collections object which a Classifier object use directly.It provides a container with labeled Collection objects<br/>
6. DataLoader class which can load DataSet object for parallel/distributed/multithread calculation or distributed store.<br/>
7. Classifier object can only use DataSet object for its training data.<br/>
# Data Processors:
## 1. Table
Table represents a data set in an abstract way<br/>
Two kinds Table: raw-oriented Table, column-oriented Table(transposition of raw-oriented Table)<br/>
Two kinds of units: Raw, Column<br/>
**Template design pattern**
(1) Raw-Oriented Table<br/>
Raw-Oriented Table is Table's subclass whose storage units are samples;<br/>
Class name: Table_Raw<br/>
Some methods are implemented to operate a Table_Raw object:<br/>
* Constructor: initialize a Table_Raw object(Override it which can load a input data set)
* build: build a Table_Raw object(Input format: map<index,Raw>)
* push: insert a Raw object
* pop: delete a Raw unit
* Override []: return a Raw object for a fixed index of sample
* dimension: return the dimension of each sample
* num: return the number of samples
(2) Column-Oriented Table<br/>
Column-Oriented Table is Table's subclass whose storage units are character instead of samples;<br/>
Class name: Table_Column<br/>
Some methods are to operate a Table_Column object:<br/>
* Constructor: initialize a Table_Column object(Override it which can load a input data set)
* build: build a Table_Column object(Input format: map<index,Column>)
* push: insert a Column object
* pop: delete a Column unit
* Override []: return a Column object for a fixed character
* dimension: return the dimension of each sample
* num: return the number of samples
* Gini: return Gini index of a fixed character
* Entropy: return information entropy of a fixed character
* Conditional Entropy: return all conditional entropy of two fixed characters
* Info_Gain: return all information gain of two fixed characters
* QuickSort: Sort the Table_Column object's raw as Quick Sort Algorithm
* Partition: Partition method for Quick sort
(3) Table<br/>
Table is an abstract container to store a data set;<br/>
Table provides interfaces implemented in Table_Raw and Table_Column respectedly.<br/>
User only construct a Table object then call API. Program will automatically decide which Table will build
(4) Raw<br/>
Raw is an abstract container to store a sample<br/>
Input format: map<prop_type,value_type><br/>
Methods:<br/>
* build: build a Raw object with tag sample_index
(6) Column<br/>
Column is an abstract container to store <br/>
Input format: map<prop_type,value_type><br/>
Methods:<br/>
* build:  build a Column object with tag prop_type
# 2. Collections:

# AI Algorithms:
## 1. kNN Algorithm
* kd Tree
* kd Tree Search
## 2. Decision Tree
* The progress of Least Square:
 Calculating the sum of elements in Y;<br/>
 Searching least square starting from j=1;<br/>
 Traversal j=2,3,....,N;<br/>
 **Complexity: O(N^2)**;<br/>
 Solving least square by **dynamic programming**<br/>
* Gini Index:
 Counting classes' capacity by *partition strategy*;<br/>
 **Complexity of counting: O(N)**;<br/>
 **Complexity of calculating Complexity of Gini: O(kN), k is the dimension**<br/>
* Prunning:
 Postorder Traversal to calculate Gini and loss function for every node;<br/>
 leaf nodes will be stored in a queue;<br/>
 Postorder Traversal searching and prunning from leaf nodes;<br/>
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
* Heuristic Algorithms: *subclass* of SVM, implements the *interfaces* of SVM

## 5. AdaBoost
* **Template Design Pattern**
* Boosting Tree: *subclass of AdaBoost*, implements the *interfaces* of a AdaBoost object

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
## 10 Clustering:


# Discussion
## 1. SVM Algorithm  with Generic Algorithm
### (1) Generic Algorithm
Generic Algorithm is a type of heuristic algorithm aiming to find an approximate optimal solution. The main features is:<br/>
* Operating structural objects directly without the limitation of derivative and continuity
* Hidden parallelity and better global searching ability
* Searching optimal point with probability method, obtaing searching direction without any given rule automatically<br/>
<br/>The main progress is:
* Generating species(samples) randomly
* Calculating fitness function/objective function and discriminating if the optimal criterion is satisfied. 
* Selecting parents(two samples) which own the highest fitness value, then eliminating the lowest ones. 
* Crossover(binary encode/float encode/character encode/generic programming method)
* Mutation<br/>
* Until terminating condition is accomplished
### (2) SVM implemented by GA
Essentially, SVM is to solve a constraint quadratic convex optimization. So, we merely extend GA to search a optimum point with constraint conditions. <br/>
However, the optimum solution may fail to be found. We should replace it by an approximate one. 
### (3) Extension to another evolutionary algorithms
PAA and SAA are all algorithms searching for the optimum point like GA.

## 2. 
