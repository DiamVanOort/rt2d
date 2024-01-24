#ifndef MYSCENE_H
#define MYSCENE_H
#include <list>
#include <rt2d/scene.h>
#include "cell.h"
#include "enemy.h"

class MyScene : public Scene
{
public:
    MyScene();
    virtual ~MyScene();

    void update(float deltaTime);
    void Walk(float deltaTime);
    void DeleteEnemy();
    void SpawnNewEnemy();
    void SpawnTower(Cell* cell);

    int xPath;
    int yPath;
    int CellIndex;
    int enemyIndex;
    std::vector<size_t> pathList;
    std::vector<Cell*> grid;

    std::list<Enemy*> enemyList; // Add the enemyList
    int numberOfEnemiesToSpawn = 4; // Adjust the number of enemies to spawn
   
    
};

#endif /* MYSCENE_H */