#include<string>

#include <fstream>

#include<iostream>
using namespace std;

int main() {
	cout << "请输入一串数据\n";

	fstream out("info.txt", ios::out);//多模式用按位或(|),不用逻辑或(||)
	
	if (!out ){
		cerr <<"无法打开文件进行写入!"<<std::endl;
		return 1;
	}
	string infomation;
	while (cin >> infomation) {
		out << infomation<<"\n";
		
	
	};

	out.close();

	fstream in("info.txt", ios::in);
	if (!in){
		cerr<<"无法打开文件进行读入!"<<std::endl;
		return 1;
	}
	while (in >> infomation) {
		cout << infomation<<endl;
	}
	in.close();




}