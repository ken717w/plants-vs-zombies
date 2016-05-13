#ifndef PLANT_H
#define PLANT_H

#include "Character.h"
using namespace std;

class Plant : public Character {
public:
	static const int RANGE_LONG = 2;
	static const int RANGE_SHORT = 1;
	static const int RANGE_NONE = 0;

	Plant();
	bool attack() const;
protected:
	int range;
};
#endif
