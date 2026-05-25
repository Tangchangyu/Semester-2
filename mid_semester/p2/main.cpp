#include"student.h"
#include<iostream>
#include<string>

int main() {
	using namespace std;

	Student stu1("2024001", "张三");
	stu1.addCourse(Course("CS101", "C++程序设计", 4.0, 95.0));

	Student stu2("2024002", "李四");
	stu2.addCourse(Course("CS101", "C++程序设计", 4.0, 82.0));
	stu2.addCourse(Course("MA102", "高等数学", 5.0, 77.0));

	Student stu3("2024003" , "王五");
	stu3.addCourse(Course("CS101", "C++程序设计", 4.0, 76.0));
	stu3.addCourse(Course("MA102", "高等数学", 5.0, 88.0));
	stu3.addCourse(Course("EN103", "大学英语", 2.0, 92.0));

	cout << stu1 << endl;
	cout << stu2 << endl;
	cout << stu3 << endl;

}