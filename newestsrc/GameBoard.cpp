#include "GameBoard.h"
#include "iostream"
#include "conio.h"
#include "time.h"

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
	if (character == "SF") { table[x][y] = 3; Sunflower SF; board[x][y] = SF; }
	if (character == "TP") { table[x][y] = 1; Threepeater TP; board[x][y] = TP; }
	if (character == "WN") { table[x][y] = 1; WallNut WN; board[x][y] = WN; }

}

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
	insertChar("BZ", 1, 9);
	insertChar("PS", 1, 7);
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
	AISystem(game);
	char c=_getch();
	system("cls");
	display(game);	
	plantAttack(game);
	system("cls");
	display(game);
	printf("The plants have all attacked.\nPress any key to continue..");
	char d=_getch();
	system("cls");
	display(game);
	zombieMove(game);
	printf("The zombies have all moved.\nPress any key to continue...");
	char e=_getch();
	system("cls");
	display(game);
	zombieAttack(game);
	printf("The zombies have all attacked.\nPress any key to continue");
	char f = _getch();
	system("cls");
	display(game);
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

void GameBoard::AISystem(Game game){
	srand(time(NULL));
	if (game.humanPlayer->role){
		while ((game.comPlayer->getCost() >= 3) && zombieHaveEmpty()){

			int ranChar = rand() % 4;
			int ranPos = rand() % 6;
			while (table[ranPos][9] != 0){
				ranPos = rand() % 6;
			}
			if (ranChar == 0) { insertChar("BZ", ranPos, 9); game.comPlayer->deductCost(characterCost("BZ")); }
			if (ranChar == 1) { insertChar("BH", ranPos, 9); game.comPlayer->deductCost(characterCost("BH")); }
			if (ranChar == 2) { insertChar("FB", ranPos, 9); game.comPlayer->deductCost(characterCost("FB")); }
			if (ranChar == 3) { insertChar("CH", ranPos, 9); game.comPlayer->deductCost(characterCost("CH")); }
		}
		int ranAct = rand() % 2;
		while (game.comPlayer->getCost() >= 1 && zombieHaveEmpty() && (ranAct == 0)){
			ranAct = rand() % 2;
			int ranChar = rand() % 2;
			if (game.comPlayer->getCost() == 1) ranChar = 0;
			int ranPos = rand() % 6;
			while (table[ranPos][9] != 0){
				ranPos = rand() % 6;
			}
			if (ranChar == 0) { insertChar("BZ", ranPos, 9); game.comPlayer->deductCost(characterCost("BZ")); }
			if (ranChar == 1) { insertChar("CH", ranPos, 9); game.comPlayer->deductCost(characterCost("CH")); }
		}
	}
	
	else{
		homeownerHaveEnemy(game);
		while ((game.comPlayer->getCost() >= 3) && homeownerHaveEmpty()){
			int ranChar = rand() % 5;
			int ranPosX = rand() % 6;
			int ranPosY = rand() % 9;
			while (table[ranPosX][ranPosY] != 0){
				ranPosX = rand() % 6;
				ranPosY = rand() % 9;
			}
			if (ranChar == 0) { insertChar("PS", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("PS")); }
			if (ranChar == 1) { insertChar("BC", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("BC")); }
			if (ranChar == 2) { insertChar("TP", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("TP")); }
			if (ranChar == 3) { insertChar("WN", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("WN")); }
			if (ranChar == 4) { insertChar("SF", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("SF")); }
		}
		int ranAct = rand() % 3;
		while (game.comPlayer->getCost() >= 1 && homeownerHaveEmpty()&&(ranAct<=1)){
			ranAct = rand() % 3;
			int ranChar = rand() % 4;
			if (game.comPlayer->getCost() == 1) ranChar = rand() % 2;
			int ranPosX = rand() % 6;
			int ranPosY = rand() % 9;
			while (table[ranPosX][ranPosY] != 0){
				ranPosX = rand() % 6;
				ranPosY = rand() % 9;
			}
			if (ranChar == 0) { insertChar("PS", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("PS")); }
			if (ranChar == 3) { insertChar("BC", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("BC")); }
			if (ranChar == 2) { insertChar("WN", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("WN")); }
			if (ranChar == 1) { insertChar("SF", ranPosX, ranPosY); game.comPlayer->deductCost(characterCost("SF")); }
		}
	}

	
	system("cls");
	display(game);
	printf("The computer have entered its command.\nPlease press any key to continue.");
	
}

