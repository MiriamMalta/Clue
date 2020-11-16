#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "raylib.h"
#include "impostorLib.h"

//Aqui juntamos todo el codigo




GameState newImpostorGame(){
    GameState game = malloc(sizeof(struct ImpostorGame));
    game->screenWidth = 1024;
    game->screenHeight = 768;
    game->screenCenterWidth = (int)game->screenWidth/2;
    game->screenCenterHeight = (int)game->screenHeight/2;
    //const int screenWidth = 1920, screenHeight = 1080; //monitor normal
    //const int screenWidth = 1366, screenHeight = 768; //monitor lap
    //const int screenWidth = 1024, screenHeight = 768; //monitor feo
    //const int screenWidth = 1280, screenHeight = 800; //monitor mac

    InitWindow(game->screenWidth,game->screenHeight, "raylib");
    SetTargetFPS(60);
    return game;
}
void playImpostor(GameState game){
    Texture2D player = LoadTexture("./res/assets/crewmates/Yellow/right.png");
    float frameWidth = (float)(player.width/12);
    float frameHeight = (float)player.height;
    int maxFrames = (int)(player.width/(int)frameWidth);
    float timer = 0.0f;
    int frame = 0;
    Rectangle frameRec = {0,0,frameWidth,frameHeight};
    Vector2 vec2 = {game->screenCenterWidth,game->screenCenterHeight};
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        timer += GetFrameTime();
        if(timer >= 0.05f){
            timer = 0.0f;
            frame += 1;
        }
        frame = frame % maxFrames;
        printf("%d\n",frame);
        frameRec.x = (frameRec.width*frame);
        DrawTextureRec(
            player,
            frameRec,
            vec2,
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