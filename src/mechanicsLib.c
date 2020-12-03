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
    return (rand()%9) + 1;
}
void NextTurn(GameState game){
    game->playerInTurn = game->playerInTurn->next;
}
// This is
int CalculateRandomPlacements(GameState game){
    char* nameOfChar = game->playerInTurn->c_player;
    //fprintf(stdout, "%c\n", nameOfChar[0]);
    //if (nameOfChar[0] == 'B'){fprintf(stdout, "BLUE");}
    //if (nameOfChar[0] == 'G'){fprintf(stdout, "GREEN");}
    return (rand()%8) + 8;
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


void InitializeCards (GameState game){
    //A: Admin, E: Electrical, F: Cafeteria, H: Shields, I: Lower Engine, L: Storage
    //R: Reactor, U: Upper Engine, V: Navigation, X: Weapons, Y: Medbay
    char deckPlaces[] = {'A','E','F','H','I','L','R','U','V','X','Y'};
    //C: Colonel Mustard, G: Mr. Green, M: Mrs. Peacock, P: Professor Plum, S: Miss Scarlet, W: Mrs. White
    char deckCharacters[] = {'C','G','M','P','S','W'};
    //B: Stabbing, D: Disconected from Server, J: Gun Shot, N: Neck Snap, O: Thrown into Space, T: Throat Saber
    char deckDeaths[] = {'B','D','J','N','O','T'};

    int randomPlaces = rand()%11;
    int randomCharacters = rand()%6;
    int randomDeaths = rand()%6;

    game->envelope[0] = deckPlaces[randomPlaces];
    game->envelope[1] = deckCharacters[randomCharacters];
    game->envelope[2] = deckDeaths[randomDeaths];

    fprintf(stdout, "%c - %c - %c\n", game->envelope[0], game->envelope[1], game->envelope[2]);

    for(int i = randomPlaces; i < 11; i++){deckPlaces[i] = deckPlaces[i + 1];}
    for(int i = randomCharacters; i < 6; i++){deckCharacters[i] = deckCharacters[i + 1];}
    for(int i = randomDeaths; i < 6; i++){deckDeaths[i] = deckDeaths[i + 1];}

    char* AllCards = calloc(20, sizeof(char)); 
    for(int i = 0; i < 10; i++){AllCards[i] = deckPlaces[i];}
    for(int i = 0; i < 5; i++){AllCards[i+10] = deckCharacters[i];}
    for(int i = 0; i < 5; i++){AllCards[i+15] = deckDeaths[i];}

    char* ShuffledCards = calloc(20, sizeof(char));
    for(int i = 0 ; i < 20; i++){
        int Index = rand() % 20;
        while(AllCards[Index % 20] == 0)
        Index++;
        ShuffledCards[i] = AllCards[Index % 20];
        AllCards[Index % 20] = 0;
    }

    int howManyCards = 20/(game->playersAlive);
    int totalNumberOfCards = 20;

    for(int j = 0; j < game->playersAlive; j++){
        fprintf(stdout, "\n");
        game->playerInTurn->cardsInHand = calloc(20, sizeof(char));
        if ((totalNumberOfCards/howManyCards >= howManyCards)||(totalNumberOfCards/howManyCards == 1)){
            for(int i = 0; i < howManyCards; i++){
                game->playerInTurn->cardsInHand[i] = ShuffledCards[i];
            }
        }
        else{
            if(game->playersAlive == 6){howManyCards++;}
            if (game->playersAlive == 3 && totalNumberOfCards < 20){howManyCards++;}
            for(int i = 0; i < howManyCards; i++){
                game->playerInTurn->cardsInHand[i] = ShuffledCards[i];
            }
        }
        for(int j = 0; j < 20 - howManyCards; j++){
            ShuffledCards[j] = ShuffledCards[j + howManyCards];
        }
        for(int i = 0; i < howManyCards; i++){
            fprintf(stdout, "[%c]", game->playerInTurn->cardsInHand[i]);
        }
        totalNumberOfCards = totalNumberOfCards - howManyCards;
        game->playerInTurn = game->playerInTurn->next;
    }
}

void MakeSuggestion(GameState game, char* suggestion){
    
}