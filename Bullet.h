#ifndef BULLET_H
#define BULLET_H

#include "globals.h"
#include "Camera.h"

#define BULLET_RIGHT true
#define BULLET_LEFT false

typedef boolean BulletDirection;

class Bullet {
  private:
    BulletDirection direction;
    byte x;
    byte y;
    boolean active;
  public:
    Bullet() {
      this->x = 0;
      this->y = 0;
      this->direction = BULLET_LEFT;
      active = false;
    };

    void update() {
      if (active) {
        if (direction == BULLET_RIGHT) {
          x += 5;
        } else if (direction == BULLET_LEFT) {
          x -= 5;
        }

        int cameraX = Camera::getInstance()->getX() + x;
        if (cameraX < 0 || cameraX > WIDTH) {
          active = false;
        }
      }
    };

    void render() {
      if (active) {
        arduboy.fillCircle(Camera::getInstance()->getX() + x, Camera::getInstance()->getY() +  y, 2, BLACK);
        arduboy.fillCircle(Camera::getInstance()->getX() + x, Camera::getInstance()->getY() +  y, 1, WHITE);
      }
    };

    boolean isActive() {
      return active;
    }

    void respawn(byte x, byte y, BulletDirection direction) {
      this->x = x;
      this->y = y;
      this->direction = direction;
      active = true;
    }
};

#endif
