#ifndef HOMEOWNER_H
#define HOMEOWNER_H

#include "Player.h"
using namespace std;

class Homeowner : public Player{
public:
	Homeowner();
	int getSun();
	virtual int getHP();
	void addSun();
	void deductSun(int cost);
	virtual void deductHP(int damage);
	void initialise();
	virtual int getCost();
	virtual bool getCommand();
	virtual string create();	
	virtual void deductCost(int cost);
	virtual void addCost();
	virtual void updateSunflower(int NO);
private:
	int HP;
	int sun;
	int sunFlower;
	const int addSunFlowerRatio = 1;
};
#endif