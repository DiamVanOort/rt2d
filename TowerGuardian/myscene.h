#ifndef MYSCENE_H
#define MYSCENE_H
#include <rt2d/scene.h>
#include "cell.h"
#include "enemy.h"

class MyScene : public Scene
{
public:
    MyScene();
    virtual ~MyScene();

    void update(float deltaTime);

    int xPath;
    int yPath;
    int CellIndex;
    std::vector<size_t> pathList;
    std::vector<Cell*> grid;
};

#endif /* MYSCENE_H */