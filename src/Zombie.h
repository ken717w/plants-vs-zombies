#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include "Character.h"
using namespace std;

class Zombie : public Character {
public:
	Zombie();
	bool attack() const;
	bool move();
private:
	double speed;
};
#endif
