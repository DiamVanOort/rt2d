#include "enemy.h"


Enemy::Enemy() : Entity()
{
    this->addSprite("assets/GridNoPath.tga");
    this->sprite()->color = RED;
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
   
}

