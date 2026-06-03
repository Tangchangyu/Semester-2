#include <iostream>

template<typename Type>
class Vector{
private:
    size_t capacity;
    Type* TypePtr=nullptr;//堆区分布，手动管理内存
    Type* endPtr=nullptr;//Type* 代表指针！！！

public:
    // 构造函数初始化
    Vector() : capacity(0), TypePtr(nullptr), endPtr(nullptr) {}

    // 析构函数：防止内存泄漏
    ~Vector() {
        delete[] TypePtr;}



    void push_back(Type element){
        if (capacity == 0){
            TypePtr = new Type[1];
            capacity = 1;
            TypePtr[0]= element;
            endPtr = TypePtr+1 ;//修改endPtr逻辑——左闭右开；
        }

        else{
            if (endPtr - TypePtr  == capacity){
                int newcapacity = capacity*2;
                Type* newPtr = new Type[newcapacity];//堆区数组通过指针访问
                for(size_t i  = 0;i < capacity ; i++){
                    newPtr[i] = TypePtr [i];
                }

                delete [] TypePtr;//注意释放内存的正确写法
                TypePtr = newPtr;
                endPtr = newPtr+capacity+1;
                capacity = newcapacity;
                *endPtr = element;
            }

            else{
                endPtr[0]= element;
                endPtr++;//修改指针逻辑时，注意内存越界
            }
        }

    }

    template<typename T>//模板类友元函数的标准写法
    friend std::ostream& operator<<(std::ostream& os ,const Vector<T>&  );

    template<typename T>
    friend std::istream& operator>>(std::ostream &is ,Vector<T>& );//流输入运算符的形参不能为const

};
template<typename Type>
std::ostream& operator<<(std::ostream &os ,const Vector<Type>& my){
    for (int i = 0; i < my.capacity; i++){
        os<<my.TypePtr[i]<<" ";
    }
    return os;
}

//流输入运算符重载
template<typename T>
std::istream& operator>>(std::ostream &is ,Vector<T>& my){
    T *nowPtr= my.TypePtr;
    while(!is){
        if(nowPtr != my.endPtr){

            is>> *nowPtr;
            nowPtr++;
        }
    }
}//实现逻辑：从vector首位开始pushback,直到输入特定字符^z？



 int main(){
    Vector<int> myVector;
    myVector.push_back(1);
    std::cout <<myVector;
    
 }
