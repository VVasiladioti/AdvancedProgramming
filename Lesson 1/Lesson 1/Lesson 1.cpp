// Lesson 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << "Hello" << ' ' << "World" << "\n";
	cout << "What is your name ?" << "\n";
	string name;
	cin >> name;
	cout << "Hello " << name << "\n";

	cout << "Please give one number" << "\n";
	int a;
	cin >> a;
	cout << "Please give another number" << "\n";
	int b;
	cin >> b;
	cout << "Their sum is " << a + b << "\n";
	cout << "Their product is " << a * b << "\n";


	std::cout << "What is 7.2 + 2?" << "\n";
	double x;
	cin >> x;
	cout << "Your answer is " << x << "\n";
	if (x == 9.2) {
		bool x = true;
		cout << "The input is correct " << x << "\n";
		char mark = 'A';
		cout << "Your mark is " << mark << "\n";
	}
	else {
		bool x = false;
		cout << "The input is incorrect " << x << "\n";
		char mark = 'F';
		cout << "Your mark is " << mark << "\n";
	}

	return 0;
}