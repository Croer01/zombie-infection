#include "Enemy.h"
#include "globals.h"
#include "Sprites.h"
#include "Player.h"
#include "scene.h"
#include "Camera.h"

Enemy::Enemy() {
  this->enemyImage = enenmyWalkRight;
  bounds.setX(0);
  bounds.setY(0);
  bounds.setW(8);
  bounds.setH(12);
  active = false;
};

void Enemy::update(Player *player, Scene *scene) {
  if (active) {
    int velX = 0;
    int velY = 0;
    //move to player
    if (bounds.getX() < player->getBounds()->getX()) {
      velX = 1;
      this->enemyImage = enenmyWalkRight;
    } else if (bounds.getX() > player->getBounds()->getX()) {
      velX = -1;
      this->enemyImage = enenmyWalkLeft;
    }

    if (bounds.getY() < player->getBounds()->getY())
      velY = 1;
    else if (bounds.getY() > player->getBounds()->getY())
      velY = -1;

    scene->checkCollisionAndMove(this->bounds, velX, velY);

    bounds.setX(bounds.getX() + velX);
    bounds.setY(bounds.getY() + velY);
    
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

void Enemy::render() {
  if (active) {
    arduboy.fillRect(Camera::getInstance()->getX() + bounds.getX() - 1, Camera::getInstance()->getY() + bounds.getY() - 1, bounds.getW() + 2, bounds.getH() + 2, BLACK);
    arduboy.drawBitmap(Camera::getInstance()->getX() + bounds.getX(), Camera::getInstance()->getY() +  bounds.getY(), enemyImage, bounds.getW(), bounds.getH(), WHITE);
  }
};

void Enemy::hurt() {
  active = false;
}

Rect Enemy::getBounds() {
  return bounds;
};

void Enemy::respawn(byte x, byte y) {
  bounds.setX(x);
  bounds.setY(y);
  active = true;
}

boolean Enemy::isActive(){
  return active;
}
