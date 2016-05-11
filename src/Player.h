#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
public:
	Player();
	string getName() const;
	void setName(string name);
protected:
	string name;
};
#endif
