#ifndef NINJAOBJECT_H
#define NINJAOBJECT_H

#include "Character.h"
#include "ImageAtlas.h"
#include "Vector2.h"
#include <map>
#include <string>
class NinjaObject : public Character
{
    public:
        NinjaObject();
        virtual ~NinjaObject();
        virtual void Draw ();
        virtual void Update ();
        std::size_t GetWidth(){return _image -> GetWidth();}
        std::size_t GetHeight(){return _image -> GetHeight();}
        int GetRange(){return _range;}
    private:
        std::map <std::string,ImageAtlas*> _sprites;
        Image* _image;
        Vector2 _position;
        Vector2 _fallDestination;
        Vector2 _destination;
        int _range;
        int _spriteNumber;
        float _spriteTime;
        float _speed;
        char _orientation;
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
