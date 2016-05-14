#include "Conehead.h"
using namespace std;

Conehead::Conehead() : Zombie() {
	hp = Character::HP_NORMAL;
	damage = Character::DAMAGE_HEAVY;
	cost = Character::COST_NORMAL;
	abbr = "CH";
	speed = Character::SPEED_SLOW;
}
