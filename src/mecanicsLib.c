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

// Another litte abuse, another pointless excuse
    // ... another day feeling like i don't belong
    // ... a better day, happy that i won't belong
    // ... does anyone, belong?
    // ... so, I end a lonely day feeling totally okay

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
