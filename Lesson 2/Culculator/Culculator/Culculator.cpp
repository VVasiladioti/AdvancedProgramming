// Culculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int add(int x, int y) {

	return x + y;
}

int substract(int x, int y) {

	return x - y;
}

int multiply(int x, int y) {

	return x * y;
}

int divide(int x, int y) {

	return x / y;
}
int main() {

	int a, b, c, exit;
	char operat;

	cout << "Please type in a number" << "\n";
	cin >> a;

	cout << "Please type in another number" << "\n";
	cin >> b;

	cout << "Please type a mathematical operator" << "\n";
	cin >> operat;

	switch (operat) {
	case '+':
		c = add(a, b);
		cout << a << '+' << b << '=' << c << "\n";
		break;
	case '-':
		c = substract(a, b);
		cout << a << '-' << b << '=' << c << "\n";
		break;
	case '*':
		c = multiply(a, b);
		cout << a << '*' << b << '=' << c << "\n";
		break;
	case '/':
		c = divide(a, b);
		cout << a << '/' << b << '=' << c << "\n";
		break;
	
	default:
		cout << "Invalid operator" << endl;
	}
	
	cout << "enter another number to exit" << "\n";

	cin >> exit;

	return 0;
}

