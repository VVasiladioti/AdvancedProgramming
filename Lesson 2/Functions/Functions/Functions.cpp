// Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int add(int x, int y) {

	return x + y;
}

int minus(int x, int y);

int main() {

	int a, b, c, exit;

	cout << "Please type in a number" << "\n";
	cin >> a;

	cout << "Please type in another number" << "\n";
	cin >> b;

	c = add(a, b);

	cout << a << '+' << b << '=' << c << "\n";

	int product(int a, int b);
	cout << "Product = " << a * b << "\n";

	int quotient(int a, double b);
	cout << "Quotient = " << a / (double) b << "\n";

	cout << "Enter another number to exit" << "\n";

	cin >> exit;

	return 0;
}


int minus(int x, int y) {

	return x - y;
}



