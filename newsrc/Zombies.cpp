#include "Zombies.h"
#include "conio.h"

using namespace std;

Zombies::Zombies(){
	initialise();
}

int Zombies::getCoins(){
	return coins;
}

void Zombies::addCoins(){
	coins = coins + addCoinsNO;
}

void Zombies::deductCoins(int cost){
	coins = coins - cost;
}

void Zombies::initialise(){
	coins = 5;
}

int Zombies::getCost(){
	return getCoins();
}

int Zombies::getHP(){ return 0; }

bool Zombies::getCommand(){
	printf("Do you want to create Zombies?(y/n)\n");
	char c = _getch();
	while ((c != 'y') && (c != 'n')){
		c = _getch();
	}
	if (c == 'y') return true; else return false;
}

string Zombies::create(){
	printf("Which Zombie do you want to create?\n1. Basic Zombie\n2. Buckethead\n3. Football\n4. Conehead\n");
	char c = _getch();
	while ((c != '1') && (c != '2') && (c != '3') && (c != '4')){
		c = _getch();
	}
	if (c == '1') return "BZ";
	if (c == '2') return "BH";
	if (c == '3') return "FB";
	if (c == '4') return "CH";
}

void Zombies::deductCost(int cost){
	deductCoins(cost);
}

