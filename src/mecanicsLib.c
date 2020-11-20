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

// Skeleton (spooky scary skeletons)
    // ... send shivers down your spine

/*
#include <stdio.h>
#include "TurnList.h"

int main(void) {
    YourTurn first = NULL; 
  
    addChara(&first, 12); 
    addChara(&first, 56); 
    addChara(&first, 2); 
    addChara(&first, 11); 
  
    printf("Contents of Circular Linked List:\n"); 
    printList(first); 

    printf("\n");print(first);

    printf("\n");printf("\n%d :3", peek(first));
    //printf("\n%d D,", poop(&first));
    printf("\n");printList(first);
    printf("\n%d :3", peek(first));

    printf("\n");printf("\n%d :P", move(&first));
    printf("\n%d :P", move(&first));
    printf("\n%d :P", move(&first));
    printf("\n%d :P", move(&first));
    printf("\n%d :P", move(&first));
    printf("\n%d :P", move(&first));

    return 0;
}
*/

YourTurn newNode(int value, YourTurn *first){
    YourTurn chara = malloc(sizeof(YourTurn));
    chara->data = value;
    chara->next = *first;
    return chara;
}
  
/* Function to insert a node at the beginning of a Circular 
   linked list */
void addChara(YourTurn *first, int data) { 
    YourTurn newC = newNode(data, first);
    YourTurn temp = *first;
  
    /* If list is not NULL then set the next of last node */
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
  
/* Function to print nodes in a given Circular linked list */
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