#include "cell.h"
#include <cstdlib>
#include <ctime>


Cell::Cell() : Entity()
{
    this->addSprite("assets/GridNoPath.tga");

    isPath = false; 
}

Cell::~Cell()
{

}

void Cell::update(float deltaTime)
{
    if(isPath)
    {
        this->sprite()->color = GRAY;
    }
}

