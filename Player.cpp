#include "Player.h"
#include "globals.h"
#include "Sprites.h"
#include "Camera.h"
#include "scene.h"
#include "SlimLib.h"

void Player::shootBullet() {
  boolean active = false;
  byte i = 0;
  while (!active && i < BULLETS_LENGTH) {
    if (!bullets[i].isActive()) {
      bullets[i].respawn(playerImage == playerWalkRight ? bounds->getX() : bounds->getX() + bounds->getW(), bounds->getY() + 4, playerImage == playerWalkRight);
      active = true;
    }
    i++;
  }
}

void Player::moveCamera(int offsetX, int offsetY) {
  int posX = Camera::getInstance()->getX() + bounds->getX();
  int posY = Camera::getInstance()->getY() + bounds->getY() ;

  if (posX <= HORIZONTAL_BOUND && offsetX > 0 ||
      posX >= WIDTH - HORIZONTAL_BOUND - bounds->getW() && offsetX < 0 ||
      posY <= VERTICAL_BOUND && offsetY > 0 ||
      posY >= HEIGHT - VERTICAL_BOUND - bounds->getH() && offsetY < 0 ) {
    Camera::getInstance()->moveCamera(offsetX, offsetY);
  }
};
Player::Player() {
  this->playerImage = playerWalkRight;
  bounds = new Rect();
  bounds->setX(0);
  bounds->setY(0);
  bounds->setW(8);
  bounds->setH(8);
  timer = millis();
};

void Player::update(Scene *scene) {
  int velX = 0;
  int velY = 0;
  int previousX = bounds->getX();
  int previousY = bounds->getY();

  //move player
  if (arduboy.pressed(RIGHT_BUTTON) && bounds->getX() < Camera::getInstance()->getW() - bounds->getW()) {
    velX = PLAYER_SPEED;
    playerImage = playerWalkRight;
  }

  if (arduboy.pressed(LEFT_BUTTON) && bounds->getX() > 0) {
    velX = -PLAYER_SPEED;
    playerImage = playerWalkLeft;
  }

  if (arduboy.pressed(UP_BUTTON) && bounds->getY() > 0) {
    velY = -PLAYER_SPEED;
  }

  if (arduboy.pressed(DOWN_BUTTON) && bounds->getY() < Camera::getInstance()->getH() - bounds->getH()) {
    velY = PLAYER_SPEED;
  }

  scene->checkCollisionAndMove(*this->bounds, velX, velY);

  //clamp position to camera limits
  bounds->setX(constrain(bounds->getX() + velX, 0, Camera::getInstance()->getW() - bounds->getW()));
  bounds->setY(constrain(bounds->getY() + velY, 0, Camera::getInstance()->getH() - bounds->getH()));

  moveCamera(previousX - bounds->getX(), previousY - bounds->getY());

  //shoot
  if (timer <= millis() && arduboy.pressed(B_BUTTON)) {
    timer = millis() + COOLDOWN_MILLIS;
    shootBullet();
  }

  //update bullets
  for (byte i = 0; i < BULLETS_LENGTH; i++) {
    bullets[i].update();
  }
};

void Player::render() {
  arduboy.fillRect(Camera::getInstance()->getX() + bounds->getX() - 1, Camera::getInstance()->getY() + bounds->getY() - 1, bounds->getW() + 2, bounds->getH() + 2, BLACK);
  arduboy.drawBitmap(Camera::getInstance()->getX() + bounds->getX(), Camera::getInstance()->getY() + bounds->getY() , playerImage, bounds->getW(), bounds->getH(), WHITE);

  for (byte i = 0; i < BULLETS_LENGTH; i++) {
    bullets[i].render();
  }
};

Bullet *Player::getBullets(size_t& arraySize) {
  arraySize = BULLETS_LENGTH;
  return bullets;
};

Rect *Player::getBounds() {
  return bounds;
}