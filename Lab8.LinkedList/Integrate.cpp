#include<stdexcept>
#include<iostream>

template <typename T>
class node{
public:
    T data;
    node<T> *next;//结构：一数据一指针

    node(T Data):data(Data),next(nullptr){};
};

template<class T>
class LinkedStack{
    node<T> *top;

public:    
    LinkedStack():top(nullptr){};

    LinkedStack(const LinkedStack<T> &original){
        node<T>* ptr=original.top;
        LinkedStack<T> temp;
        while (ptr != nullptr)
        {
            temp.push(ptr->data);
            ptr = ptr->next;
        }

        ptr = temp.top;

        while(ptr != nullptr){
            push(ptr->data);
            ptr=ptr->next;
        }
        
    }

    ~LinkedStack(){
        while (!isEmpty()){
            pop();
        }
        //delete top;无效操作
    }


    void push(T value){
        node<T> *newNode= new node<T>(value);
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

template<typename U>
friend std::ostream& operator<<(std::ostream& ,const LinkedStack<U>&);//表明此函数可以访问类的私有数据成员；
    

template<typename U>
friend LinkedStack<U> backwardStack(const LinkedStack<U>& , LinkedStack<U> );

};



template<typename T>
std::ostream& operator<<(std::ostream& os ,const LinkedStack<T>& list){
    node<T> *temp = list.top;
    while(temp != nullptr){
        os <<temp->data;
        temp = temp->next;
    }
    return os;
}


template<typename T>
LinkedStack<T> merge(const LinkedStack<T> &Stack1,const LinkedStack<T> &Stack2){
    LinkedStack<T> tempStack=backwardStack(Stack2);
    LinkedStack<T> backStack = backwardStack(Stack1,tempStack);
    return backwardStack(backStack);
}

template<typename T>
LinkedStack<T> backwardStack(const LinkedStack<T>& orientedStack, LinkedStack<T> baseStack=LinkedStack<T>()){
    node<T>* ptr = orientedStack.top;
    LinkedStack<T> backStack=baseStack;
    while( ptr != nullptr){
        backStack.push(ptr->data);
        ptr = ptr->next;
    }
    return backStack;
}//未调用拷贝构造函数，不能在拷贝构造中复用——赋值的过程就要调用拷贝构造函数

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