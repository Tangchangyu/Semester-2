#include <iostream>
#include <vector>
#include <iomanip>
#include "Employee.h"
#include "Date.h"

using namespace std;

int main() {
    // 1. 设置货币格式输出
    cout << fixed << setprecision(2);

    // 2. 创建四个员工对象（对应图片数据）
    // Salaried employee: John Smith
    Employee* s1 = new SalariedEmployee(
        "John", "Smith", "111-11-1111", date( 6, 15,1944), 800.00);

    // hourly employee: Karen Price
    Employee* s2 = new hourlyEmployee(
        "Karen", "Price", "222-22-2222", date( 4, 29,1960), 16.75, 40.00);

    // commission employee: Sue Jones
    Employee* s3 = new CommissionEmployee(
        "Sue", "Jones", "333-33-3333", date( 9, 8,1954), 10000.00, 0.06);

    // base-salaried commission employee: Bob Lewis (补上了这个类)
    Employee* s4 = new baseSalariedCommissionEmployee(
        "Bob", "Lewis", "444-44-4444", date( 3, 2,1965), 5000.00, 0.04, 300.00);

    // 3. 放入多态容器
    vector<Employee*> employees = { s1, s2, s3, s4 };

    cout << "Employees processed polymorphically via dynamic binding:\n" << endl;

    // 4. 遍历打印
    for (const auto& empPtr : employees) {
        empPtr->print();
    }

    // 5. 释放内存（触发析构函数打印）
    for (auto& empPtr : employees) {
        delete empPtr;
    }

    return 0;
}