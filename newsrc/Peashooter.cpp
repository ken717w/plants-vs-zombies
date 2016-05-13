#include "Peashooter.h"
using namespace std;

Peashooter::Peashooter() : Plant() {
	hp = Character::HP_LOW;
	damage = Character::DAMAGE_NORMAL;
	cost = Character::COST_LOW;
	abbr = "PS";
	range = Plant::RANGE_LONG;
}
