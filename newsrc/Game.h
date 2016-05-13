#ifndef GAME_H
#define GAME_H

#include "Homeowner.h"
#include "Zombies.h"
using namespace std;

class Game {
public:
	Game();
	void start();
	Player *humanPlayer = new Player;
	Player *comPlayer = new Player;
	Zombies zom = Zombies();
	Homeowner hom = Homeowner();
	int getHomeownerHP();
	int getHomeownerSun();
	int getZombiesCoins();
	void updatePlayer();
	bool getcommand();
	//int getRound() const;
	//int getCurrentRound() const;
private:
	int homeownerHP;
	int homeownerSun;
	int zombiesCoins;
	bool command;
	//int round, currentRound;
	
};
#endif
