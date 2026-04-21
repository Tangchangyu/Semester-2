#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::string;

class Shape{
    private:
    string id;

    protected:
    double S;

    public: 
    void print(){
        std::cout<<"the area of "<<id<<" is:"<<S<<std::endl;
    }


};

class Circle:public Shape{
    double R;
    double place [2]={0,0};
public:
    Circle(double x ,double y ,double R):place{x,y},R(R){
        if (R<0){
            R= 0;
        }
        area()
    }
     double area(){
        S = 3.14*R*R;
        return S;
     }

     void setPlace(double x,double y){
        place[1] = x;
        place [2] = y;
     }


};

class Triangle:public Shape{
    double A [2];
    double B [2];
    double C [2];
public:
    Triangle(double ax,double ay,double bx ,double by ,double cx, double cy):A{ax,ay},B{bx,by},C{cx,cy}{
        if (area()== 0){
            cout <<"illegal triangle! set A,B,C =(0,0)";
            A[0] = A[1]= B[0]=B[1]=C[0]=C[1]= 0;
        }
    }

    double area(){
        S=(B[0]-A[0])*(C[1]-A[1])-(B[1]- A[1])*(C[0]-A[0]);
        if (S <0){
            S = -S;
        }
        return S;
    }



};
