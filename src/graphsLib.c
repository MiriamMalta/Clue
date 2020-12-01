#include "graphsLib.h"
#include "impostorLib.h"

//Aqui solamente funciones graficas

void Movement(GameState game){
    if(IsKeyReleased(KEY_K)){
        game->playerInTurn = game->playerInTurn->next;
    }
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        game->playerInTurn->position.y += GetFrameTime() * -(game->speed);
        SelectAnimation(game,1,false);
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        game->playerInTurn->position.y += GetFrameTime() * (game->speed);
        SelectAnimation(game,2,false);
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        game->playerInTurn->position.x += GetFrameTime() * (game->speed);
        SelectAnimation(game,3,false);
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        game->playerInTurn->position.x += GetFrameTime() * -(game->speed);
        SelectAnimation(game,4,false);
    }
    
    UpdateCameraPosition(game);

    if (IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP)){
        SelectAnimation(game,1,true);
    }
    if (IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN)){
        SelectAnimation(game,2,true);
    }
    if (IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT)){
        SelectAnimation(game,3,true);
    }
    if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT)){
        SelectAnimation(game,4,true);
    }
    UpdateAnimation(game);
}

void MovementInBoard(GameState game){
    if(IsKeyReleased(KEY_K)){
        game->playerInTurn = game->playerInTurn->next;
    }
    if (IsKeyReleased(KEY_SPACE)){
        game->playerInTurn->movesLeft = CalculateRandomMovements();  
        fprintf(stdout, "%d\n", game->playerInTurn->movesLeft); //Left here for now to know what number we got on the dice
    }
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        SelectAnimation(game,1,false);
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        SelectAnimation(game,2,false);
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        SelectAnimation(game,3,false);
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        SelectAnimation(game,4,false);
    }
    
    
    if ((IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP)) && (game->playerInTurn->movesLeft > 0)){
        if((game->playerInTurn->y-1 >= 0) && (game->board->boxes[game->playerInTurn->x][game->playerInTurn->y-1].status == 'f' || game->board->boxes[game->playerInTurn->x][game->playerInTurn->y-1].status == 'd')){
            game->playerInTurn->x;
            game->playerInTurn->y--;
            game->playerInTurn->movesLeft--;
        }
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        SelectAnimation(game,1,true);
    }
    if ((IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN)) && (game->playerInTurn->movesLeft > 0)){
        if((game->playerInTurn->y+1 < 24) && (game->board->boxes[game->playerInTurn->x][game->playerInTurn->y+1].status == 'f' || game->board->boxes[game->playerInTurn->x][game->playerInTurn->y+1].status == 'd')){
            game->playerInTurn->x;
            game->playerInTurn->y++;
            game->playerInTurn->movesLeft--;
        }
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        SelectAnimation(game,2,true);
    }
    if ((IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT)) && (game->playerInTurn->movesLeft > 0)){
        if((game->playerInTurn->x+1 < 24) && (game->board->boxes[game->playerInTurn->x+1][game->playerInTurn->y].status == 'f' || game->board->boxes[game->playerInTurn->x+1][game->playerInTurn->y].status == 'd')){
            game->playerInTurn->x++;
            game->playerInTurn->y;
            game->playerInTurn->movesLeft--;
        }
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        SelectAnimation(game,3,true);
    }
    if ((IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT)) && (game->playerInTurn->movesLeft > 0)){
        if((game->playerInTurn->x-1 >= 0) && (game->board->boxes[game->playerInTurn->x-1][game->playerInTurn->y].status == 'f' || game->board->boxes[game->playerInTurn->x-1][game->playerInTurn->y].status == 'd')){
            game->playerInTurn->x--;
            game->playerInTurn->y;
            game->playerInTurn->movesLeft--;
        }
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        SelectAnimation(game,4,true);
    }
    UpdateCameraPosition(game);
    UpdateAnimation(game);
}

void SelectAnimation(GameState game, int Selection,int isStill){
    if(isStill){
        switch (Selection){
            case 1: // Up
                if (game->playerInTurn->movingAnimate == 2){
                    game->playerInTurn->movingAnimate = 0;
                }else if (game->playerInTurn->movingAnimate == 3){
                    game->playerInTurn->movingAnimate = 1;
                }
                break;
            case 2: // Down
                if (game->playerInTurn->movingAnimate == 2){
                    game->playerInTurn->movingAnimate = 0;
                }else if (game->playerInTurn->movingAnimate == 3){
                    game->playerInTurn->movingAnimate = 1;
                }
                break;
            case 3: // Right
                game->playerInTurn->movingAnimate = 0; 
                break;
            case 4: // Left
                game->playerInTurn->movingAnimate = 1;
                break;
            default:
                break;
        }
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 1);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }
    else{
        switch (Selection){
            case 1: // Up
                if (game->playerInTurn->movingAnimate == 0){
                    game->playerInTurn->movingAnimate = 2;
                }else if (game->playerInTurn->movingAnimate == 1){
                    game->playerInTurn->movingAnimate = 3;
                }
                break;
            case 2: // Down
                if (game->playerInTurn->movingAnimate == 0){
                    game->playerInTurn->movingAnimate = 2;
                }else if (game->playerInTurn->movingAnimate == 1){
                    game->playerInTurn->movingAnimate = 3;
                }
                break;
            case 3: // Right
                game->playerInTurn->movingAnimate = 2; 
                break;
            case 4: // Left
                game->playerInTurn->movingAnimate = 3;
                break;
            default:
                break;
        }
        game->playerInTurn->frameWidth = (float)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / 12);
        game->playerInTurn->maxFrames = (int)(game->playerInTurn->skin[game->playerInTurn->movingAnimate].width / (int)game->playerInTurn->frameWidth);
    }

}

void UpdateAnimation(GameState game){
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
}

void UpdateCameraPosition(GameState game){
    game->board->camera.target = (Vector2) {game->playerInTurn->position.x+43,game->playerInTurn->position.y+50};
    game->board->camera.zoom += ((float)GetMouseWheelMove()*0.05f);
    if (game->board->camera.zoom > 3.0f) game->board->camera.zoom = 3.0f;
    else if (game->board->camera.zoom < 1.0f) game->board->camera.zoom = 1.0f;
    DrawLine(game->board->camera.target.x,-game->screenHeight*10,game->board->camera.target.x,game->screenHeight*10,GREEN);
    DrawLine(-game->screenWidth*10,game->board->camera.target.y,game->screenWidth*10,game->board->camera.target.y,GREEN);  
}

void InitCamera(GameState game){
    game->board->camera.target = (Vector2) {game->playerInTurn->position.x+20,game->playerInTurn->position.y+20};
    game->board->camera.offset = (Vector2) {game->screenCenterWidth,game->screenCenterHeight};
    game->board->camera.rotation = 0.0f;
    game->board->camera.zoom = 1.0f;
}

void SetPlayersInBoard(GameState game){
    for(int i=0;i<game->playersAlive;i++){
        game->playerInTurn->x = CalculateRandomPlacements(game);
        game->playerInTurn->y = 8;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        game->playerInTurn = game->playerInTurn->next;
    }
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
