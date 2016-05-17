#include "Background.h"
#include "Resources.h"
#include "Screen.h"
Background::Background()
{
    _image = Resources::LoadImage ("Assets/Images/Background.png");
    _position = Vector2 (0.0, Screen::GetHeight());
}

Background::~Background()
{
    delete _image;
}

void Background::Draw ()
{
	Screen::Draw (_image, _position);
}

