#ifndef SLIMLIB_H
#define SLIMLIB_H

class Vector2 {
    int x;
    int y;
  public:
    Vector2() {
      x = 0;
      y = 0;
    }

    Vector2(int x, int y) {
      this->x = x;
      this->y = y;
    }

    int getX() {
      return x;
    };
    void setX(int x) {
      this->x = x;
    };
    int getY() {
      return y;
    };
    void setY(int y) {
      this->y = y;
    };
};

class Rect {
    int x;
    int y;
    int w;
    int h;
  public:
    Rect() {
      x = 0;
      y = 0;
    }

    Rect(int x, int y, int w, int h) {
      this->x = x;
      this->y = y;
      this->w = w;
      this->h = h;
    }

    boolean pointIsInside(Vector2 point) {
      return x <= point.getX() && point.getX() <= x + w && y <= point.getY() && point.getY() <= y + h;
    };

    boolean rectIsInside(Rect other) {
      return (x <= other.getX() && other.getX() <= x + w && y <= other.getY() && other.getY() <= y + h) ||
             (x <= other.getX() + other.getW() && other.getX() + other.getW() <= x + w && y <= other.getY() + other.getH() && other.getY() + other.getH() <= y + h);
    };

    int getX() {
      return x;
    };
    void setX(int x) {
      this->x = x;
    };
    int getY() {
      return y;
    };
    void setY(int y) {
      this->y = y;
    };
    int getW() {
      return w;
    };
    void setW(int w) {
      this->w = w;
    };
    int getH() {
      return h;
    };
    void setH(int h) {
      this->h = h;
    };
};

#endif
