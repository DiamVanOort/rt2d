#include "enemy.h"
#include "myscene.h"

Enemy::Enemy() : Entity()
{
    // Set the enemy's sprite
    this->addSprite("assets/GridNoPath.tga");
    this->sprite()->color = GREEN;
    this->scale = Point3(0.6f,0.6f,1.0f);
    setHealth(100);
    setSpeed(40.0f);
    setGroupSize(1);
}

Enemy::~Enemy()
{

    
}

void Enemy::update(float deltaTime)
{
    Walk(deltaTime);
}

void Enemy::Walk(float deltaTime)
{
    position.x += speed * deltaTime;
}


//Getter and Setters
void Enemy::setHealth(int health)
{
    this->health = health;
}

int Enemy::getHealth() const
{
    return health;
}

void Enemy::setSpeed(float speed)
{
    this->speed = speed;
}

float Enemy::getSpeed() const
{
    return speed;
}

void Enemy::setGroupSize(int groupSize)
{
    this->groupSize = groupSize;
}

int Enemy::getGroupSize() const
{
    return groupSize;
}

