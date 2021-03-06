// References.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void swap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap_ref(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

//Ex.4
void swap_char(char& x, char& y) {
	char temp = x;
	x = y;
	y = temp;
}

//Ex.5
int sorting(int nums[]) {
	int i, j, temp;
	for (i = 0; i < 10; i++) {
		for (j = i + 1; j < 10; j++) {

			if (nums[j] < nums[i]) {
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	cout << "Elements of array in sorted ascending order:" << "\n";
	for (i = 0; i < 10; i++) {
		cout << nums[i] << "\n";
	}
	return 0;
}

int sorting2(int nums[]) {
	int i, j, temp;
	for (i = 0; i < 10; i++) {
		for (j = i + 1; j < 10; j++) {

			if (nums[j] < nums[i]) {
				swap_ref(nums[i], nums[j]);
			}
		}
	}
	cout << "Elements of array in sorted ascending order:" << "\n";
	for (i = 0; i < 10; i++) {
		cout << nums[i] << "\n";
	}
	return 0;
}

int main() {
	int a, b;

	cout << "Please type in a number" << "\n";
	cin >> a;
	cout << "Please type in another number" << "\n";
	cin >> b;

	cout << "before swap, a = " << a << " and b = " << b << "\n";
	swap(a, b);
	cout << "after swap (by value), a = " << a << " and b = " << b << "\n";
	swap(&a, &b);
	cout << "after swap by pointer reference, a = " << a << " and b = " << b << "\n";

	swap_ref(a, b);
	cout << "after swap using references, a = " << a << " and b = " << b << "\n";

	int& a_ref = a;

	char c, d;
	cout << "Please type in a character" << "\n";
	cin >> c;
	cout << "Please type in another character" << "\n";
	cin >> d;
	
	swap_char(c, d);
	cout << "after swap using references, c = " << c << " and d = " << d << "\n";
	

	int nums[10] = {7, 3, 5, 2, 1, 4, 6, 9, 10, 8};
	sorting2(nums);

	return 0;
}
