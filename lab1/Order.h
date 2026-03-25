#pragma once
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

    void orderPrint(){
        using std::cout;
        cout <<"\n菜品名称："<<dishName<<"\n点单时间："<<time <<(deliverToDesk?"\n菜品即将送到您的餐桌\n":"\n请及时到窗口取餐\n");
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

    //int dishNumber = 0 ;//无需使用计数器，vector自带.size函数
public:
    Employee(string n,int ag):name(n),age(ag),id(EmployeeCount+1)
    {
        EmployeeCount++;
    }

    bool makeOrder(string dish,string t,bool dtd){
        if (orders.size()<3){
            orders.push_back(Order(dish,t,dtd));
            std::cout<<"点单成功，当前点单数量："<<orders.size()<<std::endl;
            orders[orders.size()-1].orderPrint();
            return 1;
        }
        else std::cout<<"您的点单数量已经达到上限(3)\n";
        return 0;
    }

};

int Employee::EmployeeCount = 0;//类外初始化，否则会报错——未定义