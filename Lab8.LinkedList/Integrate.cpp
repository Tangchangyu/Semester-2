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

    ~LinkedStack(){
        while (!isEmpty()){
            pop();
        }
        //delete top;无效操作
    }


    void push(T value){
        node<T> *newNode= new T(value);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(top == nullptr){
            throw std::out_of_range("The stack is empty;\n");//越界错误，或抛出std::underflow_error()下溢错误；
        }
        else{
        node<T> *temp = top;
        top = top->next;
        delete temp;
        }
    }

    bool isEmpty(){
        return (top == nullptr);
    }    
};