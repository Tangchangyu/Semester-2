#pragma once
#include<string>
#include<iostream>
#include<vector>
using std::cout;

using std::string;

class Course {
	string  id;
	string name;
	double xuefen;
	double grade;
	char getClass() const{
		if (grade >= 90) return 'A';
		else if (grade >= 80) return 'B';
		else if (grade >= 70) return 'C';
		else if (grade >= 60) return 'D';
		else if (grade >= 0) return 'E';
	}

public:
	Course(const string& id, const string& name, double xuefen, double grade) :id(id), name(name), xuefen(xuefen), grade(grade) {

	};

	void print()const {
		cout << "�γ̱�ţ�" << id << ", �γ����ƣ�" << name << "�� ѧ�֣�" << ", �ɼ���" << grade << "�� �ȼ���" << getClass();

	}//����γ���Ϣ��
};

class Student {
	string id;
	string sName;
	std::vector <Course> courses;
	int cnum = 0;//number of courses;
	static int count;

public:
	Student(const string& id, const string& sN) :id(id), sName(sN) { count++; }
	void addCourse(const Course& c) {
		Course nc = c;
		courses.push_back(nc);
		cnum++;
	}

	friend std::ostream& operator<<(std::ostream& os, const Student);
};

int Student::count = 0;

std::ostream& operator<<(std::ostream& os, const Student s) {
	os << "ѧ�ţ�" << s.id << ", ������" << s.sName << "\n";
	for (int i = 0; i < s.cnum; i++) {
		s.courses[i].print();
	}
	return os;
}

