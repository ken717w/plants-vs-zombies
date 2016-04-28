#ifndef PLANT_H
#define PLANT_H

#include <string>
#include "Character.h"
using namespace std;

class Plant : public Character {
public:
	Plant();
	bool attack() const;
private:
	int range;
};
#endif
