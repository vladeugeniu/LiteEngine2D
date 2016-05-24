#ifndef NINJAOBJECT_H
#define NINJAOBJECT_H

#include "SceneObject.h"
#include "CollisionInterface.h"
#include "ImageAtlas.h"
#include "Vector2.h"
#include <map>
#include <string>
class NinjaObject : public SceneObject,CollisionInterface
{
    public:
        NinjaObject();
        virtual ~NinjaObject();
        virtual void Draw ();
        virtual void Update ();
        int GetWidth(){return 126;}
        int GetHeight(){return 131;}
        int GetRange(){return _range;}
        Vector2 GetPosition(){return _position;}
        void OnCollisionEnter(CollisionInterface*);
    private:
        std::map <std::string,ImageAtlas*> _sprites;
        Image* _image;
        Vector2 _position;
        Vector2 _fallDestination;
        Vector2 _destination;
        Vector2 _limitLeft;
        Vector2 _limitRight;
        Vector2 _limitDown;
        int _range;
        int _spriteNumber;
        float _spriteTime;
        float _speed;
        char _orientation;
        bool _onCollision;
        bool _inAir;
        bool _dead;
        bool _attack;
        void UpdateSprite(std::string);
        void UpdateOrientation(char);
        void Jump();
        void Attack();
        void Idle();
        void Dead();
        void JumpContinue();

};

#endif // NINJAOBJECT_H
