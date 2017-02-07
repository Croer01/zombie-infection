#ifndef ENEMY_H
#define ENEMY_H

#include "Arduino.h"
#include "SlimLib.h"

class Player;
class Scene;

class Enemy {
  private:
    static const int ENEMY_SPEED = 1;

    char *enemyImage;
    boolean active;
    Rect bounds;

  public:
    Enemy();

    void update(Player *player, Scene *scene);

    void render();

    void hurt();

    Rect getBounds();

    void respawn(byte x, byte y);

    boolean isActive();
};

#endif
