// Memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	int a;

	int* b;

	a = 100;

	b = new int;

	cout << "The pointer b points to the memory address " << b << " located on the heap\n";
	cout << "The value in memory location b is " << *b << "\n";

	*b = a;

	cout << "The value of stack variable a is " << a << "\n";
	cout << "The 'heap' memory pointed to by b contains " << *b << "\n";

	delete b;
	b = NULL;

	//Ex.3
	char A = '1';
	string* B;

	B = new string;
	*B = A;

	cout << "The value of stack variable A is " << A << "\n";
	cout << "The 'heap' memory pointed to by B contains " << *B << "\n";

	delete B;
	B = NULL;

	return 0;

	//Ex.4
	int* C = new int[10];
	delete [] C;
}