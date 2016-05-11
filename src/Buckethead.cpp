#include "Buckethead.h"
using namespace std;

Buckethead::Buckethead() : Zombie() {
	hp = Character::HP_HIGH;
	damage = Character::DAMAGE_NORMAL;
	cost = Character::COST_HIGH;
	abbr = "BH";
	speed = Zombie::SPEED_NORMAL;
}
