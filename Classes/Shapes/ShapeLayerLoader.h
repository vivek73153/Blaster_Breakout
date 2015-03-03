
#ifndef ShapeLayerLoader_h
#define ShapeLayerLoader_h
#include "../Shapes/ShapeLayer.h"
/* Forward declaration. */
class CCBReader;
class ShapeLayerLoader : public cocos2d::extension::CCLayerLoader
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ShapeLayerLoader, loader);   
    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ShapeLayer);
};
#endif
