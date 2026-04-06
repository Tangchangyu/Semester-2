#include "HugeInt.h"
HugeInt::HugeInt(long number){
    for(int i = size -1; i>=0 ; i --){
        integer[i]= 0 ;
    }
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
    else {
        while (*flag != '\0' ){
        flag ++;
    }
    flag --;

    for (int i = size - 1; i >= 0 ; i--){
        integer[i]= *flag - '0';
        if (flag != number) flag --;
        else {
            break;
        }
    }
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
    if(*this < other){
        throw std::invalid_argument("a nagetive result");
        return other-*this;
    }
    HugeInt result;
    for (int i = size - 1 ;i >=0 ; i--)
    {
        result.integer[i]+= integer[i] - other.integer[i];
        if (result.integer[i]<0){
            result.integer[i]+=10;
            result.integer[i-1] -= 1;
        }
    }
    return result;

}

HugeInt HugeInt::operator*(const HugeInt& other)const{
    HugeInt result;
    for(int i = size - 1; i >=0 ;i--){
        for (int j = size - 1; j >=0; j --){
 
            int n = i + j - (size - 1);
            if (n <size && n >= 0 ){
                int mul = integer[i]*other.integer[j];
                result.integer[n] += mul ;
            }
            
        }
        result.adjust();
    }

    return result;
}

HugeInt HugeInt::operator/(const HugeInt& other)const{
    HugeInt zero("0");

    if ( other ==  zero){
        throw std::invalid_argument("divided by 0");
        return *this;
        }

    else if (*this < other) return zero;
    else {
        HugeInt remainder;
        HugeInt quotient;
        for(int i = 0 ; i < size ; i ++){
            remainder = remainder*10 ;
            remainder = remainder + this->integer[i];
            int count = 0;
            while (remainder >= other)
            {
                remainder =remainder - other;
                count ++;
            }
            quotient.integer[i]= count;//位数对齐;
        }
        return quotient;
    }

}

int HugeInt::getLength()const{
    int i = 0;
    for ( ;i < size;i ++){
        if (integer[i]== 0 ) return size - i;
    }
    return 0;
}

ostream& operator<<(ostream& os, const HugeInt& number){
    int i = 0;
    for(i ; i < number.size; i ++){
        if (number.integer[i]!= 0 ) break;
    }
    if (i == number.size - 1) os<<0;
    else{
        for (i ;i <number.size; i ++){
            os<<number.integer[i];
        }
    }
    return os;
}
