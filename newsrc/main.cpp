#include "Game.h"
#include "GameBoard.h"
#include "conio.h"

int main(){
	Game PlantVSZombie;
	PlantVSZombie.start();
	GameBoard board = GameBoard();
	board.display(PlantVSZombie);
	board.command(PlantVSZombie);
	return 0;
}