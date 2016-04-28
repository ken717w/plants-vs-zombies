#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "GameBoard.h"
using namespace std;

class Character {
public:
	Character();
	int getHp() const;
	bool deductHp(int damage);
	void destroy();
	virtual bool attack() const;
	int getCost() const;
	string getAbbr() const;
	int getPosX() const;
	int getPosY() const;
	bool setPosition(int x, int y);
	void setBoard(GameBoard *board);
private:
	int hp;
	int damage;
	int cost;
	string abbr;
	GameBoard *board;
	int posX, posY;
};
#endif
