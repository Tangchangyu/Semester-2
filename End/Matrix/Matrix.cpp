#include <iostream>
#include <stdexcept>
#include <string>

class exception:public std::runtime_error{
public:
    exception(std::string a ):std::runtime_error(a){

    };
};

template<typename T,int row=0,int column=0>
class Matrix
{
private:
    int Row = row;
    int Column = column;
    int volume = row*column;
    T* ptr= nullptr;

public:
    Matrix( ){
        ptr = new T[volume]{0};
    };
    ~Matrix(){
        delete []ptr;
    };

    T& at(int a,int b ){
        return at(((a)*column+b));
    }//行数-1）*每行数

    T& at(int a ){
        if(a<volume){
            return ptr[a];
        }
        else throw exception("Array crosses the boundary.");
        
    }

    T& at(int a,int b )const{
        return at(((a)*column+b));
    }//行数-1）*每行数

    T& at(int a )const{
        if(a<volume){
            return ptr[a];
        }
        else throw exception("Array crosses the boundary.");
        
    }

    Matrix<T ,row,column> operator+(const Matrix<T,row,column>& other){
        Matrix<T,row,column> sum;
        
        for ( int i = 0; i < volume ; i ++){
            sum.at(i)= this->at(i)+other.at(i);
        }
        return sum;
    }

    friend std::ostream& operator<<(std::ostream& os,const Matrix& mat ){
    os<<"\n";
        for (int i = 0 ; i < mat.Row; i ++){
            for (int j = 0 ; j<mat.Column; j ++){
                os<<"\t"<<mat.at(i,j)<<",";
            }
    os<<std::endl;
    }

    return os;//此处os为引用
    };//采用类内实现友元函数

};


int main(){
    Matrix<int , 2,2> mat1;
    Matrix<int , 2 ,2 > mat2;

    try {
        mat1.at(0,0)= 1; mat1.at(0,1) = 2;
        mat1.at(1,0) = 3; mat1.at(1,1) = 4;

        Matrix<int , 2 ,2 > sum = mat1 + mat2;

        std::cout<<"Matrix Addition Result:"<<std::endl<<sum;

        mat1.at(1,2)=3;//测试数组越界
 
    }
    catch (exception &e){
        std::cout << e.what();
    }
}