#include<iostream>
#include<map>
#include<iterator>
#include<cmath>
#include "Table_Raw.h"
#define INF 2147483647
using namespace std;
//Column-Oriented Table
//Subclass of Table
template<class T>
class Table_Algo:public Table_Raw<T>{
private:
    int class_num;
    map<T,int> dp;
protected:
    void swap(int raw_1,int raw_2);
    int Partition(int& character,int begin=0,int end=INF);
    void Partition(int& attribute);
public:
    void QuickSort(int& character,int begin=0,int end=INF);  //Sort the table based on 'character' attribute
    double gini(int& character);      //calculate the gini index of attribute 'character'
    double entropy(int& character);   //calculate the entropy of attribute 'character'
    double conditional_entropy(int Y,int X);
    double info_gain(int Y,int X);    //Calculate the info_gain of attribute Y and X
    double var(int attribute);    //calculate the variance of attribute
    double mean(int attribute);   //calculate the mean value of attribute
    
};

//QuickSort
template<class T>
void Table_Algo<T>::QuickSort(int& attribute,int begin,int end){
    if(end==INF){
        end=(*this).num();
    }
    if(begin<end){
        int q=Partition(attribute,begin,end);
        QuickSort(attribute,begin,q-1);
        QuickSOrt(attribute,q+1,end);
    }
}

//Partition of QuickSort
template<class T>
int Table_Algo<T>::Partition(int& attribute,int begin,int end){
    T x=(*this)(end,attribute);
    int init=begin-1;
    for(int j=begin;j<end-1;j++){
        if((*this)(j,attribute)<x){
            init++;
            swap(init,j);
        }
    }
    swap(init+1,end);
    return init++;
}

//swap two raw of a table object
template<class T>
void Table_Algo<T>::swap(int raw_1,int raw_2){
    typedef map<int,T> raw;
    raw S_1,S_2;
    S_1=(*this)[raw_1];
    S_2=(*this)[raw_2];
    (*this).pop(raw_1);
    (*this).pop(raw_2);
    (*this).insert(raw_2,S_1);
    (*this).insert(raw_1,S_2);
}

//gini index
template<class T>
double Table_Algo<T>::gini(int& attribute){
    Partition(attribute);
    double Gini=0;
    double* probability=new double[class_num];
    for(map<T,int>::iterator it=dp.begin();it!=dp.end();it++){
        probability[i]=(it->second)/(*this).num();
        Gini+=probability[i]*(1-probability[i]);
    }
    return Gini;
}

//reshape attribute into a class set
template<class T>
void Table_Algo<T>::Partition(int& attribute){
    for(int i=0;i<(*this).num();i++){
        if(dp[(*this)(i,attribute)]>0){
            dp[(*this)(i,attribute)]++;
        }
        else{
            dp.insert(pair<T,int>((*this)(i,attribute),1));
        }
    }
    class_num=dp.size();
}

//Entropy
template<class T>
double Table_Algo<T>::entropy(int& attribute){
    double Entropy=0;
    Partition(attribute);
    double* probability=new double[class_num];
    for(map<T,int>::iterator it=dp.begin();it!=dp.end();it++){
        probability[i]=(it->second)/(*this).num();
        Entropy+=probability[i]*log(probability[i]);
    }
    return -1*Entropy;
}


template<class T>
map<T,double> Table_Algo<T>::conditional_entropy(int Y,int X){
    double ce=0;
    int count=0;
    map<int,T> candidate;
    Table_Raw<T>* result=new Table_Raw<T>[dp.size()];
    Partition(X);
    for(map<T,int>::iterator it=dp.begin();it!=dp.end();it++){
          for(map<int,map<int,T> >::iterator table=Data.begin();table!=Data.end();table++){
              candidate=table->second;
              if(candidate[X]==it->first){
                  result[count].push(candidate);
              }
          }
          count++;
    }
    map<T,int>::iterator it=dp.begin();
    for(int i=0;i<class_num;i++){
        T value=(*(it+i)).first;
        int number=(*(it+i)).second;
        ce+=(number/(*this).num())*(result[i].entropy(Y));
    }
    return ce;
}
template<class T>
double Table_Algo<T>::info_gain(int Y,int X){
    return (*this).entropy(X)-(*this).conditional_entropy(Y,X);
}
template<class T>
double Table_Algo<T>::mean(int attribute){
    int N=(*this).num();
    double sum=0;
    for(int i=0;i<N;i++){
        sum+=(*this)(i,attribute);
    }
    double result=sum/N;
    return result;
}
template<class T>
double Table_Algo<T>::var(int attribute){
    int N=(*this).num();
    double c=(*this).mean(attribute);
    double sum=0;
    for(int i=0;i<N;i++){
        sum+=pow((*this)(i,attribute)-c,2);
    }
    return sum;
}