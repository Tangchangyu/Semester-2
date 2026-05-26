#pragma ocne
#include<iostream>
#include<stdexcept>

//编写一个程序，演示只有在异常发生之前已经构造的成员对象才会调用成员对象析构函数
class Item{
    private:
    int value;

    public:
    Item(int va):value(va){
        if(value==3){
            throw std::runtime_error("An exception was thrown!\n");
        }
        else {
                        std::cout<<"an Item with the value of "<< value <<" has been constructed."<<std::endl;

        }
    }

    ~Item(){
        std::cout<<"Item with value of "<< value <<" has been destructed."<<std::endl;

    }
};

int main(){
    try {
        Item it(1) ;
    Item  i2(2);
    Item i3(3);
    Item i4 (4);
}

catch (const std::runtime_error& er){
    std::cout <<"catch an exception.\n";
}
    
std::cout<<"the project will be closed.";
}