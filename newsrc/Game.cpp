#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Game.h"

#include "GameBoard.h"



using namespace std;

Game::Game() {
	
}

void Game::start() {
	printf("Would you like to play ¡§Plant vs.Zombie¡¨ (y/n)\n");
	char c = _getch();
	while  ((c != 'y') && (c != 'n')) {
		c = _getch();
	}
	if (c == 'n') {
		exit(0);
	}
	else{
		
		humanPlayer->verifyName();
		humanPlayer->roleChoosing();
		
		if (humanPlayer->role) { 
			humanPlayer = &hom; 
			comPlayer = &zom;
			humanPlayer->role = true;
		}
		else{
			humanPlayer = &zom;
			comPlayer = &hom;
			humanPlayer->role = false;
		}
		system("cls");
		updatePlayer();

	}
}


int Game::getHomeownerHP(){ return homeownerHP; }

int Game::getHomeownerSun(){ return homeownerSun; }

int Game::getZombiesCoins(){ return zombiesCoins; }

void Game::updatePlayer(){
	if (humanPlayer->role) {
		homeownerHP = humanPlayer->getHP();
		homeownerSun = humanPlayer->getCost();
		zombiesCoins = comPlayer->getCost();
	}
	else{
		homeownerHP = comPlayer->getHP();
		homeownerSun = comPlayer->getCost();
		zombiesCoins = humanPlayer->getCost();
	}
}

bool Game::getcommand(){
	return true;
}

/*int Game::getRound() const {
	return this->round;
}

int Game::getCurrentRound() const {
	return this->currentRound;
}
*/