#include "Player.h"
#include <iostream>
#include <conio.h>
using namespace std;

Player::Player() {
	
}

/*return the name of the player*/
string Player::getName() const {
	return name;
}

/*to set the name of the player*/
void Player::setName(string name) {
	this->name = name;
}

/*to verify the name of the player*/
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

/*to know the role of the player want to be*/
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

/*to get the HP of the player(virtual)*/
int Player::getHP(){ return 0; }

/*to get the number of sun or coins of the player(virtual)*/
int Player::getCost(){ return 0; }

/*to get the command of the player(virtual)*/
bool Player::getCommand(){ return true; }

/*to create character(virtual)*/
string Player::create(){
	return NULL;
	
}

/*to dedcut the sun or coins of the player(virtual)*/
void Player::deductCost(int cost){}

/*to deduct the HP of the player(virtual)*/
void Player::deductHP(int damage){}

/*to increase the number of sun or coins of the player(virtual)*/
void Player::addCost(){}

/*to update the sunflower*/
void Player::updateSunflower(int NO){}

