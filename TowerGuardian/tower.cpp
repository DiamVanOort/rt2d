#include "tower.h"
#include "enemy.h"
#include "myscene.h"

Tower::Tower() : Entity()
{
    // Set the Tower sprite
    this->addSprite("assets/GridNoPath.tga");
    this->sprite()->color = CYAN;
    this->scale = Point3(0.8f,0.8f,1.0f);
    setFirespeed(100);
    setDamage(25);   
}

Tower::~Tower()
{

    
}

void Tower::update(float deltaTime)
{

}


//Getter and Setters
void Tower::setFirespeed(int firespeed)
{
    this->Firespeed = firespeed;
}

int Tower::getFirespeed() const
{
    return Firespeed;
}

void Tower::setDamage(int damage)
{
    this->Damage = damage;
}

int Tower::getDamage() const
{
    return Damage;
}

