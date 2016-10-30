#ifndef SCENES_H
#define SCENES_H

#include "globals.h"
#include "Player.h"
#include "Camera.h"

class Scene {
    static const int CELLS_X_NUM = 20;
    static const int CELLS_Y_NUM = 10;
    static const int CELL_SIZE = 10;
    Player player;

  public:
    Scene() {
      Camera::getInstance()->setBounds(CELLS_X_NUM * CELL_SIZE, CELLS_Y_NUM * CELL_SIZE);
    }

    void update() {
      player.update();
    };

    void render() {
      for (int i = 0; i < CELLS_X_NUM; i++) {
        for (int j = 0; j < CELLS_Y_NUM; j++) {
          if (j % 2 != 0 && i % 2 == 0 || j % 2 == 0 && i % 2 != 0)
            arduboy.fillRect(Camera::getInstance()->getX() + i * CELL_SIZE, Camera::getInstance()->getY() + j * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
        }
      }

      player.render();
    };
};

#endif
