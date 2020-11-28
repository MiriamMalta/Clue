#ifndef _IMPOSTOR_GUARD_H
#define _IMPOSTOR_GUARD_H
#include "raylib.h"
//#include "mechanicsLib.h"

typedef enum {
    LOGO, 
    TRIBUTE, 
    DISCLAIMER, 
    MENU1, MENU2, MENU3, MENU4, MENU5, MENU6,
    NEWGAME,
    LOADGAME,
    SETTINGS,
    CREDITS,

} GameScreen;

struct GameSceneData{
    GameScreen          gameScreen;
    int                 state;
    float               alpha;
}; typedef struct GameSceneData* GameScene;


struct Box{
    int                 isRoom;
    char                status;         //f = free; b = blocked; p = player; and rooms
    Vector2             tilePosition;
};


struct BoardGame{
    Texture2D           mapBackground;
    Camera2D            camera;
    struct Box          boxes[24][24];
}; typedef struct BoardGame* Board;


struct Player_ref{
    int                 isLive; 
    int                 movingAnimate;
    int                 cards[3];   // Deck of cards
    int                 frame;      // Visible frame
    int                 maxFrames;  // Frames in the Texture
    int                 x;
    int                 y;
    float               frameWidth; // Width of the Colider
    float               frameHeight;// Height of the Colider
    float               timer;      // Helper Timer for animation
    char*               c_player;   // Color of the character
    char*               name;       // Name of the player
    struct Rectangle    frameRec;   // Rectangle Frame Colider
    struct Vector2      position;   // Position in the window
    Texture2D           skin[4];    // 0 = Stand Right || 1 = Stand Left || 2 = Walking Right || 3 = Walking Left  
    struct Player_ref*  next;       // Pointer To Create a CLL
};
typedef struct Player_ref* Player;


struct ImpostorGame{
    int                 screenWidth;
    int                 screenHeight;
    int                 screenCenterWidth;
    int                 screenCenterHeight;
    int                 fps;
    int                 gameScreen;
    int                 playersAlive;
    float               speed;
    GameScene           gameScene;
    Board               board;
    Player              playerInTurn;
};


struct GameHistory{
    
};




struct Notebook{
    
};

struct Accusations{

};

typedef struct ImpostorGame* GameState, GameInitialState;

GameState newImpostorGame();
Player newPlayer(GameState, char[10]);
Board NewBoard(GameState);

void newPlayerList(GameState);
void addPlayerToList(GameState, Player);

void playImpostor(GameState);
void endImpostor(GameState);
void initImpostor(GameState);

#endif