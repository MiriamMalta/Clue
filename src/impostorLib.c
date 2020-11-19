#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "raylib.h"
#include "impostorLib.h"
#include "mecanicsLib.h"
#include "graphsLib.h"

//Aqui juntamos todo el codigo




GameState newImpostorGame(){
    GameState game = malloc(sizeof(struct ImpostorGame));
    game->screenWidth = 1280;
    game->screenHeight = 800;
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
    Texture2D map = LoadTexture("./res/assets/map/Try_Map_1.png");
    Player player = newPlayer(game, "White");
    Camera2D camera = { 0 };
    camera.target = (Vector2) { player->position.x+20, player->position.y+20};
    camera.offset = (Vector2) {game->screenCenterWidth,game->screenCenterHeight};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
            //MapMovement(map);
            DrawTexture(map, 0, 0, WHITE);
            Movement(game,player,&camera);
             // Camera zoom controls
            camera.zoom += ((float)GetMouseWheelMove()*0.05f);

            if (camera.zoom > 3.0f) camera.zoom = 3.0f;
            else if (camera.zoom < 0.1f) camera.zoom = 0.1f;
            EndMode2D();

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
    player->movingAnimate = 0;
    player->frameWidth = (float)(player->skin[player->movingAnimate].width/1);
    player->frameHeight = (float)(player->skin[player->movingAnimate].height);
    player->maxFrames = (int)(player->skin[player->movingAnimate].width/(int)player->frameWidth);
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
