#include "Character.h"
using namespace std;

Character::Character() {

}

/*return the charcter's HP*/
int Character::getHp() const {
	return this->hp;
}

/*to deduct the charcter HP*/
void Character::deductHp(int damage){
	this->hp -= damage;
}

/*return the character's cost, sun for homeowner and coins for zombies*/
int Character::getCost() const {
	return this->cost;
}

/*return the abbreviation of the character*/
string Character::getAbbr() const {
	return this->abbr;
}

/*return the attack range of the charcter*/
int Character::getRange() const{
	return this->range;
}

/*return the damage of the character*/
int Character::getDamge() const{
	return this->damage;
}

/*to return the speed of the character*/
int Character::getSpeed() const{
	return this->speed;
}
