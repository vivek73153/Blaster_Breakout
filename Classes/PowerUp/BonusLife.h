

#ifndef BonusLife_H_
#define BonusLife_H_

#include "../Sprite/Item.h"

class BonusLife: public Item {
public:
	BonusLife();
	virtual ~BonusLife();
	static BonusLife* createBonusLife();
};

#endif /* BonusLife_H_ */
