#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "graphsLib.h"
#include "impostorLib.h"

//Aqui solamente funciones graficas

void Movement(Player player)
{
    if (IsKeyDown(KEY_W))
    {
        player->position.y += GetFrameTime() * -100.0f;
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
    if (IsKeyDown(KEY_S))
    {
        player->position.y += GetFrameTime() * 100.0f;
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
    if (IsKeyDown(KEY_D))
    {
        player->position.x += GetFrameTime() * 100.0f;
        player->movingAnimate = 2;
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 12);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyDown(KEY_A))
    {
        player->position.x += GetFrameTime() * -100.0f;
        player->movingAnimate = 3;
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 12);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyReleased(KEY_D))
    {
        player->movingAnimate = 0;
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 1);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyReleased(KEY_A))
    {
        player->movingAnimate = 1;
        player->frameWidth = (float)(player->skin[player->movingAnimate].width / 1);
        player->maxFrames = (int)(player->skin[player->movingAnimate].width / (int)player->frameWidth);
    }
    if (IsKeyReleased(KEY_W))
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
    if (IsKeyReleased(KEY_S))
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
}
void Teletransport()
{
}
void EnterRoom()
{
}
void ExitRoom()
{
}