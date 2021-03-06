// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

class Enemy {
public:
	Enemy(int hps, int sf);
	~Enemy();
	int get_hit_points() const;
	int get_score() const;
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
private:
	int hit_points;
	int* score;
	int score_field;
};

Enemy::Enemy(int hps, int score_field) :
	hit_points(hps) {
	score = new int(0);
}


Enemy::~Enemy() {
	delete score;
}

int Enemy::get_hit_points() const {
	return hit_points;
}

int Enemy::get_score() const {
	return *score;
}

void Enemy::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}

void Enemy::set_score(const int new_score) {
	*score = new_score;
}

class Player {
public:
	Player(int hps, int sf);
	~Player();
	int get_hit_points() const;
	int get_score() const;
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
	string get_name() const;
	string set_name(string new_name);
private:
	int hit_points;
	int* score;
	int score_field;
	string *name;
};

Player::Player(int hps, int score_field) :
	hit_points(hps) {
	score = new int(0);
	name = new string();
}


Player::~Player() {
	delete score;
	delete name;
}

int Player::get_hit_points() const {
	return hit_points;
}

int Player::get_score() const {
	return *score;
}

void Player::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}

void Player::set_score(const int new_score) {
	*score = new_score;
}

string Player::get_name() const {
	return *name;
}

string Player::set_name(const string new_name) {
	*name = new_name;
	return *name;
}

int main(void) {

	Enemy e1(2,5);
	cout << "hit points = " << e1.get_hit_points() << "\n";

	Enemy* e2 = new Enemy(2,5);
	e2->set_hit_points(3);
	cout << "hit points = " << e2->get_hit_points() << "\n";

	e2->set_score(2);
	cout << "score = " << e2->get_score() << "\n";

	delete e2;
	e2 = NULL;

	Player* p2 = new Player(3,6);
	p2->set_name("Vassia");
	cout << "Player Name = " << p2->get_name() << "\n";

	delete p2;
	p2 = NULL;


	return 0;
}