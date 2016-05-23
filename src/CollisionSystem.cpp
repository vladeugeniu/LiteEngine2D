#include "CollisionSystem.h"
#include "Vector2.h"
#include <iterator>


bool CollisionSystem::CheckCOllide(CollisionInterface* first_obj, CollisionInterface* second_obj)
{
    Vector2 obj1 = first_obj -> GetPosition();
    Vector2 obj2 = second_obj -> GetPosition();

    int first_width = first_obj -> GetWidth();
    int first_height = first_obj -> GetHeight();
    int second_width = second_obj -> GetWidth();
    int second_height = second_obj -> GetHeight();

    if( obj1.GetX() + first_width > obj2.GetX() &&
        obj1.GetX() + first_width < obj2.GetX() + second_width &&
        obj1.GetY() - first_height < obj2.GetY() &&
        obj1.GetY() - first_height > obj2.GetY() - second_height)
            return true;


    if( obj2.GetX() + second_width > obj1.GetX() &&
        obj2.GetX() + second_width < obj1.GetX() + first_width &&
        obj2.GetY() - second_height < obj1.GetY()&&
        obj2.GetY() - second_height > obj1.GetY() - first_height)
                 return true;
    return false;

}

void CollisionSystem::Update()
{
    for (auto it : _collidableObjects)
        for(auto it2 : _collidableObjects)

            if(it != it2 && CheckCOllide(it,it2))
                std::cout<<"collode\n";
            else
                std::cout<<"nu\n";
}

void CollisionSystem::Add(CollisionInterface* toAdd)
{
    _collidableObjects.push_back(toAdd);
}
