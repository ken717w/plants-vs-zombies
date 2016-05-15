#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include  "BasicZombie.h"
#include  "BonkChoy.h"
#include  "Buckethead.h"
#include "Conehead.h"
#include "Football.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include  "Threepeater.h"
#include  "WallNut.h"
#include "Game.h"

using namespace std;

class GameBoard {
public:
	GameBoard();
	void insertChar(string character, int x, int y);
	void command(Game game);
	void display(Game game);
	void initialise();
	int characterCost(string name);
	void notEnoughCost(Game game);
	void askGrid(Game game, string character);
	void AISystem(Game game);
	bool zombieHaveEmpty();
	bool homeownerHaveEmpty();
	bool homeownerHaveEnemy(Game game);
	void plantAttack(Game game);
	void zombieMove(Game game);
	void zombieAttack(Game game);
	void addcost(Game game);
	int sunflowerNO();
private:
	Character **board;

	int table[6][10];
};
#endif
