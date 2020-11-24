#ifndef _MECANICS_GUARD_H
#define _MECANICS_GUARD_H
#include <stdio.h>
#include <stdlib.h>
#include "impostorLib.h"

void SaveGame();
void LoadGame();
void SetGame();
void FillPackage();
void Accusation();
void Suggestion();
void GenerateTurnList();
void CalculateRandomMovements();
void HatONames();

/*
// Skeleton

struct Node { 
    int data; 
    struct Node *next; 
}; typedef struct Node* YourTurn;

YourTurn newNode(int value, YourTurn *first);

void addChara(YourTurn *first, int data);

void printList(YourTurn first);
void print(YourTurn first);

int move(YourTurn *first);
int peek(YourTurn first);

int pop(YourTurn *first, int key);
void deleteNode(YourTurn first, int key);
int poop(YourTurn *first, int key);


// First-try of right

struct NodeCharacter { 
    Player character; 
    struct NodeCharacter *nextTurn;
}; typedef struct NodeCharacter* NextCharacterTurn;

NextCharacterTurn makeNewCharacter(NextCharacterTurn *theCharacter, Player fullCharacter);

void addCharacter(NextCharacterTurn *theCharacter, Player fullCharacter);

void printListC(NextCharacterTurn theCharacter);
void printC(NextCharacterTurn theCharacter);

void moveAlongInTurns(NextCharacterTurn *theCharacter);
void peekWhoSNext(NextCharacterTurn theCharacter);

void popC(NextCharacterTurn *theCharacter, Player fullCharacter);
void deleteNodeC(NextCharacterTurn theCharacter, Player fullCharacter);

void takeOutCharacter(NextCharacterTurn *theCharacter, Player fullCharacter);


// First traduction try

void addCharacter(GameState game, Player fullCharacter);

Player moveAlongInTurns(GameState game);

Player peekWhoSNext(GameState game);

void takeOutCharacter(GameState game, Player fullCharacter);

*/
#endif