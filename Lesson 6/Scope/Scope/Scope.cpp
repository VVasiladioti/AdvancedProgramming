// Scope.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

namespace some_namespace {
	void some_function() {
		int a = 400;
		char letter = 'b';
		cout << "Inside first name space" << "\n";
	}
}

namespace some_other_namespace {
	void some_function() {
		int a = 400;
		char letter = 'b';
		cout << "Inside second name space" << "\n";
	}
}

int global_variable = 50;

int main() {
	some_namespace::some_function();
	some_other_namespace::some_function();
	cout << "global variable contains the value " << global_variable << "\n";

	int a = 100;
	int* b;
	
	{
		int a = 200;
		cout << "the value in a is " << a << "\n";
		int* local_ptr = new int(300);
		b = local_ptr;
	}

	cout << "the value in a is " << a << "\n";

	cout << "the value pointed to by 'b' is " << *b << "\n";
	delete b;
	b = NULL;

	std::cout << "output some data" << "\n";

	int variable = 5;
	cout << "Global variable is " << variable << "\n";

	{
		int variable = 5;
		cout << "Local variable is " << variable << "\n";
	}

	return 0;
}