bool GameBoard::zombieHaveEmpty(){
	bool haveEmpty = false;
	for (int i = 0; i <= 5; i++){
		if (table[i][9] == 0){ haveEmpty = true; break; }
	}
	return haveEmpty;
}

bool GameBoard::homeownerHaveEmpty(){
	bool haveEmpty = false;
	for (int i = 0; i <= 5; i++){
		for (int j = 0; j <= 8; j++){
			if (table[i][j] == 0){ haveEmpty = true; break; }
		}
		if (haveEmpty) break;
	}
	return haveEmpty;
}

bool GameBoard::homeownerHaveEnemy(Game game){
	srand(time(NULL));
	if (game.comPlayer->getCost() == 0) return false;
	for (int i = 0; i <= 5; i++){
		if ((table[i][1] == 2)&&(table[i][0]==0)){
			if (game.comPlayer->getCost() >= 3) {
				insertChar("TP",i , 0); 
				game.comPlayer->deductCost(characterCost("TP"));
			}
			else{
				int ranChar = rand() % 4;
				if (game.comPlayer->getCost() == 1) ranChar = rand() % 2;
				if (ranChar == 0) { insertChar("PS", i, 0); game.comPlayer->deductCost(characterCost("PS")); }
				if (ranChar == 3) { insertChar("BC", i,0); game.comPlayer->deductCost(characterCost("BC")); }
				if (ranChar == 2) { insertChar("WN",i, 0); game.comPlayer->deductCost(characterCost("WN")); }
				if (ranChar == 1) { insertChar("SF",i, 0); game.comPlayer->deductCost(characterCost("SF")); }
			}
		}
		if (game.comPlayer->getCost() == 0) return false;
	}
	for (int i = 0; i <= 5; i++){
		if ((table[i][2] == 2) && ((table[i][0] != 1) && (table[i][1] != 1) && (table[i][0] != 3) && (table[i][1] != 3)) && ((table[i][0] == 0) || (table[i][1] == 0))){
			int ranPos = rand() % 2;
			while (table[i][ranPos] != 0){
				ranPos = rand() % 2;
			}
			if (game.comPlayer->getCost() >= 3) {
				insertChar("TP", i, ranPos);
				game.comPlayer->deductCost(characterCost("TP"));
			}
			else{
				int ranChar = rand() % 4;
				if (game.comPlayer->getCost() == 1) ranChar = rand() % 2;
				if (ranChar == 0) { insertChar("PS", i, ranPos); game.comPlayer->deductCost(characterCost("PS")); }
				if (ranChar == 3) { insertChar("BC", i, ranPos); game.comPlayer->deductCost(characterCost("BC")); }
				if (ranChar == 2) { insertChar("WN", i, ranPos); game.comPlayer->deductCost(characterCost("WN")); }
				if (ranChar == 1) { insertChar("SF", i, ranPos); game.comPlayer->deductCost(characterCost("SF")); }
			}
		}
		if (game.comPlayer->getCost() == 0) return false;
	}
	for (int i = 0; i <= 5; i++){
		if ((table[i][3] == 2) && ((table[i][0] != 1) && (table[i][1] != 1) && (table[i][2] != 1) && (table[i][0] != 3) && (table[i][1] != 3) && (table[i][2] != 3)) && ((table[i][0] == 0) || (table[i][1] == 0) || (table[i][2] == 0))){
			int ranPos = rand() % 3;
			while (table[i][ranPos] != 0){
				ranPos = rand() % 3;
			}
			if (game.comPlayer->getCost() >= 3) {
				insertChar("TP", i, ranPos);
				game.comPlayer->deductCost(characterCost("TP"));
			}
			else{
				int ranChar = rand() % 4;
				if (game.comPlayer->getCost() == 1) ranChar = rand() % 2;
				if (ranChar == 0) { insertChar("PS", i, ranPos); game.comPlayer->deductCost(characterCost("PS")); }
				if (ranChar == 3) { insertChar("BC", i, ranPos); game.comPlayer->deductCost(characterCost("BC")); }
				if (ranChar == 2) { insertChar("WN", i, ranPos); game.comPlayer->deductCost(characterCost("WN")); }
				if (ranChar == 1) { insertChar("SF", i, ranPos); game.comPlayer->deductCost(characterCost("SF")); }
			}
		}
		if (game.comPlayer->getCost() == 0) return false;
	}
	return false;
}

