#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Character.h"
using namespace std;

class Zombie : public Character {
public:
	static const int SPEED_FAST = 3;
	static const int SPEED_NORMAL = 2;
	static const int SPEED_SLOW = 1;

	Zombie();
	bool attack() const;
	bool move();
protected:
	double speed;
};
#endif
