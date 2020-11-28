#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "raylib.h"
#include "impostorLib.h"
#include "mecanicsLib.h"
#include "graphsLib.h"

//Aqui juntamos todo el codigo

void playImpostor(GameState game){
    initImpostor(game);
    Texture2D black = LoadTexture("./res/assets/map/Space.png");

    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(game->board->camera);
            DrawTexture(black, 0, 0, WHITE);
            DrawTexture(game->board->mapBackground, 0, 0, WHITE);
            MovementInBoard(game);

            EndMode2D();

        EndDrawing();
    }
    
}
void endImpostor(GameState game){
    free(game->board);
    free(game->playerInTurn);
    free(game);
    CloseWindow();
}
void initImpostor(GameState game){
    newPlayerList(game);
    game->board = NewBoard(game);
    SetPlayersInBoard(game);
    InitCamera(game);

}
GameState newImpostorGame(){
    GameState game = malloc(sizeof(struct ImpostorGame));
    //game->screenWidth = 1920;
    //game->screenHeight = 1080;
    game->screenWidth = 1280;
    game->screenHeight = 700;
    game->fps = 60;
    game->speed = 200.0f;
    game->screenCenterWidth = (int)game->screenWidth/2;
    game->screenCenterHeight = (int)game->screenHeight/2;
    game->gameScreen = LOGO;
    game->playersAlive = 0;
    //const int screenWidth = 1920, screenHeight = 1080; //monitor normal
    //const int screenWidth = 1366, screenHeight = 768; //monitor lap
    //const int screenWidth = 1024, screenHeight = 768; //monitor feo
    //const int screenWidth = 1280, screenHeight = 800; //monitor mac
    InitWindow(game->screenWidth,game->screenHeight, "raylib");
    SetTargetFPS(game->fps);
    return game;
}
Board NewBoard(GameState game){
    Board board = malloc(sizeof(struct BoardGame));
    board->mapBackground = LoadTexture("./res/assets/map/Sketch.png");
    float initialX = 1723.0f, intialY = 1699.0f;
    for(int x=0;x<24;x++){
        for(int y=0;y<24;y++){
            board->boxes[x][y].tilePosition = (Vector2){initialX+(x*86),intialY+(y*86)};
            board->boxes[x][y].status = '-';
            board->boxes[x][y].isRoom = 0;
        }
    }
    for(int x=0;x<24;x++){
        for(int y=0;y<24;y++){
            // This is where the character can either be told to 
                // walk: which is marked with an 'f'
                // teleport inside a room: which is marked with a 'd'
                // or be in a room: which is marked with an 'r'
            if(x == 0 || x == 23){
                if(y >= 3 && y <= 20)
                    board->boxes[y][x].status = 'f';
                if(y == 0 || y == 23)
                    board->boxes[y][x].status = 'r';
                if(y == 2 || y == 21)
                    board->boxes[y][x].status = 'd';}
            if(x == 1 || x == 22)
                if(y >= 3 && y <= 20)
                    board->boxes[y][x].status = 'f';
            if(x == 11 || x == 12)
                if((y >= 2 && y <= 8) || (y >= 15 && y <= 21))
                    board->boxes[y][x].status = 'f';
            if(y == 0 || y == 1 || y == 22 || y == 23)
                if((x >= 3 && x <= 9) || (x >= 14 && x <= 20))
                    board->boxes[y][x].status = 'f';
            if(y == 11 || y == 12)
                if((x >= 2 && x <= 8) || (x >= 15 && x <= 21))
                    board->boxes[y][x].status = 'f';
            if(y == 2 || y == 21)
                if(x == 3 || x == 9 || x == 10 || x == 13 || x == 14 || x == 20)
                    board->boxes[y][x].status = 'f';
            if(y == 3 || y == 20)
                if(x == 2 || x == 3 || x == 20 || x == 21)
                    board->boxes[y][x].status = 'f';
            if(y == 6 || y == 17){
                if((x >= 2 && x <= 4) || (x >= 8 && x <= 15))
                    board->boxes[y][x].status = 'f';
                if(x == 6 || x == 17)
                    board->boxes[y][x].status = 'r';
                if(x == 5 || x == 7 || x == 16)
                    board->boxes[y][x].status = 'd';}
            if(x == 8 || x == 15 || x == 17)
                if(y >= 8 && y <= 15)
                    board->boxes[y][x].status = 'f';
            if(y == 8 || y == 15)
                if(x >= 8 && x <= 15)
                    board->boxes[y][x].status = 'f';
            if(x == 12)
                if(y == 0 || y == 23 || y == 12)
                    board->boxes[y][x].status = 'r';
            if(x == 2 || x == 10 || x == 13 || x == 21)
                if(y == 0 || y == 23)
                    board->boxes[y][x].status = 'd';
            if(x == 17)
                if(y == 7 || y == 16)
                    board->boxes[y][x].status = 'd';
            if(x == 9 || x == 14)
                if(y == 11 || y == 12)
                    board->boxes[y][x].status = 'd';
            if(y == 9 || y == 14)
                if(x == 11 || x == 12)
                    board->boxes[y][x].status = 'd';
        }
    }
    board->boxes[1][0].status = 'f'; //erase later
    board->boxes[2][0].status = 'f'; //erase later
    for(int x=0;x<24;x++){
        for(int y=0;y<24;y++){
            fprintf(stdout, "[%c] ",board->boxes[y][x].status);
        }
        fprintf(stdout, "\n");
    }
    
    return board;
}
Player newPlayer(GameState game,char color[10]){
    Player player = malloc(sizeof(struct Player_ref));
    char urlPath[100] = "./res/assets/crewmates/"; 
    strcat(urlPath,color);
    char auxUrlPath[100];
    strcpy(auxUrlPath,urlPath);
    strcat(urlPath,"/sright.png");
    player->skin[0] = LoadTexture(urlPath);
    strcpy(urlPath,auxUrlPath);
    strcat(urlPath,"/sleft.png");
    player->skin[1] = LoadTexture(urlPath);
    strcpy(urlPath,auxUrlPath);
    strcat(urlPath,"/right.png");
    player->skin[2] = LoadTexture(urlPath);
    strcpy(urlPath,auxUrlPath);
    strcat(urlPath,"/left.png");
    player->skin[3] = LoadTexture(urlPath);
    player->c_player = color;
    player->movingAnimate = 0;
    player->frameWidth = 86;
    player->frameHeight = 105;
    player->maxFrames = 1;
    player->timer = 0.0f;
    player->frame = 0;
    player->frameRec.x = 0;
    player->frameRec.y = 0;
    player->frameRec.width = player->frameWidth; 
    player->frameRec.height = player->frameHeight;
    player->position.x = 1723;//game->screenCenterWidth;
    player->position.y = 1699;//game->screenCenterHeight;    
    return player;
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
    // Aqui debe haber una funcion con los datos de los personajes escogidos
    char colorsArray[6][10] = {
        "Blue",
        "Green",
        "Purple",
        "Red",
        "White",
        "Yellow"
    };
    for(int i = 0;i<6;i++){
        addPlayerToList(game,newPlayer(game,colorsArray[i]));
        game->playersAlive++;
    }
}