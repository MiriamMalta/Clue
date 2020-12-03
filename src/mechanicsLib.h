#ifndef _MECHANICS_GUARD_H
#define _MECHANICS_GUARD_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "raylib.h"
#include "impostorLib.h"

void SaveGame();
void LoadGame();
void SetGame();
void FillPackage();
void Accusation();
void Suggestion();
void GenerateTurnList();
int CalculateRandomMovements();
int CalculateRandomPlacements();
void NextTurn(GameState game);
void HatONames();

void addCharacter(GameState game, Player fullCharacter);
char* moveAlongInTurns(GameState game);
char* peekWhoSNext(GameState game);
void takeOutCharacter(GameState game, Player fullCharacter);

void MakeSuggestion(GameState game, char* suggestion);

Card newCard(GameState game,char initial, char* name);
void makeCards(GameState game, Card deckPlaces, Card deckCharacters, Card deckDeaths);
void takeOutCard(Card Deck, int position, int elements);
void pushToAll(Card All, Card Places, Card Characters, Card Deaths);
void shuffleCards(Card All, Card Shuffle);
void dealCards(GameState game, Card Shuffle);
void initializeCards (GameState game);

void printPlayersAndCards(GameState game);

#endif