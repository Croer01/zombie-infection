#ifndef BULLET_H
#define BULLET_H

#include "SlimLib.h"

#define BULLET_UP 0
#define BULLET_RIGHT 1
#define BULLET_DOWN 2
#define BULLET_LEFT 3

typedef int BulletDirection;

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
