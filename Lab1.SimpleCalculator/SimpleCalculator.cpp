#include"SimpleCalculator.h"
#include <stdexcept>

double SimpleCalculator::add(const double&a,const double& b)const{
    return a+b;
}
double SimpleCalculator::substract(const double&a,const double& b)const{
    return a-b;
}
double SimpleCalculator::multiply(const double&a,const double& b)const{
    return a*b;
}
double SimpleCalculator::divide(const double&a,const double& b)const{
    if (b!=0) return a / b;
    else if (0==b){
        throw std::runtime_error("dividied by 0!");
        return 0;
    }

}
