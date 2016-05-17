#ifndef IMAGEATLAS_H
#define IMAGEATLAS_H
#define maxImages 50

#include "Object.h"
#include "Image.h"
#include <string>

class ImageAtlas : public Object
{
    public:
        ImageAtlas (const std::string&);
        ~ImageAtlas();
        Image* getImage(int);
    private:
        Image* _images[maxImages];
};

#endif // IMAGEATLAS_H
