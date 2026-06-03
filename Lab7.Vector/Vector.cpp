#include <iostream>

template<typename Type,int i = 0>
class Vector{
private:
    size_t capacity;
    Type* TypePtr=nullptr;//堆区分布，手动管理内存
    Type* endPtr=nullptr;//Type* 代表指针！！！

public:
    void push_back(Type element){
        if (capacity == 0){
            TypePtr = new Type element[1];
            capacity = 1;
            endPtr = TypePtr ;
        }

        else{
            if (endPtr - TypePtr +1 == capacity){
                newcapacity = capacity*2;
                Type* newPtr = new Type newElements[newcapacity];
                for(int i  = 0;i < capacity ; i++){
                    newElements[i] = TypePtr [i]
                }

                delete TypePtr[];
                TypePtr = newPtr;
                endPtr = newPtr+capacity;
                capacity = newcapacity;
                *endPtr = element;
            }

            else{
                endPtr++;
                *endPtr = element;
            }
        }

    }

    friend std::ostream& operator<<(std::ostream os ,const Vector  );

};
template<typename Type>
std::ostream& operator<<(std::ostream &os ,const Vector<Type> my){
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
