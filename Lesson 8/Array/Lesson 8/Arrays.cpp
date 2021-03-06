// Lesson 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

//Ex.1
char print_name(){
	for (int i = 0; i < 30; i++) {
		char name[30] = { 'V','a','s','i','l','i','k','i',' ','A','n','a','s','t','a','s','i','a',' ','V','a','s','i','l','a','d','i','o','t','i' };
		cout << "Your name is: " << name[i] << "\n";
	}
	return 0;
}

//Ex.2
char print_name_heap() {
	char *first = new char[18];
	char name[30] = { 'V','a','s','i','l','i','k','i',' ','A','n','a','s','t','a','s','i','a',' ','V','a','s','i','l','a','d','i','o','t','i' };
	for (int i = 0; i < 18; i++) {
		first[i] = name[i];
		cout << "Your name is: " << first[i] << "\n";
	}
	char *last = new char[12];	
	for(int i = 0; (i + 18) < 30; i++){
		last[i] = name[i+18];
		cout << "Your name is: " << last[i] << "\n";
	}
	delete[] first;
	delete[] last;
	return 0;
}

float calc_avg(const int* arr, const int val) {
	int sum = 0;

	for (int i = 0; i < val; ++i)
		sum += arr[i];

	return (sum / (float)val);
}

float calc_avg(const int* arr, const int val);

int main(void) {

	
	const int CONST_VALUE = 3;
	float ave;

	// stack based 1-d arrays
	int array_nums[CONST_VALUE] = { 2, 4, 5 };

	// print out the first element
	cout << "value at index 0 is " << array_nums[0] << "\n";

	//stack based 2-d arrays
	char naughts_n_xs[3][3];

	// set the middle square to x
	naughts_n_xs[1][1] = 'X';

	//arrays on the heap 1-d
	int* sum = new int[CONST_VALUE];

	for (int i = 0; i < CONST_VALUE; ++i)
	{
		cout << "enter a value...\n";
		cin >> sum[i];
	}

	ave = calc_avg(sum, CONST_VALUE);

	cout << "the average is " << ave << "\n";

	delete[] sum;

	print_name();
	print_name_heap();

	return 0;
}
