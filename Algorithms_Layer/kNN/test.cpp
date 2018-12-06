#include<iostream>
#include<cstdlib>
using namespace std;
int function(int* p=NULL);
int main(){
    int* p=new int[3];
    p[0]=1;
    p[1]=2;
    p[2]=3;
    cout<<&(p[0])<<endl;
    cout<<*(&(p[0]))<<endl;
    function(p+1);
    return 0;
}
int function(int* p){
    cout<<*p<<endl;
    cout<<*p+1<<endl;
}