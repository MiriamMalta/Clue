#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "raylib.h"
#include "impostorLib.h"
#include "mecanicsLib.h"

//Aqui juntamos todo el codigo




GameState newImpostorGame(){
    GameState game = malloc(sizeof(struct ImpostorGame));
    game->screenWidth = 1024;
    game->screenHeight = 768;
    game->fps = 60;
    game->screenCenterWidth = (int)game->screenWidth/2;
    game->screenCenterHeight = (int)game->screenHeight/2;
    //const int screenWidth = 1920, screenHeight = 1080; //monitor normal
    //const int screenWidth = 1366, screenHeight = 768; //monitor lap
    //const int screenWidth = 1024, screenHeight = 768; //monitor feo
    //const int screenWidth = 1280, screenHeight = 800; //monitor mac

    InitWindow(game->screenWidth,game->screenHeight, "raylib");
    SetTargetFPS(game->fps);
    return game;
}
void playImpostor(GameState game){
    Player red_player = newPlayer(game, "Red");
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        red_player->timer += GetFrameTime();
        if(red_player->timer >= 0.05f){
            red_player->timer = 0.0f;
            red_player->frame += 1;
        }
        red_player->frame = red_player->frame % red_player->maxFrames;
        red_player->frameRec.x = (red_player->frameRec.width*red_player->frame);
        DrawTextureRec(
            red_player->skin[0],
            red_player->frameRec,
            red_player->position,
            RAYWHITE
        );

        EndDrawing();
    }
    
}
void endImpostor(){
    CloseWindow();
}
void initImpostor(){

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
    player->frameWidth = (float)(player->skin[0].width);
    player->frameHeight = (float)(player->skin[0].height);
    player->maxFrames = (int)(player->skin[0].width/(int)player->frameWidth);
    player->timer = 0.0f;
    player->frame = 0;
    player->frameRec.x = 0;
    player->frameRec.y = 0;
    player->frameRec.width = player->frameWidth; 
    player->frameRec.height = player->frameHeight;
    player->position.x = game->screenCenterWidth;
    player->position.y = game->screenCenterHeight;
    return player;
}
