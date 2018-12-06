#include<iostream>
#include<cstdlib>
#include "../lib/Linear_Algebra/Vector.h"
using namespace std;
#define MAX 1.2578e+37
template<class dataset>
class EM{
private:
     double Q(Vector<double>* parameters);
     double Max;
     static Vector<double> theta;
     dataset Data;
public:
    void load(dataset& Input){
        Data=Input;
    }
    void training(Vector<double> initial);
};
template<class T>
void EM<T>::training(Vector<double> theta_zero){
    
}