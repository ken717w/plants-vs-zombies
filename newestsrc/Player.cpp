#include "Player.h"
#include <iostream>
#include <conio.h>
using namespace std;

Player::Player() {
	
}

string Player::getName() const {
	return name;
}

void Player::setName(string name) {
	this->name = name;
}

void Player::verifyName() {
	string c;
	system("cls");
	printf("What is your name?\n");
	getline(cin, c);
	bool notPass=true;
	while (notPass){
		for (int i = 0; i <= c.length() - 1; i++){
			if (((c[i] >= 'a') && (c[i] <= 'z')) || ((c[i] >= 'A') && (c[i] <= 'Z'))){
				notPass = false;
				break;
			}

		}
		if (notPass) {
			printf("Please at least contain one alphabet in your name.\n");
			getline(cin, c);
		}
	}

	setName(c);
}

void Player::roleChoosing(){
	system("cls");
	printf("Which role do you want to be?(h for Homeowner/ z for zombie)\n");
	char c = _getch();
	while ((c != 'h') && (c != 'z')) {
		c = _getch();
	}
	if (c == 'h') role = true;
	if (c == 'z') role = false;
}

int Player::getHP(){ return 0; }

int Player::getCost(){ return 0; }

bool Player::getCommand(){ return true; }

string Player::create(){
	return NULL;
	
}

void Player::deductCost(int cost){}

void Player::deductHP(int damage){}

void Player::addCost(){}

void Player::updateSunflower(int NO){}

