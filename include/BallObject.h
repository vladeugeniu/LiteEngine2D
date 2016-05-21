#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include "Image.h"
#include "CollisionInterface.h"
#include "SceneObject.h"
#include "Vector2.h"

class BallObject : public SceneObject,CollisionInterface
{
private:
	Image* _image;
	float _speed;
	Vector2 _position;
	Vector2 _destination;
    Vector2 _limitLeft;
    Vector2 _limitRight;
    Vector2 _limitDown;
    int range;

public:
	BallObject ();
	~BallObject ();
    int GetWidth(){return 48;}
    int GetHeight(){return 48;}
    int GetRange(){return range;}
    Vector2 GetPosition(){return _position;}
	virtual void Draw ();
	virtual void Update ();
    void OnCollisionEnter(CollisionInterface*){}
};

#endif
