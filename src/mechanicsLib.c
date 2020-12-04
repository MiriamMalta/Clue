#include "mechanicsLib.h"
#include "impostorLib.h"


// Save Settings in the settings panel
void SaveSettings(GameState game){
    int* data;
    data = s_Settings(game);
    FILE *pSett;
    if((pSett = fopen("./data/settings.bin","wb+"))== NULL){
        fprintf(stdout,"ERROR: APERTURA DE ARCHIVO SETTINGS SAVE.\n");
        exit(1); 
    }
    fwrite(data,sizeof(int),2,pSett);
    rewind(pSett);
    fclose(pSett);
}

// Load Settings at the begin.
void LoadSettings(GameState game){
    int data[2];
    long size;
    FILE *pSett;
    if((pSett = fopen("./data/settings.bin","rb"))== NULL){
        fprintf(stdout,"ERROR: APERTURA DE ARCHIVO SETTINGS LOAD.\n");
        game->resolution = 1;
        game->volume = 60;        
    }

    if (NULL != pSett) {
        fseek (pSett, 0, SEEK_END);
        size = ftell(pSett);
        rewind(pSett);
        if (0 == size) {
            game->resolution = 1;
            game->volume = 60;   
        }else{
            fread(data,sizeof(int),2,pSett);
            rewind(pSett);
            fclose(pSett);
            d_Settings(game,data);

        }
    }
}

// Settings Serializer
int* s_Settings(GameState game){
    int* settings = malloc(sizeof(int)*2);
    settings[0] = (int)game->resolution;
    settings[1] = (int)game->volume;
    return settings;
}

// Settings DeSerializer
void d_Settings(GameState game,int data[2]){
    game->resolution = data[0];
    game->volume = (float)data[1];
}

// Save Game Option
void SaveGame(GameState game){

}

// Load Game Option
void LoadGame(GameState game){

}

// Game information Serializer
void s_Game(GameState game){

}

// Game information DeSerializer
void d_Game(GameState game){

}

/**
 * Function to create accusation.
 * An accusation is the ultimate suggestion.
 * If you miss the cards. You die.
 */
int makeAccusation(GameState game, Card cards[3]){   
    if(game->envelope[PLACES].id == cards[PLACES]->id && 
        game->envelope[CHARACTER].id == cards[CHARACTER]->id && 
        game->envelope[DEATHS].id == cards[DEATHS]->id){
            return true;
        }
    return false;
}

/**
 * Function to create Suggestion.
 * A Suggestion is an open question, if anybody has
 * a named card the have to show it to the suggester.
 */
void makeSuggestion(GameState game, Card cards[3]){ 
    Player current = game->playerInTurn->next;
    int place = cards[PLACES]->id;
    int character = cards[CHARACTER]->id;
    int death = cards[DEATHS]->id;
    if (game->playersAlive != 0){ 
        for (int j = 0; j < game->playersAlive - 1; j++){
            for(int k = 0; k = current->numCards; k++){
                if(current->cardsInHand[k].id == place || current->cardsInHand[k].id == character || current->cardsInHand[k].id == death){
                    fprintf(stdout, "{{%c}}", current->cardsInHand[k]);
                }
            }
            current = current->next;
        }
    }
}

// Dice Random Function
int CalculateRandomMovements(){
    return (rand()%9) + 1;
}

// Next Turn Function
void NextTurn(GameState game){
    if(game->playerInTurn->movesLeft == 1){
        game->playerInTurn->movesLeft = 0;
        game->playerInTurn = game->playerInTurn->next;
    }
}
/**
 * Function to calculate the initial positions of the 
 * crewmates
 */
int CalculateRandomPlacements(){
    return (rand()%8) + 8;
}
void throwDice(GameState game){
    game->playerInTurn->movesLeft = CalculateRandomMovements()+1;  
    fprintf(stdout, "%d\n", (game->playerInTurn->movesLeft)-1); //Left here for now to know what number we got on the dice

}


/**
 * Function to add players to a Circular Linked List
 */
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

/**
 * Function to add all the actual players to the list
 */
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


