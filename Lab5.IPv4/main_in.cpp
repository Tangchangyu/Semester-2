#include<string>
#include <fstream>
#include <iostream>

int CLASS[5] = {0};

    void printNum(int  a ){
        using std::cout;
        std::cout <<"Number of class ";
        switch (a) {
            case 0 :
                cout <<"A";
                break;
            case 1 :
                cout <<"B";
                break;
            case 2 :
                cout <<"C";
                break;
            case 3 :
                cout <<"D";
                break;
            case 4 :
                cout <<"E";
                break;
            default:break;
        }
        std::cout<<" :" <<CLASS[a]<<std::endl;
    }


int main(){
    using namespace std;
    std::ifstream in("ips.txt",std::ios::in);
    if (!in){
        std::cout <<"file openning failed!";
        exit(1);
    }
    for (int i = 0; i < 100 ; i++){
        char  a[20]; 
        char temp[20];
        in >>a>>temp>>temp;
        if (a[1]=='.'||a[2]=='.'){     CLASS[0]++;}
        else{
            int num = 100*(a[0]-'0')+10*(a[1]-'0')+(a[2]-'0');
            switch (num)
            {
            case 0 ... 127:
                CLASS [0]++;
                break;
            case 128 ... 191:
                CLASS [1]++;
                break;
            case 192 ... 223:
                CLASS [2]++;
                break;
            case 224 ... 239:
                CLASS [3]++;
                break;
            case 240 ... 255:
                CLASS [4]++;
                break;
            default:
                break;
            }
        }
        
    }

    for (int i = 0 ; i < 5 ; i ++){
        printNum(i);
    }



}