#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
public:

	Player();
	string getName() const;
	void setName(string name);
	void verifyName();
	void roleChoosing();
	virtual int getHP();
	virtual void deductHP(int damage);
	virtual int getCost();
	virtual bool getCommand();
	bool role;
	virtual string create();
	virtual void deductCost(int cost);
	virtual void addCost();
	virtual void updateSunflower(int NO);
protected:
	string name;
	static const int addCostNO=2;
};
#endif
