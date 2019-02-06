// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int x = 5;
int y = 3;
int *a = &x;
int *b = &y;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void fun() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i;
	for (i = 0; i < 10; i++) {
		if (arr[i] % 2 == 0) {
			cout << *(arr + i) << " is an even nember" << "\n";
		}

	}
	return;
}

int main() {

	swap(*a, *b);
	cout << "The value of x is " << *a << "\n";
	cout << "The value of y is " << *b << "\n";
	fun();

	return 0;
}