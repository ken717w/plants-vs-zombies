#include "Game.h"
#include "GameBoard.h"
#include "conio.h"
#include "iostream"

int main(){
	bool n = true;
	while (n){
		system("cls");
		bool m = true;
		Game PlantVSZombie;
		PlantVSZombie.start();
		GameBoard board = GameBoard();

		while (m)
		{
			system("cls");
			board.display(PlantVSZombie);
			board.command(PlantVSZombie);
			if (PlantVSZombie.end()) { 
				if (!PlantVSZombie.again()) n=false;
				m = false;
			}
			else{
				board.addcost(PlantVSZombie);
			}
		}
	}
}