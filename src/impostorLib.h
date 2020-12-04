#ifndef _IMPOSTOR_GUARD_H
#define _IMPOSTOR_GUARD_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "raylib.h"

typedef enum {
    LOGO, 
    POWERED, 
    DISCLAIMER, 
    MENU,
    GAME,
    PAUSE,
    NEWGAME,
    WIN,
    LOSE,
    LOADGAME,
    SAVEGAME,
    SETTINGS,
    CREDITS,
    GREETIGS,
    THANKS,
    EXIT

} GameScreen;

typedef enum {
    sLOGO, 
    sMENU,
    sBLACK,
    sRAYLOGO,
    sCREDITS,
    sSAVE,
    sLOAD,
    sNEWGAME,
    sPAUSE,
    sSETTINGS,
    
} ScreenRes;

typedef enum {
    PLACES,
    CHARACTER,
    DEATHS
} CardType;


struct Box{
    int                 isRoom;
    char                status;         //f = free; - = blocked; p = player; d = doors; r = rooms, c = cafeteria
    Vector2             tilePosition;
};


struct BoardGame{
    Texture2D           mapBackground;
    Texture2D           map;
    Camera2D            camera;
    struct Box          boxes[24][24];
}; typedef struct BoardGame* Board;


struct Card_struct{
    char                uniqueInitial;
    char*               name;
    Texture2D           visual;
}; typedef struct Card_struct* Card;


struct Player_ref{
    int                 isLive; 
    int                 movingAnimate;  // frame to render
    int                 cards[3];       // Deck of cards
    int                 frame;          // Visible frame
    int                 maxFrames;      // Frames in the Texture
    int                 x;              // X Position in board
    int                 y;              // Y Position in board
    int                 movesLeft;      
    float               frameWidth;     // Width of the Colider
    float               frameHeight;    // Height of the Colider
    float               timer;          // Helper Timer for animation
    char*               c_player;       // Color of the character
    char*               name;           // Name of the player
    Card                cardsInHand;    // Cards of each player
    int                 numCards;       // Number of cards for each player
    struct Rectangle    frameRec;       // Rectangle Frame Colider
    struct Vector2      position;       // Position in the window
    Texture2D           skin[4];        // 0 = Stand Right || 1 = Stand Left || 2 = Walking Right || 3 = Walking Left  
    struct Player_ref*  next;           // Pointer To Create a CLL
}; typedef struct Player_ref* Player;


struct ImpostorGame{
    int                 screenWidth;
    int                 screenHeight;
    int                 screenCenterWidth;
    int                 screenCenterHeight;     
    int                 btnWidth;               // Width of the buttons
    int                 btnHeight;              // Height of the buttons
    int                 btnInitialPosition;     // Initial Position of Rows
    int                 btnRowDistance;         // Distance between Rows
    int                 btnCenter;              // Distance to put an element in center
    int                 fps;                   
    int                 playersAlive;
    int                 resolution;             // Resolution Id
    float               volume;                 // Master Volume
    int                 typeTBActive[6];        // Type Player Señectpr data
    bool                typeTBEditMode[6];      // Type Player Selector Blocker
    char                nameTB[6][30];          // Name of the crewmates
    bool                nameEditMode[6];        // Name input blocker
    char*               colorTB[6];             // Colors of the crewmates
    Board               board;                  // Information of the board
    Player              playerInTurn;           // Pointer List of players
    Texture2D           screens[10];            // Screens and backgrounds
    Card                envelope;               // Cards inside the envelope
};

struct Suggestion_struct{
    char                place; 
    /*
    A - Admin
    E - Electrical  
    F - Cafeteria
    H - Shields
    I - Lower Engine
    L - Storage
    R - Reactor
    U - Upper Engine
    V - Navigation
    X - Weapons
    Y - Medbay
    */
    char                character;
    /*
    C - Colonel Mustard
    G - Mr. Green
    M - Mrs. Peacock
    P - Professor Plum
    S - Miss Scarlet
    W - Mrs. White
    */
    char                death;
    /*
    B - Stabbing
    D - Disconected from Server
    J - Gun Shot
    N - Neck Snap
    O - Thrown into Space
    T - Throat Saber
    */
}; typedef struct Suggestion_struct* Suggestion;



struct GameHistory{
    
};

struct Notebook{
    
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