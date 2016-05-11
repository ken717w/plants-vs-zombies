#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "Player.h"
using namespace std;

class Game {
public:
	Game();
	void start();
	int getRound() const;
	int getCurrentRound() const;
private:
	GameBoard *board;
	int round, currentRound;
	Player *humanPlayer, *comPlayer;
};
#endif
