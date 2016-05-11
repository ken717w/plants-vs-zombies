#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Character.h"
#include "Game.h"
using namespace std;

class GameBoard {
public:
	GameBoard();
	bool insertChar(Character *character, int posX, int posY);
	bool removeChar(int posX, int posY);
	bool moveChar(int fromX, int fromY, int toX, int toY);
	Character *getChar(int posX, int posY);
	void render() const;
	Game *getGame();
private:
	Character **board;
	Game *game;
};
#endif
