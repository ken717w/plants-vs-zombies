#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "GameBoard.h"
using namespace std;

class Character {
public:
	static const int HP_HIGH = 3;
	static const int HP_NORMAL = 2;
	static const int HP_LOW = 1;
	static const int DAMAGE_HEAVY = 3;
	static const int DAMAGE_NORMAL = 2;
	static const int DAMAGE_WEAK = 1;
	static const int DAMAGE_NONE = 0;
	static const int COST_HIGH = 3;
	static const int COST_NORMAL = 2;
	static const int COST_LOW = 1;

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
protected:
	int hp;
	int damage;
	int cost;
	string abbr;
	GameBoard *board;
	int posX, posY;
};
#endif
