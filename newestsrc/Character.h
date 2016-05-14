#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
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
	static const int RANGE_LONG = 2;
	static const int RANGE_SHORT = 1;
	static const int RANGE_NONE = 0;
	static const int SPEED_FAST = 3;
	static const int SPEED_NORMAL = 2;
	static const int SPEED_SLOW = 1;
	

	Character();
	int getHp() const;
	void deductHp(int damage);
	int getDamge() const;
	int getCost() const;
	string getAbbr() const;
	int getRange() const;
	int getSpeed() const;
protected:
	int hp;
	int damage;
	int cost;
	string abbr;
	int range;
	int speed;
};
#endif
