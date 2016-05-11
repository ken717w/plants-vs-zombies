#include "BonkChoy.h"
using namespace std;

BonkChoy::BonkChoy() : Plant() {
	hp = Character::HP_NORMAL;
	damage = Character::DAMAGE_HEAVY;
	cost = Character::COST_NORMAL;
	abbr = "BZ";
	range = Plant::RANGE_SHORT;
}
