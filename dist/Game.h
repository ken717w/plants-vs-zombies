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
	bool end();
	bool again();
	
private:
	int round = 20;
	int currentRound = 1;
	
};
#endif
