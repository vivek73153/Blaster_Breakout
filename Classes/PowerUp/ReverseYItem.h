

#ifndef REVERSEYITEM_H_
#define REVERSEYITEM_H_

#include "cocos2d.h"
#include "../Sprite/Item.h"

class ReverseYItem: public Item {
public:
	ReverseYItem();
	virtual ~ReverseYItem();
	static ReverseYItem* createReverseYItem();
};

#endif /* REVERSEYITEM_H_ */
