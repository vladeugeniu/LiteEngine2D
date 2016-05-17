#include "ImageAtlas.h"
#include "Resources.h"
#include <iostream>
ImageAtlas::ImageAtlas(const std::string& path)
{
    char number[0];
    number[0] = '0';
    number[1] = '\0';
    for(int i=0; i<10; i++)
        {
            std::string numberString (number);
            _images[i] = Resources::LoadImage (path + '/' + number + ".png");
            number[0] ++;
        }
}

ImageAtlas::~ImageAtlas()
{
    for(int i=0; i<maxImages; i++)
        delete _images[i];
}

Image* ImageAtlas::getImage(int i)
{
    return _images[i];
}
