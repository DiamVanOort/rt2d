#ifndef MYSCENE_H
#define MYSCENE_H
#include <rt2d/scene.h>
#include "cell.h"

class MyScene : public Scene
{
public: 
    MyScene();
    virtual ~MyScene();

    void update(float deltaTime);

    std::vector<Cell*> grid;
};

#endif /* MYSCENE_H */