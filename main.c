/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2020 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <stdio.h>
#include "raylib.h"
#include "impostorLib.h"

int main(){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920, screenHeight = 1080; //monitor normal
    //const int screenWidth = 1366, screenHeight = 768; //monitor lap
    //const int screenWidth = 1024, screenHeight = 768; //monitor feo
    //const int screenWidth = 1280, screenHeight = 800; //monitor mac

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
 
    Texture2D player = LoadTexture("./res/assets/crewmates/red/left.png");
    float frameWidth = (float)(player.width/12);
    float frameHeight = (float)player.height;
    int maxFrames = (int)(player.width/(int)frameWidth);
    float timer = 0.0f;
    int frame = 0;
    Rectangle frameRec = {0,0,frameWidth,frameHeight};
    Vector2 vec2 = {20,20};

    // Main game loop - Detect window close button or ESC key
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
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}