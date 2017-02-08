#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include "SlimLib.h"
#include "Enemy.h"

class Player;
class Scene;

class EnemySpawner {
    static const int ENEMIES_LENGTH = 5;
    static const uint32_t COOLDOWN_MILLIS = 5000;
    
    Enemy enemies[ENEMIES_LENGTH];
    Rect bounds;
    uint32_t timer;
    boolean active;
    
  public:
    EnemySpawner();
    
    EnemySpawner(Vector2 center);

    void update(Scene *scene);

    void render();

    void hurt();
    
  private:
    void spawnEnemy();
};

#endif
