#include<iostream>
#include<string>
using std::cout;
using std::cin;

template <typename T,int numberOfElements =0>
class Array{
public:
    T elements [numberOfElements];//要给数组起名字！！

public:
   //仿照array类，不提供构造函数，使Array类成为聚合体
   //提供下标运算符重载
   T& operator[](unsigned int index){
    return elements[index];
   }
   //返回引用T&

   int size(){return numberOfElements;}

   void print ()const{
    for(int i = 0; i < numberOfElements; i++){
        cout <<elements[i]<<" ";
    }
   }
};


int main (){
    cout <<"输入5个整数值：\n";
    Array<int,5> intArray;
    for (int i = 0; i < intArray.size(); i++){
        cin >>intArray[i];
    }

    cout<<"则 intArray 中的值为:";
    intArray.print();

    cout<<"\n输入 7 个单字字符串值:\n";
    Array<std::string ,7> stringArray;
       for (int i = 0; i < stringArray.size(); i++){
        cin >>stringArray[i];
    }

    cout <<"则 stringArray 中的值为:";
    stringArray.print();
}