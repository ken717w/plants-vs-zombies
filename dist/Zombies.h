#ifndef ZOMBIES_H
#define ZOMBIES_H

#include "Player.h"
using namespace std;

class Zombies : public Player{
public:
	Zombies();
	int getCoins();
	void addCoins();
	void deductCoins(int cost);
	void initialise();
	virtual int getHP();
	virtual void deductHP(int damage);
	virtual int getCost();
	virtual bool getCommand();
	virtual string create();
	virtual void deductCost(int cost);
	virtual void addCost();
	virtual void updateSunflower();
private:
	int coins;

};
#endif