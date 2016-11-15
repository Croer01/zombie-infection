#include "Bullet.h"
#include "globals.h"
#include "Camera.h"

    Bullet::Bullet() {
      position.setX(0);
      position.setY(0);
      this->direction = BULLET_LEFT;
      active = false;
    };

    void Bullet::update() {
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

    void Bullet::render() {
      if (active) {
        arduboy.fillCircle(Camera::getInstance()->getX() + position.getX(), Camera::getInstance()->getY() +  position.getY(), 2, BLACK);
        arduboy.fillCircle(Camera::getInstance()->getX() + position.getX(), Camera::getInstance()->getY() +  position.getY(), 1, WHITE);
      }
    };

    bool Bullet::isActive() {
      return active;
    }

    void Bullet::disable() {
      active = false;
    }

    void Bullet::respawn(int x, int y, BulletDirection direction) {
      position.setX(x);
      position.setY(y);
      this->direction = direction;
      active = true;
      arduboy.tunes.tone(100, 100);
    }

    Vector2 Bullet::getPosition() {
      return position;
    };
