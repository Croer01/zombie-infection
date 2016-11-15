#ifndef CAMERA_H
#define CAMERA_H

class Camera {
    //singleton
  private:
    static Camera *instance;
    Camera();
    Camera(const Camera&);
    Camera& operator=(const Camera&);
  public:
    static Camera *getInstance();

    //object
  private:
    int x;
    int y;
    int w;
    int h;
  public:
    void moveCamera(int xMovement, int yMovement);
    void setBounds(int w, int h);
    int getX();
    int getY();
    int getW();
    int getH();
};


#endif
