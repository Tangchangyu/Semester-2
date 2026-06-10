#include<stdexcept>

template <typename T>
class node{
public:
    T data;
    node<T> *next;//结构：一数据一指针

    node(Data):data(Data),next(nullptr){};
};

template<class T>
class LinkedStack{
    node<T> *top;

public:    
    LinkedStack():top(nullptr){};


    void push(T value){
        node<T> *newNode= new T(value);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(top == nullptr){
            throw std::invalid_argument("The stack is empty;\n");
        }
        else{
        node<T> *temp = top;
        top = top->next;
        delete temp;
        }
    }

    
};