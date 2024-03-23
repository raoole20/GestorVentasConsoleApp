#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Customer.cpp"

using namespace std;

class App
{
public:
	App();
	void init();
	void killApp();
	void showMenu();
	void printSeparator(int type = 0);
	void printTitle(string message);
	void printIntegrators();
private:
};

#endif APP_H
