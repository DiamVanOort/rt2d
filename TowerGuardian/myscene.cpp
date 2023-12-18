#include "myscene.h"
#include <cstdlib>
#include <ctime>

MyScene::MyScene()
{
    grid = std::vector<Cell*>();
    //Makes list for the path cells
    pathList = std::vector<size_t>();

    //Makes grid
    for (size_t y = 0; y < 11; y++)
    {
        for (size_t x = 0; x < 20; x++)
        {
            Cell* c = new Cell();
            c->position = Vector2(x * 64 + 32, y * 64 + 40);
            this->addChild(c);
            grid.push_back(c);
        }
    }

    //Makes path
    xPath = 0;
    srand(time(nullptr));
    yPath = rand() % 11;

    for (size_t xPath = 0; xPath <= 19; xPath++)
    {
        size_t cellIndex = xPath % 20 + yPath * 20;
        grid[cellIndex]->isPath = true;

        // Adds path cells to list
        pathList.push_back(cellIndex);
    }
}

MyScene::~MyScene()
{
    
}

void MyScene::update(float deltaTime)
{
    
}