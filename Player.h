#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "Bullet.h"
#include "Sprites.h"
#include "Camera.h"

class Player {
  private:
    static const byte BULLETS_LENGTH = 7;
    static const uint32_t COOLDOWN_MILLIS = 150;
    static const int VERTICAL_BOUND = 20;
    static const int HORIZONTAL_BOUND = 42;
    static const int PLAYER_SPEED = 2;

    char *playerImage;
    int x;
    int y;
    Bullet bullets[BULLETS_LENGTH];
    uint32_t timer;

    void shootBullet() {
      boolean active = false;
      byte i = 0;
      while (!active && i < BULLETS_LENGTH) {
        if (!bullets[i].isActive()) {
          bullets[i].respawn(x, y + 4, playerImage == playerWalkRight);
          active = true;
        }
        i++;
      }
    }

    void moveCamera(int offsetX, int offsetY) {
      int posX = Camera::getInstance()->getX() + x;
      int posY = Camera::getInstance()->getY() + y;

      if (posX <= HORIZONTAL_BOUND && offsetX > 0 ||
          posX >= WIDTH - HORIZONTAL_BOUND - 8 && offsetX < 0 ||
          posY <= VERTICAL_BOUND && offsetY > 0 ||
          posY >= HEIGHT - VERTICAL_BOUND - 8 && offsetY < 0 ) {
        Camera::getInstance()->moveCamera(offsetX, offsetY);
      }
    };
  public:
    Player() {
      this->playerImage = playerWalkRight;
      x = 0;
      y = 0;
      timer = millis();
    };

    void update() {
      int previousX = x;
      int previousY = y;

      //move player
      if (arduboy.pressed(RIGHT_BUTTON) && x < Camera::getInstance()->getW() - 8) {
        x = min(x + PLAYER_SPEED, Camera::getInstance()->getW() - 8);
        playerImage = playerWalkRight;
      }

      if (arduboy.pressed(LEFT_BUTTON) && x > 0) {
        x = max(x - PLAYER_SPEED, 0);
        playerImage = playerWalkLeft;
      }

      if (arduboy.pressed(UP_BUTTON) && y > 0) {
        y = max(y - PLAYER_SPEED, 0);
      }

      if (arduboy.pressed(DOWN_BUTTON) && y < Camera::getInstance()->getH() - 8) {
        y = min(y + PLAYER_SPEED, Camera::getInstance()->getH() - 8);
      }

      moveCamera(previousX - x, previousY - y);

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
      arduboy.fillRect(Camera::getInstance()->getX() + x - 1, Camera::getInstance()->getY() + y - 1, 10, 10, BLACK);
      arduboy.drawBitmap(Camera::getInstance()->getX() + x, Camera::getInstance()->getY() +  y, playerImage, 8, 8, WHITE);

      for (byte i = 0; i < BULLETS_LENGTH; i++) {
        bullets[i].render();
      }
    };

    Bullet *getBullets(size_t& arraySize) {
      arraySize = BULLETS_LENGTH;
      return bullets;
    };

    int getX() {
      return x;
    };
    int getY() {
      return y;
    };
};

#endif
