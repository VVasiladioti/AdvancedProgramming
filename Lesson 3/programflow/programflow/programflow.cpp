// programflow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int add(int x, int y) {
	return x + y;
}


 /*  Ex.2
 int main(int a) {
	

	do {
		cout << "Please give a number" << "\n";
		cin >> a;

		if (a <0) {
			// terminate the loop
			break;
		}
	} while (a >= 0);
		
	return a;
}

*/
	/*  Ex.1
	int test(int a) {
	if (a >= 0) {
		bool b = true;
		cout << "The input is " << b << "\n";
	}
	else {
		bool b = false;
		cout << "The input is " << b << "\n";
	}
	return b;
	*/


/*

int fac(int x) {

	int facSum = 1;

	for (int count = x; count > 0; count--)
		facSum = facSum * count;

	return facSum;
}
*/

//Recursion
int fac(int x) {
	int facSum = 1;
	int i = x;
	i--;
	if (i > 0) {
		facSum = facSum * i;
	}
	return facSum;
}



int main() {


	int total = 0;

	int x;

	cout << "Please enter numbers, will finish if sum of factorals exceeds 2000" << "\n";

	while (total <= 2000) {
		cin >> x;
		total = add(fac(x), total);
	}

	cout << "The total is " << total << "\n";

	if (total > 3000)
		cout << "you overshot by a lot!" << "\n";
	else {
		cout << "You just went over" << "\n";
		cout << "Only over by " << total - 2000 << "\n";
	}

	cout << "enter a number to exit" << "\n";

	cin >> x;

	return 0;
}


