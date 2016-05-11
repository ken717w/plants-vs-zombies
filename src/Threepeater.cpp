#include "Threepeater.h"
using namespace std;

Threepeater::Threepeater() : Plant() {
	hp = Character::HP_LOW;
	damage = Character::DAMAGE_HEAVY;
	cost = Character::COST_HIGH;
	abbr = "BZ";
	range = Plant::RANGE_LONG;
}