void GameBoard::plantAttack(Game game){
	printf("The plants are now attacking\nPress any key to continue\n");
	_getch();
	for (int i = 0; i <= 5; i++){
		for (int j = 0; j <= 8; j++){
			if (table[i][j] == 1) {
				if ((board[i][j].getRange()) == 1) {
					if (table[i][j + 1] == 2) {
						cout << board[i][j].getAbbr() << " at<" << i << "," << j << "> is now attacking\n";
						board[i][j + 1].deductHp(board[i][j].getDamge());
						if (board[i][j + 1].getHp() <= 0) { table[i][j + 1] = 0; cout << board[i][j+1].getAbbr() << " at<" << i << "," << j << "> is died\n"; }
						printf("Press any key to cintinue...\n");
						_getch();
						system("cls");
						display(game);
						
					}
				}
				if ((board[i][j].getRange()) == 2) {
					if (table[i][j + 1] == 2) {
						cout << board[i][j].getAbbr() << " at<" << i << "," << j << "> is now attacking\n";
						board[i][j + 1].deductHp(board[i][j].getDamge());
						if (board[i][j + 1].getHp() <= 0) { table[i][j + 1] = 0; cout << board[i][j + 1].getAbbr() << " at<" << i << "," << j << "> is died\n"; }
						printf("Press any key to cintinue...\n");
						_getch();
						system("cls");
						display(game);
					}
					else{
						if (table[i][j + 2] == 2) {
							cout << board[i][j].getAbbr() << " at<" << i << "," << j << "> is now attacking\n";
							board[i][j + 2].deductHp(board[i][j].getDamge());
							if (board[i][j + 2].getHp() <= 0){ table[i][j + 2] = 0; cout << board[i][j + 2].getAbbr() << " at<" << i << "," << j << "> is died\n"; }
							printf("Press any key to cintinue...\n");
							_getch();
							system("cls");
							display(game);
						}
					}
				}
			}
		}
	}
	
}

