#ifndef CELL_H
#define CELL_H
#include <rt2d/entity.h>


class Cell: public Entity
{
public:
    Cell();
    virtual ~Cell();
    bool isPath;
    
private:
    virtual void update(float deltaTime);
    
};

#endif //*CELL_H