#ifndef SCENES_H
#define SCENES_H

#include "globals.h"
#include "Player.h"
#include "Camera.h"
#include "EnemySpawner.h"
#include "SlimLib.h"
#include "Sprites.h"

//X,Y
/**
   Save entities positions in format X,Y
   The first row is player and the others are spawners.
   The third byte represent the number of spawners.
*/
PROGMEM const unsigned char scenePositions[] = {
  16, 16,
  2,
  50, 30,
  50, 50
};

PROGMEM const unsigned char sceneLayout[16] = {
  0, 1, 1, 2,
  7, 8, 8, 3,
  7, 8, 9, 3,
  6, 5, 5, 4
};

class Scene {
    static const int CELLS_PER_ROW = 32; //4 chunks of 8 tiles
    static const int CELLS_PER_COLUMN = 32; //4 chunks of 8 tiles
    static const int CELL_SIZE = 8;

    Player player;
    EnemySpawner **spawner;
    int spawnerLength;

  public:
    Scene() {
      Vector2 playerPos = getInitialPosition(0);
      player.getBounds()->setX(playerPos.getX());
      player.getBounds()->setY(playerPos.getY());
      Camera::getInstance()->setBounds(CELLS_PER_ROW * CELL_SIZE, CELLS_PER_COLUMN * CELL_SIZE);

      spawnerLength = (int)pgm_read_byte_near(scenePositions + 2);

      spawner = new EnemySpawner*[spawnerLength];
      for (int i = 0; i < spawnerLength; i++) {
        spawner[i] = new EnemySpawner(getInitialPosition(3 + 2 * i));
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

      for (int i = 0; i < spawnerLength; i++) {
        spawner[i]->update(this);
      }
    };

    void render() {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          int index = j * 4 + i;

          int chunkId = (int)pgm_read_byte_near(sceneLayout + index);
          char *chunk = sceneChunks[chunkId];
          renderChunk(i * 8, j * 8, chunk);
        }
      }

      for (int i = 0; i < spawnerLength; i++) {
        spawner[i]->render();
      }

      player.render();

    };

    void renderChunk(int xOffset, int yOffset, const char *chunk) {
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          int index = j * 8 + i;
          int tile = (int)pgm_read_byte_near(chunk + index);

          int x = xOffset * CELL_SIZE + i * CELL_SIZE;
          int y = yOffset * CELL_SIZE + j * CELL_SIZE;
          if (tile != 0)
            arduboy.drawBitmap(Camera::getInstance()->getX() + x, Camera::getInstance()->getY() + y, sceneAtlas + tile * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
        }
      }
    }

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

    Player* getPlayer() {
      return &player;
    };

  private:

    unsigned char getCellByPos(Vector2 pos) {
      int x = pos.getX() / CELL_SIZE;
      int y = pos.getY() / CELL_SIZE;
      int chunkXOffset = x / 8;
      int chunkYOffset = y / 8;

      char *chunk = sceneChunks[(int)pgm_read_byte_near(sceneLayout + (chunkXOffset + chunkYOffset * 4))];
      return pgm_read_byte_near(chunk + ((y - chunkYOffset * 8) * 8) + (x - chunkXOffset * 8));
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

    Vector2 getInitialPosition(int id) {
      return Vector2((int)pgm_read_byte_near(scenePositions + id), (int)pgm_read_byte_near(scenePositions + id + 1));
    }
};

#endif
