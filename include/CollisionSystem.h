#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include <SceneObject.h>
#include <vector>
#include "CollisionInterface.h"

class CollisionSystem
{
    public:
        static CollisionSystem* Instance(){return _system;}
        void Update();
        void Add(CollisionInterface*);
        void Remove(CollisionInterface*);

    private:
        static CollisionSystem* _system;
        std::vector<CollisionInterface*> _collidableObjects;
        bool CheckCOllide(CollisionInterface*, CollisionInterface*);
        CollisionSystem(){}
        ~CollisionSystem(){}
};

#endif // COLLISIONSYSTEM_H
