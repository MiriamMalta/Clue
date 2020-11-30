#include "mechanicsLib.h"
#include "impostorLib.h"

//Este seria el Backend del juego, solamente 
//codigo funcional

void SaveGame(){
}
void LoadGame(){
}
void SetGame(){
}
void FillPackage(){
    // package
    // add TO ImpostorGame
}
// THIS
void Accusation(){
}
// THIS
void Suggestion(){
}
void GenerateTurnList(){
}
// This is the Dice of 6 sides
int CalculateRandomMovements(){
    return (rand()%6) + 1;
}
void HatONames(){
}

void addCharacter(GameState game, Player fullCharacter){
    Player temp = game->playerInTurn;
    if(game->playerInTurn != NULL){
        while(temp->next != game->playerInTurn){
            temp = temp->next;
        }
        temp->next = fullCharacter;
    }else{
        fullCharacter->next = fullCharacter;
    }
    game->playerInTurn = fullCharacter->next;
}

char* moveAlongInTurns(GameState game){
    char* nameOfChar = NULL;
    if(game->playerInTurn->next != NULL){
        //nameOfChar = game->playerInTurn->name;
        nameOfChar = game->playerInTurn->c_player;
        game->playerInTurn = game->playerInTurn->next;
    }
    return nameOfChar;
}

char* peekWhoSNext(GameState game){
    char* nameOfChar = NULL;
    if(game->playerInTurn->next != NULL){
        //nameOfChar = game->playerInTurn->name;
        nameOfChar = game->playerInTurn->c_player;
    }
    return nameOfChar;
}

void takeOutCharacter(GameState game, Player fullCharacter){
    Player charactertoDelete = game->playerInTurn;
    Player prevCharacter = game->playerInTurn;
    if(charactertoDelete != NULL){
        while (prevCharacter->next != game->playerInTurn){
            prevCharacter = prevCharacter->next;
        }
        game->playerInTurn = charactertoDelete->next;
        prevCharacter->next = game->playerInTurn;
        free(charactertoDelete);
    }
}
