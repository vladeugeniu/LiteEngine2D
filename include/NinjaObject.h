#ifndef NINJAOBJECT_H
#define NINJAOBJECT_H

#include "SceneObject.h"
#include "ImageAtlas.h"
#include "Vector2.h"
#include <map>
#include <string>
class NinjaObject : public SceneObject
{
    public:
        NinjaObject();
        virtual ~NinjaObject();
        virtual void Draw ();
        virtual void Update ();

    private:
        std::map <std::string,ImageAtlas*> _sprites;
        Image* _image;
        Vector2 _position;
        Vector2 _fallDestination;
        Vector2 _destination;
        int _spriteNumber;
        float _spriteTime;
        float _speed;
        char _orientation;
        bool _inAir;
        bool _dead;
        bool _attack;
        void UpdateSprite(std::string);
        void UpdateOrientation(char);
        void jump();
};

#endif // NINJAOBJECT_H
