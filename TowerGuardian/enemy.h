#ifndef ENEMY_H
#define ENEMY_H
#include <rt2d/entity.h>

class Enemy: public Entity
{
public:
    Enemy();
    virtual ~Enemy();
    
private:
    virtual void update(float deltaTime);
    
};

#endif //*CELL_H