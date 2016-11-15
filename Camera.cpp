#include "Camera.h"
#include "globals.h"

//initialize singleton variable
Camera *Camera::instance = NULL;

//singleton
Camera::Camera() {
  x = 0;
  y = 0;
  w = 0;
  h = 0;
};

static Camera *Camera::getInstance() {
  if (!instance)
    instance = new Camera();

  return instance;
};

//object
void Camera::moveCamera(int xMovement, int yMovement) {
  x = constrain(x + xMovement, -w + WIDTH, 0);
  y = constrain(y + yMovement, -h + HEIGHT, 0);
};

void Camera::setBounds(int w, int h) {
  this->w = w;
  this->h = h;
};

int Camera::getX() {
  return x;
};
int Camera::getY() {
  return y;
};

int Camera::getW() {
  return w;
};

int Camera::getH() {
  return h;
};
