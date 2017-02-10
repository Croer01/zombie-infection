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
    switch (direction) {
      case BULLET_UP:
        position.setY(position.getY() - BULLET_SPEED);
        break;
      case BULLET_RIGHT:
        position.setX(position.getX() + BULLET_SPEED);
        break;
      case BULLET_DOWN:
        position.setY(position.getY() + BULLET_SPEED);
        break;
      case BULLET_LEFT:
        position.setX(position.getX() - BULLET_SPEED);
        break;
    }

    int cameraX = Camera::getInstance()->getX() + position.getX();
    int cameraY = Camera::getInstance()->getY() + position.getY();
    
    if (cameraX < 0 || cameraX > WIDTH || cameraY < 0 || cameraY > HEIGHT) {
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
