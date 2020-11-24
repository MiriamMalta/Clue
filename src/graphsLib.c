#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "graphsLib.h"
#include "impostorLib.h"

//Aqui solamente funciones graficas

void Movement(GameState game)
{
    if(IsKeyDown(KEY_K)){
        game->playerInTurn = game->playerInTurn->next;
    }
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        game->playerInTurn->position.y += GetFrameTime() * -(game->speed);
        if (game->playerInTurn->movingAnimate == 0)
        {
            game->playerInTurn->movingAnimate = 2;
        }
        else if (game->playerInTurn->movingAnimate == 1)
        {
            game->playerInTurn->movingAnimate = 3;
        }
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 12);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        game->playerInTurn->position.y += GetFrameTime() * (game->speed);
        if (game->playerInTurn->movingAnimate == 0)
        {
            game->playerInTurn->movingAnimate = 2;
        }
        else if (game->playerInTurn->movingAnimate == 1)
        {
            game->playerInTurn->movingAnimate = 3;
        }
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 12);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        game->playerInTurn->position.x += GetFrameTime() * (game->speed);
        game->playerInTurn->movingAnimate = 2;
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 12);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        game->playerInTurn->position.x += GetFrameTime() * -(game->speed);
        game->playerInTurn->movingAnimate = 3;
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 12);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    
    game->board->camera.target = (Vector2) {game->playerInTurn->position.x+43,game->playerInTurn->position.y+50};
    game->board->camera.zoom += ((float)GetMouseWheelMove()*0.05f);
    if (game->board->camera.zoom > 3.0f) game->board->camera.zoom = 3.0f;
    else if (game->board->camera.zoom < 1.0f) game->board->camera.zoom = 1.0f;

    if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT))
    {
        game->playerInTurn->movingAnimate = 0;
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 1);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT))
    {
        game->playerInTurn->movingAnimate = 1;
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 1);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    if (IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP))
    {
        if (game->playerInTurn->movingAnimate == 2)
        {
            game->playerInTurn->movingAnimate = 0;
        }
        else if (game->playerInTurn->movingAnimate == 3)
        {
            game->playerInTurn->movingAnimate = 1;
        }
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 1);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    if (IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN))
    {
        if (game->playerInTurn->movingAnimate == 2)
        {
            game->playerInTurn->movingAnimate = 0;
        }
        else if (game->playerInTurn->movingAnimate == 3)
        {
            game->playerInTurn->movingAnimate = 1;
        }
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 1);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    game->playerInTurn->timer += GetFrameTime();
    if (game->playerInTurn->timer >= 0.05f)
    {
        game->playerInTurn->timer = 0.0f;
        game->playerInTurn->frame += 1;
    }
    game->playerInTurn->frame = game->playerInTurn->frame % game->playerInTurn->maxFrames;
    game->playerInTurn->frameRec.x = (game->playerInTurn->frameRec.width * game->playerInTurn->frame);
    DrawTextureRec(
        game->playerInTurn->skin[game->playerInTurn->movingAnimate],
        game->playerInTurn->frameRec,
        game->playerInTurn->position,
        RAYWHITE
    );
    DrawLine(game->board->camera.target.x,-game->screenHeight*10,game->board->camera.target.x,game->screenHeight*10,GREEN);
    DrawLine(-game->screenWidth*10,game->board->camera.target.y,game->screenWidth*10,game->board->camera.target.y,GREEN);    
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