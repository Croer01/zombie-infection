#ifndef BULLET_H
#define BULLET_H

#include "globals.h"
#include "Camera.h"
#include "SlimLib.h"

#define BULLET_RIGHT true
#define BULLET_LEFT false

typedef boolean BulletDirection;

class Bullet {
    static const int BULLET_SPEED = 7;
  private:
    BulletDirection direction;
    Vector2 position;
    boolean active;
  public:
    Bullet() {
      position.setX(0);
      position.setY(0);
      this->direction = BULLET_LEFT;
      active = false;
    };

    void update() {
      if (active) {
        if (direction == BULLET_RIGHT) {
          position.setX(position.getX() + BULLET_SPEED);
        } else if (direction == BULLET_LEFT) {
          position.setX(position.getX() - BULLET_SPEED);
        }

        int cameraX = Camera::getInstance()->getX() + position.getX();
        if (cameraX < 0 || cameraX > WIDTH) {
          disable();
        }
      }
    };

    void render() {
      if (active) {
        arduboy.fillCircle(Camera::getInstance()->getX() + position.getX(), Camera::getInstance()->getY() +  position.getY(), 2, BLACK);
        arduboy.fillCircle(Camera::getInstance()->getX() + position.getX(), Camera::getInstance()->getY() +  position.getY(), 1, WHITE);
      }
    };

    boolean isActive() {
      return active;
    }

    disable() {
      active = false;
    }

    void respawn(int x, int y, BulletDirection direction) {
      position.setX(x);
      position.setY(y);
      this->direction = direction;
      active = true;
      arduboy.tunes.tone(100, 100);
    }

    Vector2 getPosition() {
      return position;
    };
};

#endif
