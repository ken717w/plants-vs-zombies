#include "Football.h"
using namespace std;

Football::Football() : Zombie() {
	hp = Character::HP_HIGH;
	damage = Character::DAMAGE_WEAK;
	cost = Character::COST_HIGH;
	abbr = "FB";
	speed = Character::SPEED_FAST;
}
