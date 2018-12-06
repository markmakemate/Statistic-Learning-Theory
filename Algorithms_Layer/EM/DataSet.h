#include "../lib/Linear_Algebra/Matrix.h"
using namespace std;
template<class function>
class DatSet{
private:
    Matrix<function> dataset;
    Matrix<double> estimation;
public:
    void load(Matrix<function>& Input){
        dataset=Input;
    }
    Matrix<double> operator()(double theta){
        for(int i=0;i<dataset.raws();i++){
            for(int j=0;j<dataset.cols();j++){
                estimation(i,j)=dataset(i,j)(theta);
            }
        }
        return estimation;
    }
};