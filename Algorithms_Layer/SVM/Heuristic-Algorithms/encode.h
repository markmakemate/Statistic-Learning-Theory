#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
int* encoding(double n){
    int* result;
    stack<int> S;
    int reminder;
    int dividsion=n;
    while(division!=0){
        reminder=division%2;
        division=division/2;
        S.push(reminder);
    }
    int N=S.size();
    result=new int[N];
    for(int i=0;i<N;i++){
        result[i]=S.top();
        S.pop();
    }
    return result;
}