#include "GameBoard.h"
#include "iostream"
#include "conio.h"

using namespace std;

GameBoard::GameBoard() {
	initialise();
}

void GameBoard::insertChar(string character, int x, int y) {
	if (character == "BZ") { table[x][y] = 2; BasicZombie BZ; board[x][y]=BZ; }
	if (character == "BC") { table[x][y] = 1; BonkChoy BC; board[x][y] = BC; }
	if (character == "BH") { table[x][y] = 2; Buckethead BH; board[x][y] = BH; }
	if (character == "CH") { table[x][y] = 2; Conehead CH; board[x][y] = CH; }
	if (character == "FB") { table[x][y] = 2; Football FB; board[x][y] = FB; }
	if (character == "PS") { table[x][y] = 1; Peashooter PS; board[x][y] =PS; }
	if (character == "SF") { table[x][y] = 1; Sunflower SF; board[x][y] = SF; }
	if (character == "TP") { table[x][y] = 1; Threepeater TP; board[x][y] = TP; }
	if (character == "WN") { table[x][y] = 1; BasicZombie WN; board[x][y] = WN; }
}


/*

bool GameBoard::removeChar(int posX, int posY) {
	// To be developed
	return false;
}

bool GameBoard::moveChar(int fromX, int fromY, int toX, int toY) {
	// To be developed
	return false;
}

Character *GameBoard::getChar(int posX, int posY) {
	// To be developed
	return NULL;
}

void GameBoard::render() const {
	// To be developed
}

Game *GameBoard::getGame() {
	// To be developed
	return NULL;
}
*/

void GameBoard::display(Game game) {
	for (int k = 1; k <= 10; k++){
		printf(" ");
	}
	for (int k = 1; k <= 51; k++){
		printf("-");
	}
	printf("\n");
	for (int i = 0; i <= 5; i++){
		if (i != 2){
			for (int k = 1; k <= 10; k++){
				printf(" ");
			}
			for (int j = 0; j <= 9; j++){
				printf("|");
				if (table[i][j] != 0) cout << board[i][j].getAbbr(); else printf("  ");
				printf("  ");
			}
			printf("|\n");
			for (int k = 1; k <= 10; k++){
				printf(" ");
			}
			for (int j = 0; j <= 9; j++){
				printf("|");
				if (table[i][j] != 0) printf("HP=%d", board[i][j].getHp()); else printf("    ");
			}
			printf("|\n");
			for (int k = 1; k <= 10; k++){
				printf(" ");
			}
			for (int k = 1; k <= 51; k++){
				printf("-");
			}
			printf("\n");
		}
		else{
			printf("Homeowner ");
			for (int j = 0; j <= 9; j++){
				printf("|");
				if (table[i][j] != 0) { cout << board[i][j].getAbbr(); } else printf("  ");
				printf("  ");
			}
			printf("|   Zombies\n");
			if (game.humanPlayer->role){
				printf("HP: %3d   ", game.humanPlayer->getHP()); 				
			}
			else {
				printf("HP: %3d   ", game.comPlayer->getHP());
			}
			
			for (int j = 0; j <= 9; j++){
				printf("|");
				if (table[i][j] != 0) printf("HP=%d", board[i][j].getHp()); else printf("    ");
			}
			if (game.humanPlayer->role){
				printf("|   Coins: %3d\nSun: %3d  ", game.comPlayer->getCost(),game.humanPlayer->getCost());
			}
			else{
				printf("|   Coins: %3d\nSun: %3d  ", game.humanPlayer->getCost(), game.comPlayer->getCost());
			}
			for (int k = 1; k <= 51; k++){
				printf("-");
			}
			printf("\n");
		}
	}
}

void GameBoard::initialise(){
	board = new Character*[6];
	for (int i = 0; i <= 5; i++){
		board[i] = new Character[10];
	}
	for (int i = 0; i <= 5; i++){
		for (int j = 0; j <= 9; j++){
			table[i][j] = 0;
		}
	}

}

void GameBoard::command(Game game){
	while (game.humanPlayer->getCommand()){
		system("cls");
		display(game); 
		string character = game.humanPlayer->create();
		if (characterCost(character) > game.humanPlayer->getCost())
		{
			notEnoughCost(game);
		}
		else{
			system("cls");
			display(game);
			askGrid(game,character);

		}
		system("cls");
		display(game);
		
	}
}

int GameBoard::characterCost(string name){
	Character *cost;
	cost = new Character[9];
	BasicZombie BZ; cost[0] = BZ;
	BonkChoy BC; cost[1] = BC;
	Buckethead BH; cost[2] = BH;
	Conehead CH; cost[3] = CH;
	Football FB; cost[4] = FB;
	Peashooter PS; cost[5] = PS;
	Sunflower SF; cost[6] = SF;
	Threepeater TP; cost[7] = TP;
	WallNut WN; cost[8] = WN;
	
	for (int i = 0; i <= 8; i++){
		if (name == cost[i].getAbbr()) return cost[i].getCost();
	}
	delete[] cost;
}

void GameBoard::notEnoughCost(Game game){
	system("cls");
	display(game);
	if (game.humanPlayer->role) printf("You do not have enough sun.\n"); else printf("You do not have enough coins.\n");
	printf("Please press any key to continue...");
	_getch();
}

void GameBoard::askGrid(Game game, string character){
	if (game.humanPlayer->role) {
		printf("which grid do you want to plant?(x,y) 0<=x<=5, 0<=y<=8\n");
		int x, y;
		scanf("%d,%d", &x, &y);
		while (((x < 0) || (x>5) || (y < 0) || (y>8)) || (table[x][y]!=0))
		{
			if (table[x][y] != 0){
				printf("The grid have occupied.Please enter again.(x,y) 0<=x<=5, 0<=y<=8\n");
			}
			else
			{
				printf("You have input a invalid gird.Please enter again.(x,y) 0<=x<=5, 0<=y<=8\n");
			}			
			scanf("%d,%d", &x, &y);
		}
		insertChar(character, x, y);
		game.humanPlayer->deductCost(characterCost(character));
	}
	else{
		printf("which grid do you want to create?(x) 0<=x<=5\n");
		int x;
		scanf("%d",&x);
		while (((x < 0) || (x>8)) || (table[x][9] != 0))
		{
			if (table[x][9] != 0){
				printf("The grid have occupied.Please enter again.(x) 0<=x<=5\n");
			}
			else
			{
				printf("You have input a invalid gird.Please enter again.(x) 0<=x<=5\n");
			}
			scanf("%d", &x);
		}
		insertChar(character, x, 9);
		game.humanPlayer->deductCost(characterCost(character));
	}
	
}


