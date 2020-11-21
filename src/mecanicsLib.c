#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mecanicsLib.h"

//Este seria el Backend del juego, solamente 
//codigo funcional


void SaveGame(){
}
void LoadGame(){
}
void SetGame(){
}
void FillPackage(){
}
void Accusation(){
}
void Suggestion(){
}
void GenerateTurnList(){
}
void CalculateRandomMovements(){
}
void HatONames(){
}

/*

int main(void) {
    YourTurn first = NULL; 
  
    addChara(&first, 12); 
    addChara(&first, 56); 
    addChara(&first, 2); 
    addChara(&first, 11); 
  
    printList(first); 
    printf("\n");print(first);

    //printf("\n");printf("\n%d", peek(first));
    //printf("\n%d", poop(&first));
    //printf("\n");printList(first);
    //printf("\n%d", peek(first));

    printf("\n");printf("\n%d", move(&first));
    printf("\n%d", move(&first));
    printf("\n%d", move(&first));
    printf("\n%d", move(&first));
    printf("\n%d", move(&first));
    printf("\n%d", move(&first));

    printf("\n");printf("\n%d :3", peek(first));
    printf("\n");print(first);

    //printf("\t");printf("\n%d D,", pop(&first, peek(first)));
    //printf("\t");deleteNode(first, peek(first));
    printf("\t");printf("\n%d D,", poop(&first, peek(first)));

    printf("\n");print(first);

    return 0;
}
*/

//Skeleon

YourTurn newNode(int value, YourTurn *first){
    YourTurn chara = malloc(sizeof(YourTurn));
    chara->data = value;
    chara->next = *first;
    return chara;
}
  
void addChara(YourTurn *first, int data) { 
    YourTurn newC = newNode(data, first);
    YourTurn temp = *first;
  
    if (*first != NULL){ 
        while (temp->next != *first){
            temp = temp->next;}
        temp->next = newC;
    } 
    else{
        newC->next = newC;
    }
    *first = newC; 
} 
  
void printList(YourTurn first){
    YourTurn temp = first;
    if (first != NULL){
        do{
            printf("[%d]->", temp->data);
            temp = temp->next;
        } while(temp != first);
    }
}

void print(YourTurn first){
    for (int i = 0; i <= 8; i++){
        printf("[%d]->", first->data);
        first = first->next;
    }
}

int move(YourTurn *first){
    int val = 0;
    if((*first)->next != NULL)
        val = (*first)->data;
        *first = (*first)->next;
    return val;
}

int peek(YourTurn first){
    int val = 0;
    if(first->next != NULL)
        val = first->data;
    return val;
}

int poop(YourTurn *first, int key){
    YourTurn toDelete = *first;
    YourTurn prev = *first;
    int val = 0; 
    if(toDelete != NULL){
        char turn = toDelete->data;
        while (prev->next != *first){prev = prev->next;}
        *first = toDelete->next;
        prev->next = *first;
        free(toDelete);
        return turn;
    }
    return 0;
}

int pop(YourTurn *first, int key){
    YourTurn toDelete = *first;
    int val = 0; 
    if(toDelete != NULL){
        char dataToReturn = toDelete->data;
        *first = toDelete->next;
        free(toDelete);
        return dataToReturn;
    }
    return 0;
}

void deleteNode(YourTurn first, int key){
    YourTurn toDelete = first, prev;
    if (first == NULL)
        return;
    if (toDelete == first) {
        prev = first;
        while (prev->next != first)
            prev = prev->next;
        first = toDelete->next;
        prev->next = first;
        free(toDelete);
    }
}


//First-try of right

NextCharacterTurn makeNewCharacter(NextCharacterTurn *theCharacter, Player fullCharacter){
    NextCharacterTurn newCharacter = malloc(sizeof(NextCharacterTurn));
    newCharacter->character = fullCharacter;
    newCharacter->nextTurn = *theCharacter;
    return newCharacter;
}
  
void addCharacter(NextCharacterTurn *theCharacter, Player fullCharacter){ 
    NextCharacterTurn newCharacter = makeNewCharacter(theCharacter, fullCharacter);
    NextCharacterTurn temporalCharacter = *theCharacter;
  
    if (*theCharacter != NULL){ 
        while (temporalCharacter->nextTurn != *theCharacter){
            temporalCharacter = temporalCharacter->nextTurn;}
        temporalCharacter->nextTurn = newCharacter;
    } 
    else{
        newCharacter->nextTurn = newCharacter;
    }
    *theCharacter = newCharacter; 
} 
  
void printListC(NextCharacterTurn theCharacter){
    NextCharacterTurn temporalCharacter = theCharacter;
    if (theCharacter != NULL){
        do{
            printf("[%s]->", theCharacter->character->name);
            temporalCharacter = temporalCharacter->nextTurn;
        } while(temporalCharacter != theCharacter);
    }
}

void printC(NextCharacterTurn theCharacter){
    for (int i = 0; i <= 8; i++){
        printf("[%s]->", theCharacter->character->name);
        theCharacter = theCharacter->nextTurn;
    }
}

void moveAlongInTurns(NextCharacterTurn *theCharacter){
    char* nameOfChar;
    if((*theCharacter)->nextTurn != NULL)
        nameOfChar = (*theCharacter)->character->name;
        *theCharacter = (*theCharacter)->nextTurn;
}

void peekWhoSNext(NextCharacterTurn theCharacter){
    char* nameOfChar;
    if(theCharacter->nextTurn != NULL)
        nameOfChar = theCharacter->character->name;
}

void takeOutCharacter(NextCharacterTurn *theCharacter, Player fullCharacter){
    NextCharacterTurn charactertoDelete = *theCharacter;
    NextCharacterTurn prevCharacter = *theCharacter;
    char* nameOfChar; 
    if(charactertoDelete != NULL){
        nameOfChar = charactertoDelete->character->name;
        while (prevCharacter->nextTurn != *theCharacter){prevCharacter = prevCharacter->nextTurn;}
        *theCharacter = charactertoDelete->nextTurn;
        prevCharacter->nextTurn = *theCharacter;
        free(charactertoDelete);
    }
}

void popC(NextCharacterTurn *theCharacter, Player fullCharacter){
    NextCharacterTurn charactertoDelete = *theCharacter;
    char* nameOfChar; 
    if(charactertoDelete != NULL){
        nameOfChar = charactertoDelete->character->name;
        *theCharacter = charactertoDelete->nextTurn;
        free(charactertoDelete);
    }
}

void deleteNodeC(NextCharacterTurn theCharacter, Player fullCharacter){
    NextCharacterTurn toDelete = theCharacter, prev;
    if (theCharacter == NULL)
        return;
    if (toDelete == theCharacter) {
        prev = theCharacter;
        while (prev->nextTurn != theCharacter)
            prev = prev->nextTurn;
        theCharacter = toDelete->nextTurn;
        prev->nextTurn = theCharacter;
        free(toDelete);
    }
}
