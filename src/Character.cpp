#include <iostream>
#include "Character.h"
using namespace std;

Character::Character() {

}

int Character::getHp() const {
	return this->hp;
}

bool Character::deductHp(int damage) {
	this->hp -= damage;

	return this->hp > 0;
}

void Character::destroy() {
	this->board->removeChar(this->getPosX(), this->getPosY());

	delete this;
}

int Character::getCost() const {
	return this->cost;
}

string Character::getAbbr() const {
	return this->abbr;
}

int Character::getPosX() const {
	return this->posX;
}

int Character::getPosY() const {
	return this->posY;
}

bool Character::setPosition(int x, int y) {
	bool result = this->board->moveChar(this->getPosX(), this->getPosY(), x, y);

	if (result) {
		this->posX = x;
		this->posY = y;
	}

	return result;
}

void Character::setBoard(GameBoard *board) {
	this->board = board;
}
