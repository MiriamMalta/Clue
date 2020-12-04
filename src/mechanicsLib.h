#ifndef     _MECHANICS_GUARD_H
#define     _MECHANICS_GUARD_H
#include    <stdio.h>
#include    <stdlib.h>
#include    <math.h>
#include    <time.h>
#include    <string.h>
#include    "raylib.h"
#include    "impostorLib.h"

void    LoadSettings(GameState game);
void    SaveSettings(GameState);
void    d_Settings(GameState,int[2]);
int*    s_Settings(GameState);
void    SaveGame(GameState);
void    LoadGame(GameState);
void    d_Game(GameState game);
void    s_Game(GameState game);
int     makeAccusation(GameState game, Card cards[3]);
void    makeSuggestion(GameState game, Card cards[3]);
void    GenerateTurnList();
void    SetGame();
void    FillPackage();
void    HatONames();

int     CalculateRandomMovements();
int     CalculateRandomPlacements();
void    NextTurn(GameState game);
void    throwDice(GameState game);

void    addPlayerToList(GameState game,Player player);
void    newPlayerList(GameState game);

char*   moveAlongInTurns(GameState game);
char*   peekWhoSNext(GameState game);
void    takeOutCharacter(GameState game, Player fullCharacter);

void    MakeSuggestion(GameState game, char* suggestion);

Card    newCard(GameState game,int initial, char* name,char* imgName);
void    makeCards(GameState game, Card deckPlaces, Card deckCharacters, Card deckDeaths);
void    takeOutCard(Card Deck, int position, int elements);
void    pushToAll(Card All, Card Places, Card Characters, Card Deaths);
void    shuffleCards(Card All, Card Shuffle);
void    dealCards(GameState game, Card Shuffle);
void    initializeCards (GameState game);

char     whatPlace(GameState game);
//void   printCardsIGot(GameState game);

#endif