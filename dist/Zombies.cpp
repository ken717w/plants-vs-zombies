#include "Zombies.h"
#include "conio.h"

using namespace std;

Zombies::Zombies(){
	initialise();
}

/*return the number of coins of the player*/
int Zombies::getCoins(){
	return coins;
}

/*to increase the number of coins of the player*/
void Zombies::addCoins(){
	coins = coins + addCostNO;
}

/*to decrease the number of coins of the player*/
void Zombies::deductCoins(int cost){
	coins = coins - cost;
}

/*to initialise the status of the zombies*/
void Zombies::initialise(){
	coins = 2;
}

/*return the number of coins of the player*/
int Zombies::getCost(){
	return getCoins();
}

/*return the HP of the player*/
int Zombies::getHP(){ return 0; }

/*return true if the player want to create zombie,false if not*/
bool Zombies::getCommand(){
	printf("Do you want to create Zombies?(y/n)\n");
	char c = _getch();
	while ((c != 'y') && (c != 'n')){
		c = _getch();
	}
	if (c == 'y') return true; else return false;
}

/*return the abbreviation of the zombie that the zombies want to create*/
string Zombies::create(){
	printf("Which Zombie do you want to create?\n1. Basic Zombie(1 coin)\n2. Buckethead(3 coins)\n3. Football(3 coins)\n4. Conehead(2 coins)\n");
	char c = _getch();
	while ((c != '1') && (c != '2') && (c != '3') && (c != '4')){
		c = _getch();
	}
	if (c == '1') return "BZ";
	if (c == '2') return "BH";
	if (c == '3') return "FB";
	if (c == '4') return "CH";
}

/*to decrease the number of coins of the player*/
void Zombies::deductCost(int cost){
	deductCoins(cost);
}

/*to deduct HP of the player*/
void Zombies::deductHP(int damage){};

/*to increase the number of coins of the player*/
void Zombies::addCost(){
	addCoins();
}

/*(virtual)*/
void Zombies::updateSunflower(){};
