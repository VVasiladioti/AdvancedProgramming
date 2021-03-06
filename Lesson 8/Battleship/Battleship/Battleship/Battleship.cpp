// Battleship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//Initialize default variables
   //Create game board
bool battleground[5][5];
void createboard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			battleground[i][j] = false;
		}
	}
}
//Place ship
void placeship() {
	srand(time(0));
	int shiporientation, positionX, positionY;
	shiporientation = rand() % 2; //horisontal=0 vertical=1
	cout << shiporientation << endl;

	if (shiporientation == 0) {
		positionX = rand() % 5;
		cout << positionX << endl;
		positionY = rand() % 3;
		cout << positionY << endl;
		battleground[positionX][positionY] = true;
		battleground[positionX][positionY + 1] = true;
		battleground[positionX][positionY + 2] = true;
	}
	else {
		positionX = rand() % 3;
		cout << positionX << endl;
		positionY = rand() % 5;
		cout << positionY << endl;
		battleground[positionX][positionY] = true;
		battleground[positionX + 1][positionY] = true;
		battleground[positionX + 2][positionY] = true;
	}
}
void playgame() {
	int x, y;
	int	guesses = 5;
	int damage = 0;
		
	while (guesses > 0) {
		cout << "You have " << guesses << " guesses left" << endl;
		cout << "Where do you want to hit on x-axis?" << endl;
		cin >> x;
		cout << "Where do you want to hit on y-axis?" << endl;
		cin >> y;

		if (battleground[x][y] == true) {
			cout << "That's a hit!" << endl;
			damage++;
			cout << damage << endl;
		}
		else {
			cout << "You missed!" << endl;
		}
		guesses--;
	}

	if (guesses == 0) {
		cout << "No more guesses, you lose" << endl;
	}
	if (damage == 3) {
		cout << "You win!!!" << endl;
		//cout << "Want to play again?" << endl;
	}
}

int main() {
	createboard();
	placeship();
	playgame();


   //Game Loop Start
	 //Player X inputs valid attack grid
	 // Check to see if attack is a hit
	 // Remove/add damage to hit ship
	 // Redraw game board
	 // Check to see if game is over
		 // If game over - exit loop/end program
	 
   //Game Loop Return
	return 0;
}

