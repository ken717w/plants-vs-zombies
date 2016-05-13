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
	void deductHP(int damage);
	void initialise();
	virtual int getCost();
	virtual bool getCommand();
	virtual string create();	
	virtual void deductCost(int cost);
private:
	int HP;
	int sun;
	int sunFlower;
	const int addSunNO = 2;
	const int addSunFlowerRatio = 1;
};
#endif