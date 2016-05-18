#ifndef CHARACTER_H
#define CHARACTER_H

#include <SceneObject.h>


class Character : public SceneObject
{
    public:
         virtual ~Character(){};

         virtual std::size_t GetHeight()=0;
         virtual std::size_t GetWidth()=0;
         virtual int GetRange()=0;
};

#endif // CHARACTER_H
