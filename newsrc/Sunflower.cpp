#include "Sunflower.h"
using namespace std;

Sunflower::Sunflower() : Plant() {
	hp = Character::HP_LOW;
	damage = Character::DAMAGE_NONE;
	cost = Character::COST_LOW;
	abbr = "SF";
	range = Plant::RANGE_NONE;
}