Card newCard(GameState game,int initial, char* name, char* imgName){
    Card cardOne = calloc(1, sizeof(struct Card_struct));
    char urlPath[100] = "./res/assets/cards/"; 
    strcat(urlPath,imgName);
    strcat(urlPath,".png");
    cardOne->visual = LoadTexture(urlPath);
    cardOne->id = initial;
    cardOne->name = name;
    return cardOne;
}
void makeCards(GameState game, Card deckPlaces, Card deckCharacters, Card deckDeaths){
    int Places1[] = {1,2,3,4,5,6,7,8,9,10,11};
    char* Places2[] = {
        "Admin","Electrical","Cafeteria","Shields","Lower Engine","Storage",
        "Reactor","Upper Engine","Navigation","Weapons","Medbay"
    };
    char* Places3[] = {
        "p_Admin","p_Electrical","p_Cafeteria","p_Shields","p_LEngine","p_Storage",
        "p_Reactor","p_UEngine","p_Navigation","p_Weapons","p_Medbay"
    };
    
    int Characters1[] = {12,13,14,15,16,17};
    char* Characters2[] = {
        "Colonel Mustard","Mr. Green","Mrs. Peacock",
        "Professor Plum","Miss Scarlet","Mrs. White"
    };
    char* Characters3[] = {
        "c_Yellow","c_Green","c_Blue",
        "c_Purple","c_Red","c_White"
    };
    int Deaths1[] = {18,19,20,21,22,23};
    char* Deaths2[] = {
        "Stabbing","Disconnected from Server","Gun Shot",
        "Neck Snap","Thrown into Space","Throat Saber"
    };
    char* Deaths3[] = {
        "d_Stabbing","d_Disconnected","d_GunShot",
        "d_NeckSnap","d_Funado","d_ThroatSaber"
    };

    
    for(int i = 0; i <= 11; i++){
        deckPlaces[i] = *(newCard(game, Places1[i], Places2[i],Places3[i]));
    }

    for(int i = 0; i <= 6; i++){
        deckCharacters[i] = *(newCard(game, Characters1[i], Characters2[i],Characters3[i]));
    }

    for(int i = 0; i <= 6; i++){
        deckDeaths[i] = *(newCard(game, Deaths1[i], Deaths2[i], Deaths3[i]));
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
        while(All[addIndex % 20].id == 0){addIndex++;}
        Shuffle[i] = All[addIndex % 20];
        All[addIndex % 20].id = 0;
    }
}
void dealCards(GameState game, Card Shuffle){
    if (game->playersAlive != 0){
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

    fprintf(stdout, "%c - %c - %c\n", game->envelope[0].id, game->envelope[1].id, game->envelope[2].id);

    takeOutCard(deckPlaces, randomPlaces, 11);
    takeOutCard(deckCharacters, randomCharacters, 6);
    takeOutCard(deckDeaths, randomDeaths, 6);

    pushToAll(AllCards, deckPlaces, deckCharacters, deckDeaths);
    shuffleCards(AllCards, ShuffledCards);
    dealCards(game, ShuffledCards);

}

char whatPlace(GameState game){
    if (game->playerInTurn->x == 0 && game->playerInTurn->y == 0) return 'U'; // UPPER ENGINE
    if (game->playerInTurn->x == 23 && game->playerInTurn->y == 0) return 'X'; // WEAPONS
    if (game->playerInTurn->x == 0 && game->playerInTurn->y == 23) return 'I'; // LOWER ENGINE
    if (game->playerInTurn->x == 23 && game->playerInTurn->y == 23) return 'H'; // SHIELDS
    if (game->playerInTurn->x == 0 && game->playerInTurn->y == 12) return 'R'; // REACTOR
    if (game->playerInTurn->x == 23 && game->playerInTurn->y == 12) return 'V'; // NAVIGATION
    if (game->playerInTurn->x == 6 && game->playerInTurn->y == 6) return 'Y'; // MED-BAY
    if (game->playerInTurn->x == 17 && game->playerInTurn->y == 6) return 'L'; // STORAGE
    if (game->playerInTurn->x == 5 && game->playerInTurn->y == 18) return 'A'; // ADMIN
    if (game->playerInTurn->x == 18 && game->playerInTurn->y == 18) return 'E'; // ELECTRICAL
}
/*
void printCardsIGot(GameState game){
    int place = whatPlace(game);
    Card sugg[3]; sugg[PLACES]->id = place; sugg[CHARACTER]->id = 'C'; sugg[DEATHS]->id = 'B';
    fprintf(stdout, "%c %c %c", sugg[PLACES]->id, sugg[CHARACTER]->id, sugg[DEATHS]->id);
}
*/