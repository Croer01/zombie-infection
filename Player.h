#ifndef PLAYER_H
#define PLAYER_H

#include "Arduino.h"
#include "Bullet.h"

class Scene;

class Player {
  private:
    static const byte BULLETS_LENGTH = 7;
    static const uint32_t COOLDOWN_MILLIS = 150;
    static const int VERTICAL_BOUND = 20;
    static const int HORIZONTAL_BOUND = 42;
    static const int PLAYER_SPEED = 2;

    char *playerImage;
    Rect *bounds;
    Bullet bullets[BULLETS_LENGTH];
    uint32_t timer;

    void shootBullet();

    void moveCamera(int offsetX, int offsetY);
  public:
    Player();

    void update(Scene *scene);

    void render();

    Bullet *getBullets(size_t& arraySize);

    Rect *getBounds();
};

#endif
