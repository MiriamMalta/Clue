#ifndef _IMPOSTOR_GUARD_H
#define _IMPOSTOR_GUARD_H

struct ImpostorGame{
    
};

struct GameHistory{
    
};

struct Board{
    
};

struct Player{
    
};

struct Notebook{
    
};

struct Accusations{

};

typedef struct ImpostorGame* GameState, GameInitialState;

GameState newImpostorGame();
void initImpostor();
void playImpostor();
void endImpostor();

#endif