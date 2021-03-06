#ifndef COLLISIONINTERFACE_H
#define COLLISIONINTERFACE_H

#include "Vector2.h"

class CollisionInterface
{
    public:
        CollisionInterface();
        virtual ~CollisionInterface();
        virtual void OnCollisionEnter(CollisionInterface*)=0;
        virtual int GetWidth()=0;
        virtual int GetHeight()=0;
        virtual int GetRange()=0;
        virtual Vector2 GetPosition()=0;
};

#endif // COLLISIONINTERFACE_H
