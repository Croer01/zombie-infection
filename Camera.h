#ifndef CAMERA_H
#define CAMERA_H

#include "globals.h"

class Camera {
    //singleton
  private:
    static Camera *instance;
    Camera() {
      x = 0;
      y = 0;
      w = 0;
      h = 0;
    };
    Camera(const Camera&);
    Camera& operator=(const Camera&);
  public:
    static Camera *getInstance() {
      if (!instance)
        instance = new Camera();

      return instance;
    };

    //object
  private:
    int x;
    int y;
    int w;
    int h;
  public:

    void moveCamera(int xMovement, int yMovement) {
      x = constrain(x + xMovement, -w + WIDTH, 0);
      y = constrain(y + yMovement, -h + HEIGHT, 0);
    };

    void setBounds(int w, int h) {
      this->w = w;
      this->h = h;
    };

    int getX() {
      return x;
    };
    int getY() {
      return y;
    };

    int getW() {
      return w;
    };
    int getH() {
      return h;
    };
};

//initialize singleton variable
Camera *Camera::instance = NULL;

#endif
