#include "BasicZombie.h"
using namespace std;

BasicZombie::BasicZombie() : Zombie() {
	hp = Character::HP_NORMAL;
	damage = Character::DAMAGE_NORMAL;
	cost = Character::COST_LOW;
	abbr = "BZ";
	speed = Character::SPEED_NORMAL;
}
