#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "Bullet.h"
#include "Sprites.h"
#include "Camera.h"
#include "SlimLib.h"

class Player {
  private:
    static const byte BULLETS_LENGTH = 7;
    static const uint32_t COOLDOWN_MILLIS = 150;
    static const int VERTICAL_BOUND = 20;
    static const int HORIZONTAL_BOUND = 42;
    static const int PLAYER_SPEED = 2;

    char *playerImage;
    Rect bounds;
    Bullet bullets[BULLETS_LENGTH];
    uint32_t timer;

    void shootBullet() {
      boolean active = false;
      byte i = 0;
      while (!active && i < BULLETS_LENGTH) {
        if (!bullets[i].isActive()) {
          bullets[i].respawn(playerImage == playerWalkRight ? bounds.getX() : bounds.getX() + bounds.getW(), bounds.getY() + 4, playerImage == playerWalkRight);
          active = true;
        }
        i++;
      }
    }

    void moveCamera(int offsetX, int offsetY) {
      int posX = Camera::getInstance()->getX() + bounds.getX();
      int posY = Camera::getInstance()->getY() + bounds.getY() ;

      if (posX <= HORIZONTAL_BOUND && offsetX > 0 ||
          posX >= WIDTH - HORIZONTAL_BOUND - bounds.getW() && offsetX < 0 ||
          posY <= VERTICAL_BOUND && offsetY > 0 ||
          posY >= HEIGHT - VERTICAL_BOUND - bounds.getH() && offsetY < 0 ) {
        Camera::getInstance()->moveCamera(offsetX, offsetY);
      }
    };
  public:
    Player() {
      this->playerImage = playerWalkRight;
      bounds.setX(0);
      bounds.setY(0);
      bounds.setW(8);
      bounds.setH(8);
      timer = millis();
    };

    void update(Scene *scene) {
      int velX = 0;
      int velY = 0;

      //move player
      if (arduboy.pressed(RIGHT_BUTTON) && bounds.getX() < Camera::getInstance()->getW() - bounds.getW()) {
        velX = min(bounds.getX() + PLAYER_SPEED, Camera::getInstance()->getW() - bounds.getW());
        playerImage = playerWalkRight;
      }

      if (arduboy.pressed(LEFT_BUTTON) && bounds.getX() > 0) {
        velX = max(bounds.getX() - PLAYER_SPEED, 0);
        playerImage = playerWalkLeft;
      }

      if (arduboy.pressed(UP_BUTTON) && bounds.getY() > 0) {
        velY = max(bounds.getY() - PLAYER_SPEED, 0);
      }

      if (arduboy.pressed(DOWN_BUTTON) && bounds.getY() < Camera::getInstance()->getH() - bounds.getH()) {
        velY = min(bounds.getY() + PLAYER_SPEED, Camera::getInstance()->getH() - bounds.getH());
      }

      scene->checkCollisionAndMove(this->bounds, velX, velY)

      moveCamera(velX, velY);

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

    void render() {
      arduboy.fillRect(Camera::getInstance()->getX() + bounds.getX() - 1, Camera::getInstance()->getY() + bounds.getY() - 1, bounds.getW() + 2, bounds.getH() + 2, BLACK);
      arduboy.drawBitmap(Camera::getInstance()->getX() + bounds.getX(), Camera::getInstance()->getY() + bounds.getY() , playerImage, bounds.getW(), bounds.getH(), WHITE);

      for (byte i = 0; i < BULLETS_LENGTH; i++) {
        bullets[i].render();
      }
    };

    Bullet *getBullets(size_t& arraySize) {
      arraySize = BULLETS_LENGTH;
      return bullets;
    };

    Rect getBounds() {
      return bounds;
    }
};

#endif
