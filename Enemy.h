#ifndef ENEMY_H
#define ENEMY_H

#include "globals.h"
#include "Sprites.h"
#include "Player.h"
#include "SlimLib.h"

class Enemy {
  private:
    static const int ENEMY_SPEED = 1;

    char *enemyImage;
    boolean active;
    Rect bounds;

  public:
    Enemy() {
      this->enemyImage = enenmyWalkRight;
      bounds.setX(0);
      bounds.setY(0);
      bounds.setW(8);
      bounds.setH(12);
    };

    void update(Player *player) {
      if (active) {
        //move to player
        if (bounds.getX() < player->getBounds().getX()) {
          bounds.setX(bounds.getX() + 1);
          this->enemyImage = enenmyWalkRight;
        } else if (bounds.getX() > player->getBounds().getX()) {
          bounds.setX(bounds.getX() - 1);
          this->enemyImage = enenmyWalkLeft;
        }

        if (bounds.getY() < player->getBounds().getY())
          bounds.setY(bounds.getY() + 1);
        else if (bounds.getY() > player->getBounds().getY())
          bounds.setY(bounds.getY() - 1);

        //check if hurt by bullet

        size_t bulletsLength = 0;
        Bullet *playerBullets = player->getBullets(bulletsLength);

        for (int i = 0; i < bulletsLength; i++) {
          if (playerBullets[i].isActive() && this->getBounds().pointIsInside(playerBullets[i].getPosition())) {
            playerBullets[i].disable();
            this->hurt();
          }
        }
      }
    };

    void render() {
      if (active) {
        arduboy.fillRect(Camera::getInstance()->getX() + bounds.getX() - 1, Camera::getInstance()->getY() + bounds.getY() - 1, bounds.getW() + 2, bounds.getH() + 2, BLACK);
        arduboy.drawBitmap(Camera::getInstance()->getX() + bounds.getX(), Camera::getInstance()->getY() +  bounds.getY(), enemyImage, bounds.getW(), bounds.getH(), WHITE);
      }
    };

    void hurt() {
      active = false;
    }

    Rect getBounds() {
      return bounds;
    };

    void respawn(byte x, byte y) {
      bounds.setX(x);
      bounds.setY(y);
      active = true;
    }
};

#endif
