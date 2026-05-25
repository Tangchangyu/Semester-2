#pragma once
#include<string>
#include<iostream>
#include<vector>
using std::cout;
using std::vector;
using std::string;
class FoodItem {
public:
	string m_id;
	string m_name;
	float m_fPrice;

	void print()const {
		cout << m_name << "\t" << m_fPrice << std::endl;
	}
	FoodItem(string id, string name, float Price) :m_id(id), m_name(name), m_fPrice(Price) {};
};

class Order {
protected:
	vector<FoodItem> items;
	double fee = 0;
	int iNum = 0;
public:
	Order(){};
	virtual ~Order() = 0;

	void AddItem(const FoodItem& f) {
		items.push_back(f);
		iNum++;
	}
	virtual double GetTotalFee() {
		for (int i = 0; i < iNum; i++) {
			fee += items[i].m_fPrice;
		}//?如何表示
		return fee;
	}

	virtual void PrintOrder() const {
		for (int i = 0; i < iNum;i++) {
			cout << "i+1";
			items[i].print();
		}
	
	};
};


Order::~Order() {};

class LocalOrder :public Order {
public:

	LocalOrder(){};
	
	virtual double GetTotalFee() {
		Order::GetTotalFee();
		if (fee >= 100) {
			fee = fee * 0.9;
		}

		return fee;
	}

	virtual void PrintOrder() {
		cout << "This is a local order:\nThe ordered items are:\n";
		Order::PrintOrder();
		cout << "Order TotalFee:" << GetTotalFee();
	}
};

class NetOrder :public Order {
	float deliverFee = 0;
public:

	void SetDeliverCost(float i) {
		deliverFee = i;

	}
	virtual double GetTotalFee() {
		Order::GetTotalFee();
		fee += deliverFee;
		return fee;
	}

	virtual void PrintOrder() {
		cout << "This is a net order:\nThe ordered items are:\n";
		Order::PrintOrder();
		cout << "Order TotalFee:" << GetTotalFee();
	}

};