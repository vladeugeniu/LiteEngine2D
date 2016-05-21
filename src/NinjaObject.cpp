#include "NinjaObject.h"
#include "Input.h"
#include "GameTime.h"
#include "Screen.h"
#include <algorithm>
#include <cstdlib>
#include "Window.h"
#define Ninja_SPEED 350

NinjaObject::NinjaObject(): _speed(Ninja_SPEED),
_position(500, 120)
{
    _sprites["Run Right"] = new ImageAtlas("Assets/Images/run_right");
    _sprites["Run Left"] = new ImageAtlas("Assets/Images/run_left");
    _sprites["Jump Right"] = new ImageAtlas("Assets/Images/jump_right");
    _sprites["Jump Left"] = new ImageAtlas("Assets/Images/jump_left");
    _sprites["Dead Left"] = new ImageAtlas("Assets/Images/dead_left");
    _sprites["Dead Right"] = new ImageAtlas("Assets/Images/dead_right");
    _sprites["Attack Left"] = new ImageAtlas("Assets/Images/attack_left");
    _sprites["Attack Right"] = new ImageAtlas("Assets/Images/attack_right");
    _sprites["Idle Left"] = new ImageAtlas("Assets/Images/idle_left");
    _sprites["Idle Right"] = new ImageAtlas("Assets/Images/idle_right");

    _range = 100;
    _image = _sprites["Idle Right"]->getImage(0);
    _spriteNumber = 0;
    _spriteTime = 0;
    _orientation = 'r';
    _dead = false;
    _attack = false;
}

NinjaObject::~NinjaObject()
{
    //dtor
}

void NinjaObject::Draw ()
{
	Screen::Draw (_image, _position);
}

void NinjaObject::Update ()
{
	 Vector2 velocity = Vector2::Zero;

     if(!_inAir && !_attack && !_dead )
        {
            if (Input::GetKey ('w'))
            {
                _spriteNumber = 0;
                _spriteTime = 0;
                Jump();
                velocity = _destination - _position;
                if (velocity.SqrMagnitude () < 0.1f)
                    return;
                velocity.Normalize ();
                _position += velocity * _speed * GameTime::GetDeltaTime ();
                return ;
            }

            if (Input::GetKey ('d'))
            {
            if(_position.GetX() < WINDOW_WIDTH - 50)
                velocity += Vector2::Right;
            if(_orientation != 'r')
                UpdateOrientation('r');
            if(_spriteTime > 0.05)
                UpdateSprite("Run Right");
            _spriteTime += GameTime::GetDeltaTime ();
            }

            if (Input::GetKey ('a'))
            {
                if(_position.GetX() > -15)
                    velocity += Vector2::Left;
                if(_orientation != 'l')
                    UpdateOrientation('l');
                if(_spriteTime > 0.05)
                    UpdateSprite("Run Left");
                _spriteTime += GameTime::GetDeltaTime ();
            }

            if(Input::GetKey ('x'))
            {
                _dead = true;
                _spriteNumber = 0;
                _spriteTime = 0;
                Dead();
            }


             if(Input::GetKey ('q'))
            {
                _attack = true;
                _spriteNumber = 0;
                _spriteTime = 0;
                Attack();
            }

            if(!Input::GetKey ('a') && !Input::GetKey ('d') && !Input::GetKey ('w') && !Input::GetKey('q') && !_attack)
                Idle();

            if (velocity == Vector2::Zero)
                return;
            velocity.Normalize ();
            _position += velocity * _speed * GameTime::GetDeltaTime ();

        }

        else
        {
            if(_attack) Attack();
            else if(_inAir) JumpContinue();
                else Dead();
        }
}

void NinjaObject::UpdateSprite(std::string key)
{
	 	_image = _sprites[key]->getImage(_spriteNumber);

	 	if(_spriteNumber == 9)
            _spriteNumber = 0;
        else
            _spriteNumber ++;
        _spriteTime = 0;


}

void NinjaObject::UpdateOrientation(char newOrientation)
{
    _spriteTime = 0;
    _spriteNumber = 0;
    _orientation = newOrientation;
}

void NinjaObject::Jump()
{
    _destination = _position;
    _fallDestination = _position;
    _inAir = true;
    if (Input::GetKey ('d'))
    {
        _orientation = 'r';
        _destination.SetX( std::min( _destination.GetX() + 200, (float) (WINDOW_WIDTH - 50) ) );
        _fallDestination.SetX( std::min( _destination.GetX() + 200, (float) (WINDOW_WIDTH - 50) ) );
    }
    if (Input::GetKey ('a'))
    {
        _orientation = 'l';
        _destination.SetX(std::max( _destination.GetX() - 200,( float) - 15));
        _fallDestination.SetX(std::max( _destination.GetX() - 200, (float) - 15));
    }
    _destination.SetY( _destination.GetY() + 150 );

}

void NinjaObject::JumpContinue()
{
    if (abs(_destination.GetX() - _position.GetX() ) < 0.25  && abs(_destination.GetY() - _position.GetY())< 0.25 )
        _destination = _fallDestination;
    if (abs(_destination.GetX() - _position.GetX() ) < 0.25  && abs(_destination.GetY() - _position.GetY())< 0.25 )
        _inAir=false;
    Vector2 velocity = _destination - _position;
    if (velocity.SqrMagnitude () < 0.1f)
        return;
    velocity.Normalize ();
    _position += velocity * _speed * GameTime::GetDeltaTime ();
    if(_spriteTime > 0.05)
        if(_orientation == 'r') UpdateSprite("Jump Right");
            else UpdateSprite("Jump Left");
        _spriteTime += GameTime::GetDeltaTime ();

            }

void NinjaObject::Dead()
{
    if(_spriteTime > 0.05)
    {
        if(_orientation == 'r')
            UpdateSprite("Dead Right");
        if(_orientation == 'l')
            UpdateSprite("Dead Left");
    }
    _spriteTime += GameTime::GetDeltaTime ();
    if(_spriteNumber == 9)
        _dead = false;
}

void NinjaObject::Attack()
{
    if(_spriteTime > 0.05)
    {
        if(_orientation == 'r')
            UpdateSprite("Attack Right");
        if(_orientation == 'l')
            UpdateSprite("Attack Left");
    }
    _spriteTime += GameTime::GetDeltaTime ();

    if(_spriteNumber == 9)
        _attack = false;

}

void NinjaObject::Idle()
{
    if(_spriteTime > 0.05)
    {
        if(_orientation == 'r')
            UpdateSprite("Idle Right");
        if(_orientation == 'l')
            UpdateSprite("Idle Left");
    }
    _spriteTime += GameTime::GetDeltaTime ();
}
