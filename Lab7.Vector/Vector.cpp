#include <iostream>

template<typename Type>
class Vector{
private:
    size_t capacity;
    Type* TypePtr=nullptr;//堆区分布，手动管理内存
    Type* endPtr=nullptr;//Type* 代表指针！！！

public:
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
                endPtr[0]= element
                endPtr++;//修改指针逻辑时，注意内存越界
            }
        }

    }

    template<typename T>//模板类友元函数的标准写法
    friend std::ostream& operator<<(std::ostream& os ,const Vector<T>&  );

};
template<typename Type>
std::ostream& operator<<(std::ostream &os ,const Vector<Type>& my){
    for (int i = 0; i < my.capacity; i++){
        os<<my.TypePtr[i];
    }
    return os;
}



 int main(){
    Vector<int> myVector;
    myVector.push_back(1);
    std::cout <<myVector;
    
 }
