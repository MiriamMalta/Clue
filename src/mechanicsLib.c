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
int makeAccusation(GameState game,Card cards[3]){   
    if(game->envelope[PLACES].uniqueInitial == cards[PLACES]->uniqueInitial && 
        game->envelope[CHARACTER].uniqueInitial == cards[CHARACTER]->uniqueInitial && 
        game->envelope[DEATHS].uniqueInitial == cards[DEATHS]->uniqueInitial){
            return true;
        }
    return false;
}
// THIS
void makeSuggestion(){
}
void GenerateTurnList(){
}
void HatONames(){
}


// This is the Dice of 6 sides
int CalculateRandomMovements(){
    return (rand()%9) + 1;
}
void NextTurn(GameState game){
    game->playerInTurn = game->playerInTurn->next;
}
// This is
int CalculateRandomPlacements(){
    return (rand()%8) + 8;
}

void addPlayerToList(GameState game,Player player){
    Player temp = game->playerInTurn;
    if(game->playerInTurn == NULL){
        game->playerInTurn = player;
        game->playerInTurn->next = player;
    }else{
        while(temp->next != game->playerInTurn){
            temp = temp->next;
        }
        temp->next = player;
        player->next = game->playerInTurn;
    }
}
void newPlayerList(GameState game){
    game->playerInTurn = NULL;
    for(int i = 0;i<6;i++){
        if(game->typeTBActive[i] == 0){
            addPlayerToList(game,newPlayer(game,game->colorTB[i]));
            game->playersAlive++;
        }
    }
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

Card newCard(GameState game,char initial, char* name){
    Card cardOne = calloc(1, sizeof(struct Card_struct));
    //char urlPath[100] = "./res/assets/cards/"; 
    //strcat(urlPath,initial);
    //strcat(urlPath,".jpg");
    //cardOne->visual = LoadTexture(urlPath);
    cardOne->uniqueInitial = initial;
    cardOne->name = name;
    return cardOne;
}

void makeCards(GameState game, Card deckPlaces, Card deckCharacters, Card deckDeaths){
    char Places1[] = {'A','E','F','H','I','L','R','U','V','X','Y'};
    char* Places2[] = {
        "Admin","Electrical","Cafeteria","Shields","Lower Engine","Storage",
        "Reactor","Upper Engine","Navigation","Weapons","Medbay"
    };
    for(int i = 0; i <= 11; i++){
        deckPlaces[i] = *(newCard(game, Places1[i], Places2[i]));
    }

    char Characters1[] = {'C','G','M','P','S','W'};
    char* Characters2[] = {
        "Colonel Mustard","Mr. Green","Mrs. Peacock",
        "Professor Plum","Miss Scarlet","Mrs. White"
    };
    for(int i = 0; i <= 6; i++){
        deckCharacters[i] = *(newCard(game, Characters1[i], Characters2[i]));
    }

    char Deaths1[] = {'B','D','J','N','O','T'};
    char* Deaths2[] = {
        "Stabbing","Disconnected from Server","Gun Shot",
        "Neck Snap","Thrown into Space","Throat Saber"
    };
    for(int i = 0; i <= 6; i++){
        deckDeaths[i] = *(newCard(game, Deaths1[i], Deaths2[i]));
    }
}

void takeOutCard(Card Deck, int position, int elements){
    for(int i = position; i < elements; i++){
        Deck[i] = Deck[i + 1];
    }
}

void pushToAll(Card All, Card Places, Card Characters, Card Deaths){
    for(int i = 0; i < 10; i++){All[i] = Places[i];}
    for(int i = 0; i < 5; i++){All[i+10] = Characters[i];}
    for(int i = 0; i < 5; i++){All[i+15] = Deaths[i];}
}

void shuffleCards(Card All, Card Shuffle){
    for(int i = 0 ; i < 20; i++){
        int addIndex = rand() % 20;
        while(All[addIndex % 20].uniqueInitial == 0){addIndex++;}
        Shuffle[i] = All[addIndex % 20];
        All[addIndex % 20].uniqueInitial = 0;
    }
}

void dealCards(GameState game, Card Shuffle){

    int howManyCards = 20/(game->playersAlive);
    int totalNumberOfCards = 20;

    for(int j = 0; j < game->playersAlive; j++){
        game->playerInTurn->cardsInHand = calloc(20, sizeof(struct Card_struct));
        if ((totalNumberOfCards/howManyCards >= howManyCards)||(totalNumberOfCards/howManyCards == 1)){
            for(int i = 0; i < howManyCards; i++){
                game->playerInTurn->cardsInHand[i] = Shuffle[i];
            }
        }
        else{
            if(game->playersAlive == 6){howManyCards++;}
            if (game->playersAlive == 3 && totalNumberOfCards < 20){howManyCards++;}
            for(int i = 0; i < howManyCards; i++){
                game->playerInTurn->cardsInHand[i] = Shuffle[i];
            }
        }
        for(int j = 0; j < 20 - howManyCards; j++){
            Shuffle[j] = Shuffle[j + howManyCards];
        }
        game->playerInTurn->numCards = howManyCards;
        totalNumberOfCards = totalNumberOfCards - howManyCards;
        game->playerInTurn = game->playerInTurn->next;
    }
}

void initializeCards (GameState game){
    Card deckPlaces = calloc(11, sizeof(struct Card_struct));
    Card deckCharacters = calloc(6, sizeof(struct Card_struct));
    Card deckDeaths = calloc(6, sizeof(struct Card_struct));
    Card AllCards = calloc(20, sizeof(struct Card_struct));
    Card ShuffledCards = calloc(20, sizeof(struct Card_struct));

    makeCards(game, deckPlaces, deckCharacters, deckDeaths);

    int randomPlaces = rand()%11; int randomCharacters = rand()%6; int randomDeaths = rand()%6;

    game->envelope[0] = deckPlaces[randomPlaces];
    game->envelope[1] = deckCharacters[randomCharacters];
    game->envelope[2] = deckDeaths[randomDeaths];

    fprintf(stdout, "%c - %c - %c\n", game->envelope[0].uniqueInitial, game->envelope[1].uniqueInitial, game->envelope[2].uniqueInitial);

    takeOutCard(deckPlaces, randomPlaces, 11);
    takeOutCard(deckCharacters, randomCharacters, 6);
    takeOutCard(deckDeaths, randomDeaths, 6);

    pushToAll(AllCards, deckPlaces, deckCharacters, deckDeaths);
    shuffleCards(AllCards, ShuffledCards);
    dealCards(game, ShuffledCards);

    //free(deckPlaces);
    //free(deckCharacters);
    //free(deckDeaths);
    //free(AllCards);
    //free(ShuffledCards);
}

/*
void printPlayersAndCards(GameState game){
    fprintf(stdout, "\n");
    for(int j = 0; j < game->playersAlive; j++){
        //char* color = game->playerInTurn->c_player;
        //fprintf(stdout, "%s -> ", game->playerInTurn->c_player);
        for(int i = 0; i < game->playerInTurn->numCards; i++){
            fprintf(stdout, "[%c]", game->playerInTurn->cardsInHand[i].uniqueInitial);
        }
        fprintf(stdout, " {%d}\n", game->playerInTurn->numCards);
        game->playerInTurn = game->playerInTurn->next;
    }
}
*/