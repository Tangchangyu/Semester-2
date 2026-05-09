#include"shape2.h"
#include<string>
#include<iomanip>
#include<vector>
#include <iostream>

int main(){
    using namespace std;
    cout<<fixed<<setprecision(2);

    double A[]={1,2};
    double O[]={0,0};
    double B[]={2,1};

    shape* s1 = new triangle("三角形",A,B,O);
    shape* s2 = new square("正方形",A,2);
    shape* s3 = new circle("圆",O,3);
    shape* s4 = new sphere("球",O,3);

    vector<shape*> shapes = {s1,s2,s3,s4};

    for(const auto& Ptr : shapes){
        Ptr->print();
        cout<<"\n";
    }

    for(const auto& Ptr : shapes){
        delete Ptr;
    }


}