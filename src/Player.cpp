#include "Player.h"
using namespace std;

Player::Player() {

}

string Player::getName() const {
	return name;
}

void Player::setName(string name) {
	this->name = name;
}
