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
    GameScreen  gameScene = LOGO;
    int         state = 0;
    int         splashCounter = 0;
    int         transCounter = 0; 
    float       alpha = 0.0f;
    Texture2D logo = LoadTexture("./res/animations/Logo2.png");
    Texture2D black = LoadTexture("./res/animations/black.png");
    initImpostor(game);
    
    while (!WindowShouldClose()){
        // Calculos de transiciones
        splashCounter +=4;
        transCounter ++;
        switch (gameScene){
            case LOGO:
                if(state == 0) {
                    if(alpha<1.0)alpha += 0.05;
                    else state = 1;
                }
                else if (state == 1){
                    alpha = 1.0;
                    if(transCounter % 350==0) state = 2;
                }
                else if (state == 2){
                    if(alpha>0.0)alpha -= 0.05;
                    else{
                        gameScene = GAME;
                        state = 0;
                    }
                }
                break;
            case POWERED:
                break;
            case DISCLAIMER:
                break;
            case MENU:
                break;
            case GAME:
                
                break;
            case NEWGAME:
                break;

            case LOADGAME:
                break;

            case SETTINGS:
                break;

            case CREDITS:
                break;

            case GREETIGS:
                break;

            case EXIT:
                break;
            default:
                break;
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            switch (gameScene){
                case LOGO:
                    switch(state)   {
                        case 0 : 
                            DrawTexture(black,0,0,Fade(BLACK,alpha));
                            break;
                        case 1 :
                            DrawText(TextSubtext("DK SS",0,splashCounter/13),game->screenWidth/3 + 25, game->screenHeight*2/3 + 18, 23, BLACK);
                            DrawTexture(logo,game->screenWidth/3 + 25, game->screenHeight/4,RAYWHITE);
                            break;
                        case 2 : 
                            DrawTexture(black,0,0,Fade(BLACK,alpha));
                            break;
                    }
                    break;
                case POWERED:
                    break;
                case DISCLAIMER:
                    break;
                case MENU:
                    break;
                case GAME:
                    BeginMode2D(game->board->camera);
                        DrawTexture(game->board->mapBackground, 0, 0, WHITE);
                        DrawTexture(game->board->map, 0, 0, WHITE);
                        MovementInBoard(game);
                    EndMode2D();
                    break;
                case NEWGAME:
                    break;

                case LOADGAME:
                    break;

                case SETTINGS:
                    break;

                case CREDITS:
                    break;

                case GREETIGS:
                    break;

                case EXIT:
                    break;
                default:
                    break;
            }
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
    game->screenWidth = 1920;
    game->screenHeight = 1080;
    //game->screenWidth = 1280;
    //game->screenHeight = 700;
    game->fps = 60;
    game->speed = 200.0f;
    game->screenCenterWidth = (int)game->screenWidth/2;
    game->screenCenterHeight = (int)game->screenHeight/2;
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
    board->mapBackground = LoadTexture("./res/assets/map/Space.png");
    board->map = LoadTexture("./res/assets/map/Board.png");
    float initialX = 1723.0f, intialY = 1699.0f;
    for(int x=0;x<24;x++){
        for(int y=0;y<24;y++){
            board->boxes[x][y].tilePosition = (Vector2){initialX+(x*86),intialY+(y*86)};
            board->boxes[x][y].status = '-';
            board->boxes[x][y].isRoom = 0;
        }
    }
    for(int x=0;x<24;x++){
        if(x == 0 || x == 1 || x == 11 || x == 12 || x == 22 || x == 23 ){
            for(int y=0;y<24;y++){
                board->boxes[y][x].status = 'f';
            }
        }else if((x > 1 && x <= 8)|| x == 16){
            board->boxes[0][x].status = 'f';
            board->boxes[1][x].status = 'f';
            board->boxes[6][x].status = 'f';
            board->boxes[11][x].status = 'f';
            board->boxes[12][x].status = 'f';
            board->boxes[17][x].status = 'f';
            board->boxes[22][x].status = 'f';
            board->boxes[23][x].status = 'f';
        }else if(x > 17 && x < 22){
            board->boxes[0][x].status = 'f';
            board->boxes[1][x].status = 'f';
            board->boxes[11][x].status = 'f';
            board->boxes[12][x].status = 'f';
            board->boxes[22][x].status = 'f';
            board->boxes[23][x].status = 'f';
        }else if(x >= 9 && x < 16){
            board->boxes[0][x].status = 'f';
            board->boxes[1][x].status = 'f';
            board->boxes[6][x].status = 'f';
            board->boxes[8][x].status = 'f';
            board->boxes[9][x].status = 'f';
            board->boxes[10][x].status = 'f';
            board->boxes[11][x].status = 'f';
            board->boxes[12][x].status = 'f';
            board->boxes[13][x].status = 'f';
            board->boxes[14][x].status = 'f';
            board->boxes[15][x].status = 'f';
            board->boxes[17][x].status = 'f';
            board->boxes[22][x].status = 'f';
            board->boxes[23][x].status = 'f';
        }else if(x == 17){
            board->boxes[0][x].status = 'f';
            board->boxes[1][x].status = 'f';
            board->boxes[6][x].status = 'f';
            board->boxes[7][x].status = 'f';
            board->boxes[8][x].status = 'f';
            board->boxes[9][x].status = 'f';
            board->boxes[10][x].status = 'f';
            board->boxes[11][x].status = 'f';
            board->boxes[12][x].status = 'f';
            board->boxes[13][x].status = 'f';
            board->boxes[14][x].status = 'f';
            board->boxes[15][x].status = 'f';
            board->boxes[16][x].status = 'f';
            board->boxes[17][x].status = 'f';
            board->boxes[22][x].status = 'f';
            board->boxes[23][x].status = 'f';
        }
    }
    
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