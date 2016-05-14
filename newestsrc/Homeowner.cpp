#include "Homeowner.h"
#include "conio.h"

using namespace std;

Homeowner::Homeowner(){
	initialise();
}

int Homeowner::getSun(){
	return sun;
}

int Homeowner::getHP(){
	return HP;
}

void Homeowner::addSun(){
	sun = sun + addCostNO + sunFlower*addSunFlowerRatio;
}

void Homeowner::deductSun(int cost){
	sun = sun - cost;
}

void Homeowner::deductHP(int damage){
	HP = HP - damage;
}

void Homeowner::initialise(){
	HP = 20;
	sun = 2;
	sunFlower = 0;
}

int Homeowner::getCost(){ return getSun(); }

bool Homeowner::getCommand(){
	printf("Do you want to plant?(y/n)\n");
	char c = _getch();
	while ((c != 'y') && (c != 'n')){
		c = _getch();
	}
	if (c == 'y') return true; else return false;
}

string Homeowner::create(){
	printf("Which plant do you want to plant?\n1. Peashooter(1 sun)\n2. Bonk Choy(2 sun)\n3. Threepeater(3 sun)\n4. Wall-nut(2 sun)\n5. Sunflower(1 sun)\n");
	char c = _getch();
	while ((c != '1') && (c != '2') && (c != '3') && (c != '4') && (c != '5')){
		c = _getch();
	}
	
	if (c == '1') return "PS";
	if (c == '2') return "BC";
	if (c == '3') return "TP";
	if (c == '4') return "WN";
	if (c == '5') return "SF";

}

void Homeowner::deductCost(int cost){
	deductSun(cost);
}

void Homeowner::updateSunflower(int NO){
	sunFlower = NO;
}

void Homeowner::addCost(){
	addSun();
}




