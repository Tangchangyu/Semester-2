#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Shape{


    protected:
    void printDot(double A[2]){
        cout<<"("<<A[0]<<","<<A[1]<<")  ";
    }
    string id;
    double S;

    public: 

    Shape(string id):id(id){};

    virtual void print(){
        std::cout<<"Information of "<<id<<":\n\tS:"<<S<<endl;
    }


};

class Circle:public Shape{
    double R;
    double place [2]={0,0};
public:
    Circle(const Circle& other):Shape(other.id),R(other.R){
        place[0]= other.place[0];
        place[1]= other.place[1];
        area();
    }
    Circle(string _id,double x ,double y ,double R):Shape(_id),place{x,y},R(R){
        if (R<0){
            R= 0;
        }
        area();
    }
    double area(){
        S = 3.14*R*R;
        return S;
    }

    void setPlace(double x,double y){
        place[1] = x;
        place [2] = y;
    }

    void print(){
        Shape::print();
        cout<<"\tCenter of circle:";
        printDot(place);
        cout<<"\n\tR:"<<R<<endl;
    }


};

class Triangle:public Shape{
    double A [2];
    double B [2];
    double C [2];
public:
    Triangle(const Triangle& other):Shape(other.id){
        for(int i = 0;i<2; i++){
            A[i]=other.A[i];
            B[i]=other.B[i];
            C[i]=other.C[i];
        }
        area();
    }

    Triangle(string _id,double ax,double ay,double bx ,double by ,double cx, double cy):Shape(_id),A{ax,ay},B{bx,by},C{cx,cy}{
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

    void print(){
        Shape::print();
        cout <<" \tThree vertex:";
        printDot(A);
        printDot(B);
        printDot(C);
    }



};

class Rectangle:public Shape{
protected:
    double a;
    double b;
    double leftTop[2];
    double rightBottom[2];

    public:
    Rectangle(const Rectangle& other):Shape(other.id){
        for(int i = 0; i < 2; i++){
            leftTop[i]=other.leftTop[i];
            rightBottom[i]= other.rightBottom[i];
                }
        area();

        
    }
    Rectangle(string _id,double ax ,double ay ,double bx,double by ):Shape(_id),a(bx-ax),b(by-ay),leftTop{ax,ay},rightBottom{bx,by}{
        if(a>0&&b>0){
            area();
        }
        else{
            if (a<0) a=-a;
            if (b<0) b = -b;
            area();
        } 
    }

    double area(){
        S=a*b;
        return S;
    }

    void print(){
        Shape::print();
        cout<<"\tThe leftTop dot:";
        printDot(leftTop);
        cout<<"\n\tThe rightBottom dot:";
        printDot(rightBottom);
        cout<<endl;

    }
};

class Square:public Rectangle{
    
    public:
    Square(const Square& other):Rectangle(other.id,other.leftTop[0],other.leftTop[1],other.rightBottom[0],other.rightBottom[1]){
        area();
    }
    Square(string _id,double ax ,double ay ,double a  ):Rectangle(_id,ax,ay,ax+a,ay+a){
        if(a>0&&b>0){
            area();
        }
        else{
            if (a<0) a=-a;
            area();
        }
    }

    double area(){
        S=a*b;
        return S;
    }

    Circle incircle(){
        string _id ="incircle of "+id;
        Circle inc(_id,(leftTop[0]+rightBottom[0])/2,(leftTop[1]+rightBottom[1])/2,a/2);
        return inc;
    }

    void print(){
        Shape::print();
        cout<<"\ta:"<<a<<"\n\tThe leftTop dot:";
        printDot(leftTop);
        cout<<"\nthe incircle of square:\n";
        Circle inc= incircle();
        inc.print();
    }
};

