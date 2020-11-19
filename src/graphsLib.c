#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "graphsLib.h"
#include "impostorLib.h"

//Aqui solamente funciones graficas

void Movement(GameState game,Player player,Camera2D* cam)
{
    Camera2D camera;
    camera = *cam;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        player->position.y += GetFrameTime() * -(game->speed);
        if (player->movingAnimate == 0)
        {
            player->movingAnimate = 2;
        }
        else if (player->movingAnimate == 1)
        {
            player->movingAnimate = 3;
        }
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 12);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        player->position.y += GetFrameTime() * (game->speed);
        if (player->movingAnimate == 0)
        {
            player->movingAnimate = 2;
        }
        else if (player->movingAnimate == 1)
        {
            player->movingAnimate = 3;
        }
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 12);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        player->position.x += GetFrameTime() * (game->speed);
        player->movingAnimate = 2;
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 12);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        player->position.x += GetFrameTime() * -(game->speed);
        player->movingAnimate = 3;
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 12);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    camera.target = (Vector2) {player->position.x+43,player->position.y+50};
    camera.zoom += ((float)GetMouseWheelMove()*0.05f);
    if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    else if (camera.zoom < 1.0f) camera.zoom = 1.0f;

    if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT))
    {
        player->movingAnimate = 0;
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 1);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT))
    {
        player->movingAnimate = 1;
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 1);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP))
    {
        if (player->movingAnimate == 2)
        {
            player->movingAnimate = 0;
        }
        else if (player->movingAnimate == 3)
        {
            player->movingAnimate = 1;
        }
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 1);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN))
    {
        if (player->movingAnimate == 2)
        {
            player->movingAnimate = 0;
        }
        else if (player->movingAnimate == 3)
        {
            player->movingAnimate = 1;
        }
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 1);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    player->timer += GetFrameTime();
    if (player->timer >= 0.05f)
    {
        player->timer = 0.0f;
        player->frame += 1;
    }
    player->frame = player->frame % player->maxFrames;
    player->frameRec.x = (player->frameRec.width * player->frame);
    DrawTextureRec(
        player->skin[player->movingAnimate],
        player->frameRec,
        player->position,
        RAYWHITE
    );
    DrawLine(camera.target.x,-game->screenHeight*10,camera.target.x,game->screenHeight*10,GREEN);
    DrawLine(-game->screenWidth*10,camera.target.y,game->screenWidth*10,camera.target.y,GREEN);
    *cam = camera;        
}

void Teleport()
{
}
void EnterRoom()
{
}
void ExitRoom()
{
}