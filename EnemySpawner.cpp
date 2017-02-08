#include "EnemySpawner.h"
#include "scene.h"

EnemySpawner::EnemySpawner(Vector2 center) {
  bounds.setX(center.getX() - 8);
  bounds.setY(center.getY() - 4);
  bounds.setW(16);
  bounds.setH(8);
  timer = millis();
  active = true;
}

EnemySpawner::EnemySpawner() {
  bounds.setX(-8);
  bounds.setY(-4);
  bounds.setW(16);
  bounds.setH(8);
  timer = millis();
  active = true;
}

void EnemySpawner::update(Scene *scene) {
  Player *player = scene->getPlayer();
  if (active) {
    //check if hurt by bullet
    size_t bulletsLength = 0;
    Bullet *playerBullets = player->getBullets(bulletsLength);

    for (int i = 0; i < bulletsLength; i++) {
      if (playerBullets[i].isActive() && bounds.pointIsInside(playerBullets[i].getPosition())) {
        playerBullets[i].disable();
        this->hurt();
      }
    }

    if (timer <= millis()) {
      spawnEnemy();
      timer = millis() + COOLDOWN_MILLIS;
    }
  }
  //update enemies
  for (int i = 0; i < ENEMIES_LENGTH; i++) {
    enemies[i].update(player, scene);
  }
}

void EnemySpawner::render() {
  if (active) {
    arduboy.drawBitmap(Camera::getInstance()->getX() + bounds.getX(), Camera::getInstance()->getY() + bounds.getY(), enemySpawner, bounds.getW(), bounds.getH(), WHITE);
  }
  
  for (int i = 0; i < ENEMIES_LENGTH; i++) {
    enemies[i].render();
  }
};

void EnemySpawner::spawnEnemy() {
  Enemy *enemy = NULL;
  int i = 0;

  while (enemy == NULL && i < ENEMIES_LENGTH) {
    if (!enemies[i].isActive())
      enemy = &enemies[i];

    i++;
  }

  if (enemy != NULL) {
    enemy->respawn(bounds.getX() + bounds.getW()/2, bounds.getY() + bounds.getH()/2);
  }
}


void EnemySpawner::hurt() {
  active = false;
}
