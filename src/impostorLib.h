#ifndef _IMPOSTOR_GUARD_H
#define _IMPOSTOR_GUARD_H

struct ImpostorGame{
    int screenWidth;
    int screenHeight;
    int screenCenterWidth;
    int screenCenterHeight;
};

struct Player{
    int             isLive; 
    int             isMoveing;  
    int             cards[3];   // Deck of cards
    int             frame;      // Visible frame
    int             maxFrames;  // Frames in the Texture
    float           frameWidth; // Width of the Colider
    float           frameHeight;// Height of the Colider
    float           timer;      // Helper Timer for animation
    char*           c_player;   // Color of the character
    char*           name;       // Name of the player
    Rectangle frameRec;   // Rectangle Frame Colider
    Vector2   position;   // Position in the map
    Texture2D sleft;      // Stand Texture Left
    Texture2D sright;     // Stand Texture Right
    Texture2D left;       // Movement Texture Left
    Texture2D right;      // Movement Texture Right
    Player*  next;       // Pointer To Create a CLL
};
typedef struct Player* Player_ref;


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
void playImpostor(GameState game);
void endImpostor();
void initImpostor();

#endif