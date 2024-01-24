#ifndef ENEMY_H
#define ENEMY_H
#include <rt2d/entity.h>


class Enemy : public Entity
{
public:
    Enemy();
    virtual ~Enemy();

    void update(float deltaTime);
    void Walk(float deltaTime);

    // Getters and Setters
    void setHealth(int health);
    int getHealth() const;

    void setSpeed(float speed);
    float getSpeed() const;

    void setGroupSize(int groupSize);
    int getGroupSize() const;



private:
    int health;
    float speed;
    int groupSize;
};



#endif