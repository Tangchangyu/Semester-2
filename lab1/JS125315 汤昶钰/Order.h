
#include<iostream>
#include<string>
#include<vector>
using std::vector;
using std::string;



class Order
{
private:
 string dishName;
 string time;
 bool deliverToDesk;
static int orderCount;//默认初始化为0；
public:
    Order(string dn,string t, bool dtd):dishName(dn),time(t),deliverToDesk(dtd)
    {
        orderCount++;
        if (orderCount>=12){
            std::cout <<"订单数量达到上限";
            orderCount--;
        }
    }

};
int Order::orderCount = 0;//这里需要作用域的标注么？

class Employee
{
private:
 string name;
 int age;
 const int id;
static int EmployeeCount;
vector<Order> orders;

    int dishNumber = 0 ;
public:
    Employee(string n,int ag):name(n),age(ag),id(EmployeeCount+1)
    {
        EmployeeCount++;
    }
    void makeOrder(string dish,string t,bool dtd){
        
    }

   
};