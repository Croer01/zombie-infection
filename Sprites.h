#ifndef SPRITE_H
#define SPRITE_H

//Player
//size 8x8
PROGMEM const unsigned char playerWalkLeft[] = { 0xFF, 0xF1, 0x71, 0x7F, 0x71, 0x71, 0xFF, 0xFF};

//size 8x8
PROGMEM const unsigned char playerWalkRight[] = {0xFF, 0xFF, 0x71, 0x71, 0x7F, 0x71, 0xF1, 0xFF};

//Enemy
//size 8x12
PROGMEM const unsigned char enenmyWalkRight[] = {0xFF, 0xFF, 0x11, 0x73, 0x1F, 0x73, 0x11, 0x7F, 0x0F, 0x0F, 0x07, 0x06, 0x07, 0x06, 0x0F, 0x0E};

//size 8x12
PROGMEM const unsigned char enenmyWalkLeft[] = {0x7F, 0x11, 0x73, 0x1F, 0x73, 0x11, 0xFF, 0xFF, 0x0E, 0x0F, 0x06, 0x07, 0x06, 0x07, 0x0F, 0x0F};

//Enemy spawner
//size 16x8
PROGMEM const unsigned char PROGMEM enemySpawner[] =
{
0xa8, 0x5c, 0xaa, 0x72, 0x69, 0x71, 0x29, 0xb5, 
0xa9, 0xb5, 0xa9, 0x31, 0x6a, 0xf2, 0xac, 0x50, 
};

// width = 8, height = 8
PROGMEM const unsigned char sceneAtlas[] = {
  //dummy tyle
  0,0,0,0,0,0,0,0,
  // tile 1: wall
  0x9D,0xA3,0x6C,0x8D,0xAD,0xA3,0x6C,0xAD,
  // tile 2: ground
  0x00,0x00,0x00,0x04,0x08,0x00,0x0E,0x00,
  // tile 3: ground 2
  0x00,0x04,0x0E,0x0A,0x04,0x40,0x10,0x00,
  // tile 4: dirt road
  0xB2,0x40,0x12,0x06,0xA8,0x20,0xAA,0xC1,
  // tile 5: floor tiled
  //0x81,0x24,0x5A,0x24,0x24,0x5A,0x24,0x81
  0x00,0x42,0x18,0x24,0x24,0x18,0x42,0x00, 
  
};

/* 0 1 2
 * 7 8 3
 * 6 5 4
 */
PROGMEM const unsigned char sceneChunks[][64] = {
  {
    //-- Basic chunks--
    //Chunk 0
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 2, 3, 0, 0, 0, 0,
    1, 0, 0, 2, 0, 0, 2, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 3, 0, 0,
    1, 3, 0, 2, 0, 0, 0, 0,
    1, 0, 0, 0, 2, 0, 0, 0
  },{
    //Chunk 1
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 2, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 2, 0, 0, 0, 0, 3, 2,
    2, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 3, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, 0
  },{
    //Chunk 2
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 3, 0, 0, 1,
    0, 2, 0, 0, 0, 0, 0, 1,
    0, 3, 0, 0, 0, 0, 0, 1,
    2, 0, 0, 0, 0, 3, 0, 1,
    0, 0, 2, 0, 2, 0, 0, 1,
    0, 0, 0, 3, 0, 2, 0, 1
  },{
    //Chunk 3
    0, 0, 0, 2, 3, 3, 0, 1,
    0, 0, 0, 3, 2, 0, 0, 1,
    0, 0, 0, 0, 3, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 3, 0, 0, 0, 0, 0, 1,
    3, 2, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 2, 0, 0, 1,
    0, 0, 0, 3, 0, 0, 3, 1
  },{
    //Chunk 4
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 3, 0, 0, 1,
    0, 2, 0, 0, 0, 0, 0, 1,
    0, 3, 0, 0, 0, 0, 0, 1,
    2, 0, 0, 0, 0, 3, 0, 1,
    0, 0, 2, 0, 2, 0, 0, 1,
    0, 0, 0, 3, 0, 2, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1
  },{
    //Chunk 5
    0, 0, 0, 2, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 2, 0, 0, 0, 0, 3, 2,
    2, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 3, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, 0,
    1, 1, 1, 1, 1, 1, 1, 1
  },{
    //Chunk 6
    1, 0, 0, 0, 2, 0, 0, 0,
    1, 0, 0, 0, 0, 2, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 3, 2, 0, 0, 0, 3, 2,
    1, 2, 0, 0, 0, 2, 0, 0,
    1, 0, 0, 0, 3, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 2, 0,
    1, 1, 1, 1, 1, 1, 1, 1
  },{
    //Chunk 7
    1, 2, 0, 0, 0, 2, 0, 0,
    1, 0, 0, 0, 2, 0, 0, 0,
    1, 0, 0, 0, 0, 2, 0, 0,
    1, 0, 0, 0, 3, 0, 0, 0,
    1, 3, 2, 0, 0, 0, 3, 2,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 2, 0,
    1, 2, 0, 0, 0, 2, 0, 0
  },{
    //Chunk 8
    0, 0, 0, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 3, 2, 0, 0, 0,
    2, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 0, 0,
    3, 2, 0, 0, 0, 0, 3, 2,
    0, 0, 0, 0, 0, 0, 2, 0
  },{
    //-- Extra chunks--
    //Chunk 9
    0, 0, 0, 4, 4, 0, 0, 2,
    0, 1, 1, 5, 5, 1, 1, 0,
    2, 1, 5, 5, 5, 5, 1, 0,
    2, 1, 5, 5, 5, 5, 1, 0,
    0, 1, 5, 5, 5, 5, 1, 0,
    3, 1, 1, 1, 1, 1, 1, 0,
    3, 3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 0, 0
  }
};
#endif
