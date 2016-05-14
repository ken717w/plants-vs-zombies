#include "Character.h"
using namespace std;

Character::Character() {

}

int Character::getHp() const {
	return this->hp;
}

void Character::deductHp(int damage){
	this->hp -= damage;
}

int Character::getCost() const {
	return this->cost;
}

string Character::getAbbr() const {
	return this->abbr;
}

int Character::getRange() const{
	return this->range;
}

int Character::getDamge() const{
	return this->damage;
}

int Character::getSpeed() const{
	return this->speed;
}
