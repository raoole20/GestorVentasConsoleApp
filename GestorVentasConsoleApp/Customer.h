#include <iostream>
#ifndef CUSTOMERS_H
#define CUSTOMERS_H

using namespace std;

class Customers
{
public:
	Customers() {}
	string getName();
	void display();
private:
	string name;
};

#endif // !CUSTOMERS_H