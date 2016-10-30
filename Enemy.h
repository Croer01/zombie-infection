#ifndef ENEMY_H
#define ENEMY_H

#include "globals.h"
#include "Sprites.h"
#include "Player.h"

class Enemy {
  private:
    static const int ENEMY_SPEED = 1;

    char *enemyImage;
    byte x;
    byte y;

  public:
    Enemy() {
      this->enemyImage = enenmyWalkRight;
      x = 0;
      y = 0;
    };

    void update(Player *player) {
      if (x < player->getX())
        x++;
      else if (x > player->getX())
        x--;

      if (y < player->getY())
        y++;
      else if (y > player->getY())
        y--;
    };

    void render() {
      arduboy.fillRect(Camera::getInstance()->getX() + x - 1, Camera::getInstance()->getY() + y - 1, 10, 14, BLACK);
      arduboy.drawBitmap(Camera::getInstance()->getX() + x, Camera::getInstance()->getY() +  y, enemyImage, 8, 12, WHITE);
    };
};

#endif
