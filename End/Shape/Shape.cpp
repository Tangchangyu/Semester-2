#include <iostream>
#include<string>

using std::string;
using std::cout;

class Shape{
public:
    virtual void display()const{
        cout<<"Shape type: ";
    };

    virtual double volume()const = 0;
};

class Cuboid:public Shape{

double a = 0;
double b = 0;
double c = 0;

public :
    Cuboid(double A=0,double B=0, double C=0):a(A),b(B),c(C){};

    void display()const{
        Shape::display();
        cout<<"Sphere:\n\tDetailed infomation:\n\tthree edges: ";
        cout<<"a="<<a<<" b="<<b<<" c="<<c<<std::endl;

    }

    double volume()const{
        return a*b*c;
    }

};

class Sphere:public Shape{

double Radius= 0;

public:
    Sphere(double r):Radius(r){
        
    };

    void display(){
        Shape::display();

        cout<<"Sphere:\n\tDetailed infomation:\n\tRadius: "<<Radius<<std::endl;
    }

    double volume()const{
        return 3.14*Radius*Radius;
    };
};

class Cube:public Cuboid{
    double a =0;


public:
    Cube(double A):Cuboid(0,0,0){

    };
    void display()const override{
        Shape::display();
                cout<<"Sphere:\n\tDetailed infomation:\n\tThe side length: "<<a<<std::endl;

    }
    
};


int main(){
    Shape* shapes[3];

    shapes [0]= new Sphere(2);
    shapes [1]= new Cuboid(2,3,4);
    shapes [2]= new Cube(5);

    double totalvolume = 0.0;

    for ( int i = 0 ;i < 3 ; i ++){
        shapes[i]->display();

        totalvolume +=shapes[i]->volume();
    }

    std::cout<<"Total volume of all shapes:"<< totalvolume<<std::endl;
}