#include "HugeInt.h"
HugeInt::HugeInt(long number = 0){

    for(int i = size -1; i>=0 ; i --){
        integer[i]=number%10;
        number=number/10;
    }

}
HugeInt::HugeInt(const char* number){
    for(int i = size-1; i >=0; i--){
        integer[i]=0;
    }

    const char* flag = number;
    if (flag == nullptr) ;
    else while (*flag != '\0' ){
        flag ++;
    }
    flag --;

    for (int i = size - 1; i >= 0 ; i--){
        integer[i]= *flag - '0';
        if (flag != number) flag --;
        else integer[i - 1]= *number;
        break;
    }
}
void  HugeInt::adjust(){
    for (int i = size - 1 ;i >= 0 ;i--){
        if (integer[i]>=10){
            integer[i-1]+=integer[i]/10;
            integer[i] =integer[i]%10;
        }
    }//实现进位矫正
}

HugeInt HugeInt::operator+(const HugeInt& other)const{
    HugeInt result;
    for(int i = 0;i<size;i++){
        result.integer[i]=integer[i]+other.integer[i];
    }
    result.adjust();

    return result;
}

HugeInt HugeInt::operator+(int other)const{
    return operator+(HugeInt(other));
}

HugeInt HugeInt::operator+(const char* other)const{
    return operator+(HugeInt(other));
}

bool HugeInt::operator==(const HugeInt& other)const{
    bool flag = true;
    for (int i = 0 ;i <size ;i++){
        if (integer[i]!= other.integer[i])
            flag = false;
    }
    return flag;
}

bool HugeInt::operator!=(const HugeInt& other)const{
    return !(*this==other);
}

bool HugeInt::operator>= (const HugeInt& other) const{
    for(short i = 0;i<size ;i++){
        if (integer[i] < other.integer[i] ) return false; 
        else if (integer[i] > other.integer[i] ) return true;
    }

    return true;
}

bool HugeInt::operator < (const HugeInt& other) const{
    return !(*this>=other);
}

bool HugeInt::operator<=(const HugeInt& other )const {
    return ((*this==other||*this<other)?true:false);
}

bool HugeInt::operator>(const HugeInt& other)const {
    return !(*this<=other);
}

HugeInt HugeInt::operator-(const HugeInt& other)const{
    HugeInt result;
    for (int i = size - 1 ;i >=0 ; i--)
    {
        result.integer[i]= integer[i];
    }
    
}



