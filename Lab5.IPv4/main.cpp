#include<fstream>
#include <ctime>
#include <cstdlib>
//1.随机生成一个IPv4地址址（范围从 0.0.0.0 到 255.255.255.255）和一个时间戳（格式为 YYYY-MM-DD HH:MM:SS）。
//在一个文件中打印所有记录，每个记录占据一行
    int setNum(){
        return rand()%256;
    }

    void setIP(std::fstream& of){
        for (int i = 0 ; i < 4 ; i ++){
            of <<setNum();

            if(i < 3) of <<",";
            else of <<"\t";
        }
    }

    void setTime(std::fstream& of );//可以使用父类的ostream作为实参；


int main(){


    srand(static_cast<unsigned int>(time(0)));
    //像 srand(...) 这种调用函数的操作，属于“具体的指令”。具体的指令必须写在函数体内部

    std::fstream outFile("ips.txt",std::ios::out);

    for(int i = 0; i <100; i ++){
        setIP(outFile);
        setTime(outFile);
        outFile << std::endl;
    }
}



