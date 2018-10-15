#include<iostream>
#include<vector>
#include"KNN.h"
using namespace std;
int main() {
	kd_Tree T;
	BSTreeNode<vector<double> >* root;
	vector<double>* Input;
	vector<double> search;
	vector<double> searching_point;
	double* Set[2];
	Set[2] = new double[6];
	double input[6][2] = { {2,3},{5,4},{9,6},{4,7},{8,1},{7,2} };
	double point[2] = { 5,6 };
	searching_point.push_back(point[0]);
	searching_point.push_back(point[1]);
	for (int i = 0; i < 6; i++) {
		*(Set + i) = input[i];
		(*(Input + i)).push_back(*(Set + i)[0]);
		(*(Input + i)).push_back(*(Set + i)[1]);
	}
	root = T.Generator(Input);
	search = T.kd_Searching(root, searching_point);
	cout << search.at(0) << " " << search.at(1);
	return 0;
}