#include "shape.h"
#include <iostream>
#include <string>

int main (){
    Circle mycir("mycir",10,0,4);
    Triangle mytri("mytri", 1,1,2,2,1,2);
    Rectangle myrec("myrec",10,1,3,10);
    Square mysqu("mysqu",1,1,4);
    mycir.print();
    mytri.print();
    myrec.print();
    mysqu.print();
    Circle inCircleOfMysqu=mysqu.incircle();
    inCircleOfMysqu.print();

}