#include "time.h"
#include <iostream>

int main(){
    using namespace std;
    Time test(23,59,57);

 for(int t =0; t < 14;t++){
        test.printStandard();
        test.tick();
        cout<<"\n";
        
    }


}

