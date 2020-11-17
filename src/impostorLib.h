#include "raylib.h"

#ifndef _IMPOSTOR_GUARD_H
#define _IMPOSTOR_GUARD_H

struct ImpostorGame{
    int screenWidth;
    int screenHeight;
    int screenCenterWidth;
    int screenCenterHeight;
    int fps;
};

struct Player_ref{
    int                 isLive; 
    int                 isMoving;  
    int                 cards[3];   // Deck of cards
    int                 frame;      // Visible frame
    int                 maxFrames;  // Frames in the Texture
    float               frameWidth; // Width of the Colider
    float               frameHeight;// Height of the Colider
    float               timer;      // Helper Timer for animation
    char*               c_player;   // Color of the character
    char*               name;       // Name of the player
    struct Rectangle    frameRec;   // Rectangle Frame Colider
    struct Vector2      position;   // Position in the window
    Texture2D    skin[4];    // 0 = Stand Right || 1 = Stand Left || 2 = Walking Right || 3 = Walking Left  
    struct Player_ref*  next;       // Pointer To Create a CLL
};
typedef struct Player_ref* Player;


struct GameHistory{
    
};

struct Board{
    
};


struct Notebook{
    
};

struct Accusations{

};

typedef struct ImpostorGame* GameState, GameInitialState;

GameState newImpostorGame();
Player newPlayer(GameState, char[10]);
void playImpostor(GameState);
void endImpostor();
void initImpostor();

#endif