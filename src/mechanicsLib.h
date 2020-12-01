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
int CalculateRandomPlacements(GameState game);
void HatONames();

void addCharacter(GameState game, Player fullCharacter);
char* moveAlongInTurns(GameState game);
char* peekWhoSNext(GameState game);
void takeOutCharacter(GameState game, Player fullCharacter);

void InitializeCards (GameState game);
void MakeSuggestion(GameState game, char* suggestion);

#endif