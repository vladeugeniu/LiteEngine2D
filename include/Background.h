#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SceneObject.h"
#include "Vector2.h"
#include "Image.h"


class Background : public SceneObject
{
    public:
        Background();
        ~Background();
        void Draw();
    private:
        Image* _image;
        Vector2 _position;

};

#endif // BACKGROUND_H
