#ifndef TOWER_H
#define TOWER_H
#include <rt2d/entity.h>


class Tower : public Entity
{
public:
    Tower();
    virtual ~Tower();

    void update(float deltaTime);

    // Getters and Setters
    void setFirespeed(int health);
    int getFirespeed() const;

    void setDamage(int speed);
    int getDamage() const; 

    Timer* fireSpeed;
    float fireCooldown = 1.00f;

private:
    int Firespeed;
    int Damage;

    float fireTimer; // Timer to control the firing rate
};




#endif /* TOWER_H */