void GameBoard::zombieMove(Game game){
	printf("Zombies are now moving.\nPress any key to continue\n");
	_getch();
	for (int i = 0; i <= 5; i++){
		for (int j = 1; j <= 9; j++){
			if (table[i][j] == 2){
				int distance = board[i][j].getSpeed();
				switch (distance)
				{
				case 1:
					if (table[i][j - 1] == 0) {

						board[i][j - 1] = board[i][j];
						table [i][j - 1] = 2;
						table[i][j] = 0;
						cout << board[i][j].getAbbr()<<" at<"<<i<<","<<j << "> is now moving.\nPress anykey to continue..";
						_getch();
						system("cls");
						display(game);
						break;
					}
				case 2:
					if ((table[i][j - 1] == 0) && (table[i][j - 2] == 0) && (j >= 2)) {
						board[i][j - 2] = board[i][j];
						table[i][j - 2] = 2;
						table[i][j] = 0;
						cout << board[i][j].getAbbr() << " at<" << i << "," << j << "> is now moving.\nPress anykey to continue..";
						_getch();
						system("cls");
						display(game);
					}
					else{
						if (table[i][j - 1] == 0) {
							board[i][j - 1] = board[i][j];
							table[i][j - 1] = 2;
							table[i][j] = 0;
							cout << board[i][j].getAbbr() << " at<" << i << "," << j << "> is now moving.\nPress anykey to continue..";
							_getch();
							system("cls");
							display(game);
						}
					}
					break;
					
				case 3:
					if ((table[i][j - 1] == 0) && (table[i][j - 2] == 0) && (table[i][j - 3] == 0) && (j >= 3)) {
						board[i][j - 3] = board[i][j];
						table[i][j - 3] = 2;
						table[i][j] = 0;
						cout << board[i][j].getAbbr() << " at<" << i << "," << j << "> is now moving.\nPress anykey to continue..";
						_getch();
						system("cls");
						display(game);
					}
					else{
						if ((table[i][j - 1] == 0) && (table[i][j - 2] == 0) && (j >= 2)) {
							board[i][j - 2] = board[i][j];
							table[i][j - 2] = 2;
							table[i][j] = 0;
							cout << board[i][j].getAbbr() << " at<" << i << "," << j << "> is now moving.\nPress anykey to continue..";
							_getch();
							system("cls");
							display(game);
						}
						else{
							if (table[i][j - 1] == 0) {
								board[i][j - 1] = board[i][j];
								table[i][j - 1] = 2;
								table[i][j] = 0;
								cout << board[i][j].getAbbr() << " at<" << i << "," << j << "> is now moving.\nPress anykey to continue..";
								_getch();
								system("cls");
								display(game);
							}
						}
					}
					break;
				default:
					break;
				}
			}
		}
	}
	
}

void GameBoard::zombieAttack(Game game){
	printf("Zombies are now attacking.\nPress any key to continue..\n");
	_getch();
	for (int i = 0; i <= 5; i++){
		for (int j = 1; j <= 9; j++){
			if (table[i][j] == 2){
				if ((table[i][j - 1] == 1) || (table[i][j - 1] == 3)){
					board[i][j - 1].deductHp(board[i][j].getDamge());
					cout << board[i][j].getAbbr()<<" at <"<<i<<","<<j<<"> is attacking.\n" ;
					if (board[i][j - 1].getHp() <= 0) { table[i][j - 1] = 0; cout << board[i][j-1].getAbbr() << " at <" << i << "," << j-1 << "> is died.\n"; }
					printf("Please press any key to continue...");
					_getch();
					system("cls");
					display(game);
				}
			}
		}
	}
	for (int i = 0; i <= 5; i++){
		if (table[i][0] == 2){
			if (game.humanPlayer->role){
				game.humanPlayer->deductHP(board[i][0].getDamge());
				cout << board[i][0].getAbbr() << " at <" << i << ",0> is attacking.\n";
				printf("Homeowner HP have been deducted by %d point.\nPlease press any key to continue...", board[i][0].getDamge());
				table[i][0] = 0;
				_getch();
				system("cls");
				display(game);
			}
			else{
				game.comPlayer->deductHP(board[i][0].getDamge());
				cout << board[i][0].getAbbr() << " at <" << i << ",0> is attacking.\n";
				printf("Homeowner HP have been deducted by %d point.\nPlease press any key to continue...", board[i][0].getDamge());
				table[i][0] = 0;
				_getch();
				system("cls");
				display(game);
			}
		}
	}
}

void GameBoard::addcost(Game game){
	if (game.humanPlayer->role) game.humanPlayer->updateSunflower(sunflowerNO()); else game.comPlayer->updateSunflower(sunflowerNO());
	game.humanPlayer->addCost();
	game.comPlayer->addCost();
}

int GameBoard::sunflowerNO(){
	int NO = 0;
	for (int i = 0; i <= 5; i++){
		for (int j = 0; j <= 9; j++){
			if (table[i][j] == 3) NO = NO + 1;
		}
	}
	return NO;
}




