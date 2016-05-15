#include "WallNut.h"
using namespace std;

WallNut::WallNut() : Plant() {
	hp = Character::HP_HIGH;
	damage = Character::DAMAGE_NONE;
	cost = Character::COST_NORMAL;
	abbr = "WN";
	range = Character::RANGE_NONE;
}
