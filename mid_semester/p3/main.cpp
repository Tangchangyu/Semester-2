#include"Order.h"
#include<string>
#include<iostream>

using namespace std;

int main() {
	LocalOrder l;
	l.AddItem(FoodItem("101", "”„œ„»‚Àø", 32));
	l.AddItem(FoodItem("102", "Õ¡∂π≈£»‚", 42));
	l.AddItem(FoodItem("103", "∫Ï…’≈≈π«", 58));
	l.PrintOrder();

	NetOrder net;
	net.AddItem(FoodItem("101", "”„œ„»‚Àø", 32));
	net.AddItem(FoodItem("102", "Õ¡∂π≈£»‚", 42));
	net.AddItem(FoodItem("103", "∫Ï…’≈≈π«", 58));
	net.PrintOrder();

}