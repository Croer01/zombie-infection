#include "globals.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"

Scene scene;

void setup() {
  Serial.begin(9600);
  //initiate arduboy instance
  arduboy.begin();

  // here we set the framerate to 30, we do not need to run at default 60 and
  // it saves us battery life.
  arduboy.setFrameRate(30);
}

void loop() {
  // pause render until it's time for the next frame
  if (!arduboy.nextFrame())
    return;

  // we clear our screen to black
  arduboy.clear();

  scene.update();
  scene.render();

  // then we finaly we tell the arduboy to display what we just wrote to the display.
  arduboy.display();
}

