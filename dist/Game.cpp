#include <stdio.h>
#include "iostream"
#include <conio.h>
#include <stdlib.h>
#include "Game.h"
#include "GameBoard.h"



using namespace std;

Game::Game() {
	
}

/*to start the game(play or exit)*/
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
			hom.setName(humanPlayer->getName());
			humanPlayer = &hom; 
			comPlayer = &zom;
			humanPlayer->role = true;
		}
		else{
			zom.setName(humanPlayer->getName());
			humanPlayer = &zom;
			comPlayer = &hom;
			humanPlayer->role = false;
		}
		system("cls");


	}
}

/*return true if the player want to play again,false if the player donot want to play again*/
bool Game::again(){
	
		printf("\nDo you want to Play again?(y/n)\n");
		char c = _getch();
		while ((c != 'y') && (c != 'n')){
			c = _getch();
		}
		if (c == 'n') return false; else return true;
	
	
}

/*return true if the game is end(homeowner's hp is <=0/currentround ==round),false if the game is not end*/
bool Game::end(){
	printf("Current round NO is %d\n", currentRound);
	_getch();
	if (humanPlayer->role){
		if (humanPlayer->getHP() <= 0) {
			cout << humanPlayer->getName() << ", you lose!"; return true;
		}
		if (round == currentRound) { 
			cout << humanPlayer->getName() << ", you win!"; return true; 
		}
	}
	else{
		if (comPlayer->getHP() <= 0) {
			cout << humanPlayer->getName() << ", you win!"; return true;
		}
		if (round == currentRound) {
			cout << humanPlayer->getName() << ", you lose!"; return true;
		}
	}
	currentRound= currentRound + 1;
	return false;
}


