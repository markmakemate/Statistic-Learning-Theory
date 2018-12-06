#include<iostream>
#include<cstdlib>
#include<cmath>
#include "../lib/Linear_Algebra/Matrix.h"
#include "../lib/Linear_Algebra/Vector.h"
#include "../lib/Data_Processors/Table/Table.h"
#define raws rows
using namespace std;
template<class T>
class HMM{
private:
    Matrix<T> transition;  //Probability transition matrix
    Matrix<T> observation;  //observed probability matrix
    Vector<T> series;  //observation series vector
    static Vector<T> Value;
    Table<T> observe;
    Table<T> states;
    double Probability;   //P(O|lemada): the result
public:
    void load(const Table<T>& observed_series,const Table<T>& state_series);  //load data sets
    void forward(const Matrix<T>& A,const Matrix<T>& B,const Vector<T>& pi);  //forward algorithm to calculate probability
    void backward(const Matrix<T>& A,const Matrix<T>& B,const Vector<T>& pi);  //backward algorithm to calculate probability
    //A: Probability transition matrix
    //B: Observation probability matrix
    //pi: initial value
    void Baum_Welch();   //Baum-Welch Algorithm
    void supervised();  //Supervised Algorithm
    void Viterbi();  //Viterbi Algorithm
};
template<class T>
void HMM<T>::load(const Table<T>& observed_series,const Table<T>& state_series){
    observe=observed_series;
    states=state_series;
}
template<class T>
//forward algorithm
void HMM<T>::forward(const Matrix<T>& A,const Matrix<T>& B,const Vector<T>& pi){
    int N=A.rows();
    int count=0;
    Probability=0;
    for(int i=0;i<N;i++){
        series[i]=pi[i]*B(i,1);
    }
    for(int i=0;i<N;i++){
        count++;
        if(count<N){
            for(int j=0;j<N;j++){
                series[i]=series[j]*A(j,i)
            }
            series[i]=series[i]*B(i,count);
            double sum=0;
            //calculate probability P(O|lambda)
            for(int k=0;k<N;k++){
                sum+=series[k];
            }
            Probability+=sum;
        }
        else{
            break;
        }
        
    }
}
template<class T>
void HMM<T>::backward(const Matrix<T>& A,const Matrix<T>& B,const Vector<T>& pi){

}

template<class T>
void HMM<T>::Baum_Welch(){

}

template<class T>
void HMM<T>::supervised(){}

template<class T>
void HMM<T>::Viterbi(){}