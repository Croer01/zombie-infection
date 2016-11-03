#ifndef SCENES_H
#define SCENES_H

#include "globals.h"
#include "Player.h"
#include "Camera.h"
#include "Enemy.h"

class Scene {
    static const int CELLS_X_NUM = 20;
    static const int CELLS_Y_NUM = 10;
    static const int CELL_SIZE = 10;
    Player player;
    Enemy enemy[ENEMIES_LENGTH];

  public:
    Scene() {
      Camera::getInstance()->setBounds(CELLS_PER_ROW * CELL_SIZE, CELLS_PER_COLUMN * CELL_SIZE);
      for (int i = 0; i < ENEMIES_LENGTH; i++) {
        enemy[i].respawn(20 + i * 20, 20 + i * 20);
      }
    }

    void update() {
      player.update();

      for (int i = 0; i < ENEMIES_LENGTH; i++) {
        enemy[i].update(&player);
      }
    };

    void render() {
      for (int i = 0; i < CELLS_X_NUM; i++) {
        for (int j = 0; j < CELLS_Y_NUM; j++) {
          if (j % 2 != 0 && i % 2 == 0 || j % 2 == 0 && i % 2 != 0)
            arduboy.fillRect(Camera::getInstance()->getX() + i * CELL_SIZE, Camera::getInstance()->getY() + j * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
        }
      }

      player.render();
      for (int i = 0; i < ENEMIES_LENGTH; i++) {
        enemy[i].render();
      }
    };
};

#endif
