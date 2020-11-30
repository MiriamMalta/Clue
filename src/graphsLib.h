#ifndef _GRAPHS_GUARD_H
#define _GRAPHS_GUARD_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "impostorLib.h"
#include "mechanicsLib.h"

void Movement(GameState game);
void MovementInBoard(GameState game);
void SelectAnimation(GameState game, int Selection, int isStill);
void UpdateAnimation(GameState game);
void UpdateCameraPosition(GameState game);
void InitCamera(GameState game);
void SetPlayersInBoard(GameState game);

void Teletransport();
void EnterRoom();
void ExitRoom();

#endif