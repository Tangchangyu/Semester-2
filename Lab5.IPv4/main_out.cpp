#include<fstream>
#include <ctime>
#include <cstdlib>
#include<iomanip>
//1.随机生成一个IPv4地址址（范围从 0.0.0.0 到 255.255.255.255）和一个时间戳（格式为 YYYY-MM-DD HH:MM:SS）。
//在一个文件中打印所有记录，每个记录占据一行
    int setNum(){
        return rand()%256;
    }//生成随机数

    void setIP(std::ostream& of){
        for (int i = 0 ; i < 4 ; i ++){
            of <<setNum();

            if(i < 3) of <<".";
            else of <<"\t";
        }
    }//设置ip

    void setTime(std::ostream& of )//可以使用父类的ostream作为实参；
    {
        static std::time_t startTime = std::time(0) - 365*24*3600;
        //实则传入的是更改的变量指针，0为nullptr;
        //前移一年时间：
        startTime+= rand()% (24*3600);//保证位移时间在一天以内；
        std::tm* now = std::localtime(&startTime);//lovaltime函数只接受地址
        /*
        工作原理：localtime 函数接受一个time_t指针，在内存中创建一个tm结构体，返回&tm；
        二次调用会覆盖同一片内存
        */
        of <<std::put_time(now,"%Y-%m-%d %H:%M:%S");
        /*
            std::put_time 的底层运作其实是一个匹配与替换的过程：

        解析字符串：它会从左到右扫描你写的格式字符串。

        识别指令：一旦遇到 % 字符，它就知道后面跟着的是一个“取数指令”。//占位符

        提取数据：它根据指令去 std::tm 结构体对应的盒子里拿数据。

        原样输出：不是以 % 开头的字符（比如 -、: 或空格），它会原封不动地直接打印出来。
        */
    }


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



