#ifndef SCENES_H
#define SCENES_H

#include "globals.h"
#include "Player.h"
#include "Camera.h"
#include "Enemy.h"
#include "SlimLib.h"
#include "Sprites.h"

PROGMEM const unsigned char sceneLayout[] = {
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
  1, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
  1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,  
  1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
  1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1,
  1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

class Scene {
    static const int CELLS_PER_ROW = 32;
    static const int CELLS_PER_COLUMN = 32;
    static const int CELL_SIZE = 8;
    static const byte ENEMIES_LENGTH = 5;
    Player player;
    Enemy enemy[ENEMIES_LENGTH];

  public:
    Scene() {
      player.getBounds()->setX(2 * CELL_SIZE);
      player.getBounds()->setY(2 * CELL_SIZE);
      Camera::getInstance()->setBounds(CELLS_PER_ROW * CELL_SIZE, CELLS_PER_COLUMN * CELL_SIZE);
      for (int i = 0; i < ENEMIES_LENGTH; i++) {
        enemy[i].respawn(20 + i * 20, 20 + i * 20);
      }
    }

    void update() {
      player.update(this);
      
      //check bullets collisions
      size_t bulletsLength = 0;
      Bullet *playerBullets = player.getBullets(bulletsLength);

      for (int i = 0; i < bulletsLength; i++) {
        if (playerBullets[i].isActive() && getCellByPos(playerBullets[i].getPosition()) == 0x01) {
          playerBullets[i].disable();
        }
      }

      for (int i = 0; i < ENEMIES_LENGTH; i++) {
        enemy[i].update(&player, this);
      }
    };

    void render() {
      for (int i = 0; i < CELLS_PER_ROW; i++) {
        for (int j = 0; j < CELLS_PER_COLUMN; j++) {
          int index = j * CELLS_PER_ROW + i;

          int tile = (int)pgm_read_byte_near(sceneLayout + index);

          if(tile != 0)
            arduboy.drawBitmap(Camera::getInstance()->getX() + i * CELL_SIZE, Camera::getInstance()->getY() + j * CELL_SIZE, sceneAtlas + tile * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
        }
      }
      
      player.render();
      for (int i = 0; i < ENEMIES_LENGTH; i++) {
        enemy[i].render();
      }
    };

    void checkCollisionAndMove(Rect& bounds, int& velX, int& velY) {
      //check horizontal collision
      if (velX != 0) {
        int x = velX > 0 ? bounds.getX() + bounds.getW() + 1 : bounds.getX();
        Vector2 first = {x: x + velX, y: bounds.getY()};
        Vector2 second = {x: x + velX, y: bounds.getY() + bounds.getH()};

        if (getCellByPos(first) == 0x01 || getCellByPos(second) == 0x01) {
          velX = calculateNewVelocity(x, velX);
        }
      }

      //check vertical collision
      if (velY != 0) {
        int y = velY > 0 ? bounds.getY() + bounds.getH() + 1 : bounds.getY();
        Vector2 first = {x: bounds.getX(), y: y + velY };
        Vector2 second = {x: bounds.getX() + bounds.getW(), y: y + velY };

        if (getCellByPos(first) == 0x01 || getCellByPos(second) == 0x01) {
          velY = calculateNewVelocity(y, velY);
        }
      }
    };

  private:

    unsigned char getCellByPos(Vector2 pos) {
      int x = pos.getX() / CELL_SIZE;
      int y = pos.getY() / CELL_SIZE;
      return pgm_read_byte_near(sceneLayout + (x * CELLS_PER_ROW + y));
    };


    int calculateNewVelocity(int currentPos, int velocity) {
      int newVelocity = velocity;
      int cellPosition = (currentPos + velocity) / CELL_SIZE;

      if (velocity < 0) {
        newVelocity = currentPos - (cellPosition * CELL_SIZE + CELL_SIZE);
      } else if (velocity > 0) {
        newVelocity = cellPosition * CELL_SIZE - currentPos;
      }
      return newVelocity;
    };
};

#endif
