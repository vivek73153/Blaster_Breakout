
#ifndef MAGNETITEM_H_
#define MAGNETITEM_H_

#include "../Sprite/Item.h"

class BulletItem: public Item {
public:
	BulletItem();
	virtual ~BulletItem();
	static BulletItem* createBulletItem();

};

#endif /* MAGNETITEM_H_ */
