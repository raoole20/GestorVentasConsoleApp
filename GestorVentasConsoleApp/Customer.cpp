#include <iostream>

using namespace std;

class Customers
{
public:
	Customers() {}
	void setName() { name = "Raul"; }
	string getName() { return name; };
	void display() {
		cout << "Nombre del usuario: " << this->name << endl;
	};
private:
	string name;
};