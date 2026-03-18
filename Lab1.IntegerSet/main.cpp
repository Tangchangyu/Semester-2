#include"IntegerSet.h"
#include<iostream>
using std::cout;
using std::endl;

int main(){
    IntegerSet a ;
    IntegerSet b ;
    IntegerSet c;
    IntegerSet d;
    
    cout <<"Enter set A:\n";
    a.inputSet();
    cout<<"\nEnter aset B: \n";
    b.inputSet();
    
    c=a.unionOfSets(b);
    d= a.intersectionOfSets(b);

   
    cout <<"\nUnion of A and B is :\n";
    c.printSet();

    cout <<"Intersection of A and B is:\n";
    d.printSet();

    if ( a.isEqualto(b)){
        cout <<"Set a is equal to set B\n";
    }

    else{
        cout <<"Set a is not equal to set B\n";
    }

    cout <<"\nInserting 77 into set A...\n";
    a.insertElement(77);
    cout <<"set A is now:\n";
    a.printSet();

    cout << "\nDeleting 77 from set A...\n";
    a.deleteElement(77);
    cout <<"Set A is now:\n";
    a.printSet();

    cout<<endl;


}