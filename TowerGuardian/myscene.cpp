#include "myscene.h"
#include "enemy.h"
#include "tower.h"
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



    SpawnNewEnemy();
}

MyScene::~MyScene()
{
    
}

void MyScene::update(float deltaTime)
{
    // for (auto it = enemyList.begin(); it != enemyList.end(); ++it)
    // {
    //     std::cout << (*it)->position << std::endl;
    // }


    DeleteEnemy();

    if (input()->getMouseDown(0))
    {
        // Getting mouse position and converting into grid coordinates
        int mouseX = input()->getMouseX();
        int mouseY = input()->getMouseY();

        int gridX = (mouseX - 40 + 32) / 64;
        int gridY = (mouseY - 40 + 32) / 64;

        // Making sure coordinates are on the grid
        if (gridX >= 0 && gridX < 20 && gridY >= 0 && gridY < 20)
        {
            // Get the clicked cell
            Cell *clickedCell = grid[gridY * 20 + gridX];

            // Change the color to blue
            SpawnTower(clickedCell);
        }
    }
}





void MyScene::DeleteEnemy()
{
    if (!enemyList.empty())
    {
        Enemy* frontEnemy = enemyList.front();
        if (frontEnemy->position.x >= grid[pathList[19]]->position.x + 64)
        {
            enemyList.pop_front();
            this->removeChild(frontEnemy);  // Remove from the scene
            delete frontEnemy;

            numberOfEnemiesToSpawn = 1;
            SpawnNewEnemy();
        }
    }
}


void MyScene::SpawnNewEnemy()
{

    for (int i = 0; i < numberOfEnemiesToSpawn; ++i)
    {
        // Spawn a new enemy at the starting position
        Enemy* newEnemy = new Enemy();
        newEnemy->position = grid[pathList[0]]->position;
        newEnemy->position.x = newEnemy->position.x - 66 * i; // Adjust the position for each enemy
        this->addChild(newEnemy);
        enemyList.push_back(newEnemy);
    }
}

void MyScene::SpawnTower(Cell* cell)
{
    // Check if the cell is not a path cell
    if (!cell->isPath)
    {
        Tower* tower = new Tower();
        tower->position = cell->position;
        this->addChild(tower);
    }
}