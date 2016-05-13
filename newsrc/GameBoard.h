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
	//bool removeChar(int posX, int posY);
	//bool moveChar(int fromX, int fromY, int toX, int toY);
	//Character *getChar(int posX, int posY);
	//void render() const;
	//Game *getGame();
	void command(Game game);
	void display(Game game);
	void initialise();
	int characterCost(string name);
	void notEnoughCost(Game game);
	void askGrid(Game game, string character);
private:
	Character **board;

	int table[6][10];
};
#endif
