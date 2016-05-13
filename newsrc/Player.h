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
	virtual int getCost();
	virtual bool getCommand();
	bool role;
	virtual string create();
	virtual void deductCost(int cost);
protected:
	string name;
};
#endif
