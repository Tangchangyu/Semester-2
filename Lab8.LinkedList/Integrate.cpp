#include<stdexcept>
#include<iostream>

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

template<typename T>
friend std::ostream& operator<<(std::ostream& ,const LinkedStack&);
    

};

template<typename T>
LinkedStack<T> merge(LinkedStack<T> &Stack1,LinkedStack<T> &Stack2);

int main (){
using std::cout;

    LinkedStack<int> LinkedList1;
    LinkedStack<int> LinkedList2;

    for(int i = 0; i < 10 ; i++){
        LinkedList1.push(i);
    }

    for(int i = 10; i <30 ; i+=2){
        LinkedList2.push(i);
    }

    cout<<"Linked list 1 now is: "<<LinkedList1<<"\n";
    cout<<"Linked list 2 now is: "<<LinkedList2<<"\n";

    LinkedStack<int > LinkedList3 = merge(LinkedList1,LinkedList2);

    cout<<"Integrate list 1 and list 2 is :"<<LinkedList3<<"\n";


    
}