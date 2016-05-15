#include "Game.h"
#include "GameBoard.h"
#include "conio.h"
#include "iostream"

int main(){
	bool n = true;

	/*loop for the game*/
	while (n){
		system("cls");
		bool m = true;

		/*start of the game*/
		Game PlantVSZombie;
		PlantVSZombie.start();
		GameBoard board = GameBoard();

		/*loop for the comand*/
		while (m)
		{
			system("cls");
			board.display(PlantVSZombie);
			board.command(PlantVSZombie);

			/*determine the game is end or not*/
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