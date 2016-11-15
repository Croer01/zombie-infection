#ifndef BULLET_H
#define BULLET_H

#include "SlimLib.h"

#define BULLET_RIGHT true
#define BULLET_LEFT false

typedef bool BulletDirection;

class Bullet {
    static const int BULLET_SPEED = 7;
  private:
    BulletDirection direction;
    Vector2 position;
    bool active;
  public:
    Bullet();
    void update();
    void render();
    bool isActive();
    void disable();
    void respawn(int x, int y, BulletDirection direction);
    Vector2 getPosition();
};

#endif
