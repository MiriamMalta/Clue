#include "graphsLib.h"
#include "impostorLib.h"
#include "mechanicsLib.h"

/**
 * MovementInBoard manages the movement and the animation of
 * the player. As well works with the camera and detects
 * the principal keyboard events.
 */
void MovementInBoard(GameState game){
    // This code manages the animation selections

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
    
    // This code manages the movement of the Player trought the Board

    if ((IsKeyReleased(KEY_W) || IsKeyReleased(KEY_UP)) && (game->playerInTurn->movesLeft > 1)){
        if((game->playerInTurn->y-1 >= 0) && (game->board->boxes[game->playerInTurn->x][game->playerInTurn->y-1].status == 'f' || game->board->boxes[game->playerInTurn->x][game->playerInTurn->y-1].status == 'd')){
            game->playerInTurn->x;
            game->playerInTurn->y--;
            game->playerInTurn->movesLeft--;
        }
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        SelectAnimation(game,1,true);
    }
    if ((IsKeyReleased(KEY_S) || IsKeyReleased(KEY_DOWN)) && (game->playerInTurn->movesLeft > 1)){
        if((game->playerInTurn->y+1 < 24) && (game->board->boxes[game->playerInTurn->x][game->playerInTurn->y+1].status == 'f' || game->board->boxes[game->playerInTurn->x][game->playerInTurn->y+1].status == 'd')){
            game->playerInTurn->x;
            game->playerInTurn->y++;
            game->playerInTurn->movesLeft--;
        }
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        SelectAnimation(game,2,true);
    }
    if ((IsKeyReleased(KEY_D) || IsKeyReleased(KEY_RIGHT)) && (game->playerInTurn->movesLeft > 1)){
        if((game->playerInTurn->x+1 < 24) && (game->board->boxes[game->playerInTurn->x+1][game->playerInTurn->y].status == 'f' || game->board->boxes[game->playerInTurn->x+1][game->playerInTurn->y].status == 'd')){
            game->playerInTurn->x++;
            game->playerInTurn->y;
            game->playerInTurn->movesLeft--;
        }
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        SelectAnimation(game,3,true);
    }
    if ((IsKeyReleased(KEY_A) || IsKeyReleased(KEY_LEFT)) && (game->playerInTurn->movesLeft > 1)){
        if((game->playerInTurn->x-1 >= 0) && (game->board->boxes[game->playerInTurn->x-1][game->playerInTurn->y].status == 'f' || game->board->boxes[game->playerInTurn->x-1][game->playerInTurn->y].status == 'd')){
            game->playerInTurn->x--;
            game->playerInTurn->y;
            game->playerInTurn->movesLeft--;
        }
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        SelectAnimation(game,4,true);
    }
 
    /**
     * This block of code checks:
     * - The turns left of the player
     * - The position of the Camera
     * - The correct animation in the game
     * - The room events
     */
    NextTurn(game);
    UpdateCameraPosition(game);
    UpdateAnimation(game);
    MoveCharacter(game);
}

/**
 * Check the state of the player, the next movements 
 * and update the variables of the animations.
 */
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

/**
 * Update the states of the animations and redraw the Player.
 */
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

/**
 * - Update the camera position
 * - Update the zoom level
 * - Print the Green Lines of the player 
 */
void UpdateCameraPosition(GameState game){
    game->board->camera.target = (Vector2) {game->playerInTurn->position.x+43,game->playerInTurn->position.y+50};
    game->board->camera.zoom += ((float)GetMouseWheelMove()*0.05f);
    if (game->board->camera.zoom > 3.0f) game->board->camera.zoom = 3.0f;
    else if (game->board->camera.zoom < 1.0f) game->board->camera.zoom = 1.0f;
    DrawLine(game->board->camera.target.x,-game->screenHeight*10,game->board->camera.target.x,game->screenHeight*10,GREEN);
    DrawLine(-game->screenWidth*10,game->board->camera.target.y,game->screenWidth*10,game->board->camera.target.y,GREEN);  
}
/**
 * Intialize the camera data layer
 */
void InitCamera(GameState game){
    game->board->camera.target = (Vector2) {game->playerInTurn->position.x+20,game->playerInTurn->position.y+20};
    game->board->camera.offset = (Vector2) {game->screenCenterWidth,game->screenCenterHeight};
    game->board->camera.rotation = 0.0f;
    game->board->camera.zoom = 1.0f;
}


/*
Move Outside
    [I]
[J]     [L]
    [M]
*/
void MoveCharacter(GameState game){
    // UPPER ENGINE
    if ((game->playerInTurn->x == 2 && game->playerInTurn->y == 0) || (game->playerInTurn->x == 0 && game->playerInTurn->y == 2)){
        game->playerInTurn->x = 0;
        game->playerInTurn->y = 0;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 0 && game->playerInTurn->y == 0){
        if (IsKeyReleased(KEY_M)){
            game->playerInTurn->x = 0;
            game->playerInTurn->y = 3;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_L)){
            game->playerInTurn->x = 3;
            game->playerInTurn->y = 0;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // WEAPONS
    if ((game->playerInTurn->x == 21 && game->playerInTurn->y == 0) || (game->playerInTurn->x == 23 && game->playerInTurn->y == 2)){
        game->playerInTurn->x = 23;
        game->playerInTurn->y = 0;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 23 && game->playerInTurn->y == 0){
        if (IsKeyReleased(KEY_M)){
            game->playerInTurn->x = 23;
            game->playerInTurn->y = 3;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_J)){
            game->playerInTurn->x = 20;
            game->playerInTurn->y = 0;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // LOWER ENGINE
    if ((game->playerInTurn->x == 0 && game->playerInTurn->y == 21) || (game->playerInTurn->x == 2 && game->playerInTurn->y == 23)){
        game->playerInTurn->x = 0;
        game->playerInTurn->y = 23;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 0 && game->playerInTurn->y == 23){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 0;
            game->playerInTurn->y = 20;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_L)){
            game->playerInTurn->x = 3;
            game->playerInTurn->y = 23;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // SHIELDS
    if ((game->playerInTurn->x == 21 && game->playerInTurn->y == 23) || (game->playerInTurn->x == 23 && game->playerInTurn->y == 21)){
        game->playerInTurn->x = 23;
        game->playerInTurn->y = 23;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 23 && game->playerInTurn->y == 23){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 23;
            game->playerInTurn->y = 20;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_J)){
            game->playerInTurn->x = 20;
            game->playerInTurn->y = 23;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // REACTOR
    if ((game->playerInTurn->x == 0 && game->playerInTurn->y == 10) || (game->playerInTurn->x == 0 && game->playerInTurn->y == 13)){
        game->playerInTurn->x = 0;
        game->playerInTurn->y = 12;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 0 && game->playerInTurn->y == 12){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 0;
            game->playerInTurn->y = 9;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_M)){
            game->playerInTurn->x = 0;
            game->playerInTurn->y = 14;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // NAVIGATION
    if ((game->playerInTurn->x == 23 && game->playerInTurn->y == 10) || (game->playerInTurn->x == 23 && game->playerInTurn->y == 13)){
        game->playerInTurn->x = 23;
        game->playerInTurn->y = 12;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 23 && game->playerInTurn->y == 12){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 23;
            game->playerInTurn->y = 9;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_M)){
            game->playerInTurn->x = 23;
            game->playerInTurn->y = 14;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // MED-BAY
    if ((game->playerInTurn->x == 6 && game->playerInTurn->y == 5) || (game->playerInTurn->x == 6 && game->playerInTurn->y == 7)){
        game->playerInTurn->x = 6;
        game->playerInTurn->y = 6;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 6 && game->playerInTurn->y == 6){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 6;
            game->playerInTurn->y = 4;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_M)){
            game->playerInTurn->x = 6;
            game->playerInTurn->y = 8;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // STORAGE
    if ((game->playerInTurn->x == 17 && game->playerInTurn->y == 5) || (game->playerInTurn->x == 17 && game->playerInTurn->y == 7)){
        game->playerInTurn->x = 17;
        game->playerInTurn->y = 6;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 17 && game->playerInTurn->y == 6){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 17;
            game->playerInTurn->y = 4;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_M)){
            game->playerInTurn->x = 17;
            game->playerInTurn->y = 8;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // ADMIN
    if ((game->playerInTurn->x == 6 && game->playerInTurn->y == 16) || (game->playerInTurn->x == 7 && game->playerInTurn->y == 17)){
        game->playerInTurn->x = 5;
        game->playerInTurn->y = 18;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 5 && game->playerInTurn->y == 18){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 6;
            game->playerInTurn->y = 15;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_L)){
            game->playerInTurn->x = 8;
            game->playerInTurn->y = 17;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // ELECTRICAL
    if ((game->playerInTurn->x == 17 && game->playerInTurn->y == 16) || (game->playerInTurn->x == 16 && game->playerInTurn->y == 17)){
        game->playerInTurn->x = 18;
        game->playerInTurn->y = 18;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 18 && game->playerInTurn->y == 18){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 17;
            game->playerInTurn->y = 15;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_J)){
            game->playerInTurn->x = 15;
            game->playerInTurn->y = 17;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
    // CAFETERIA
    if ((game->playerInTurn->x == 11 && game->playerInTurn->y == 9) || (game->playerInTurn->x == 12 && game->playerInTurn->y == 9) || (game->playerInTurn->x == 11 && game->playerInTurn->y == 14) || (game->playerInTurn->x == 12 && game->playerInTurn->y == 14) || (game->playerInTurn->x == 9 && game->playerInTurn->y == 11) || (game->playerInTurn->x == 9 && game->playerInTurn->y == 12) || (game->playerInTurn->x == 14 && game->playerInTurn->y == 11) || (game->playerInTurn->x == 14 && game->playerInTurn->y == 12)){
        game->playerInTurn->x = 12;
        game->playerInTurn->y = 12;
        game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
    }
    if (game->playerInTurn->x == 12 && game->playerInTurn->y == 12){
        if (IsKeyReleased(KEY_I)){
            game->playerInTurn->x = 12;
            game->playerInTurn->y = 8;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_J)){
            game->playerInTurn->x = 8;
            game->playerInTurn->y = 12;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_L)){
            game->playerInTurn->x = 15;
            game->playerInTurn->y = 12;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
        if (IsKeyReleased(KEY_M)){
            game->playerInTurn->x = 12;
            game->playerInTurn->y = 15;
            game->playerInTurn->position = game->board->boxes[game->playerInTurn->x][game->playerInTurn->y].tilePosition;
        }
    }
}

/**
 * Print the structure data of the Board
 */
void PrintMap(GameState game){
    for(int x=0;x<24;x++){
        for(int y=0;y<24;y++){
            fprintf(stdout, "[%c] ",game->board->boxes[y][x].status);
        }
        fprintf(stdout, "\n");
    }
}
/**
 * Print the players and the cards in their possession.
 */
void PrintPlayersAndCards(GameState game){
    for(int j = 0; j < game->playersAlive; j++){
        for(int i = 0; i < game->playerInTurn->numCards; i++){
            fprintf(stdout, "[%c]", game->playerInTurn->cardsInHand[i].id);
        }
        fprintf(stdout, " {%d}\n", game->playerInTurn->numCards);
        game->playerInTurn = game->playerInTurn->next;
    }
    fprintf(stdout, "\n");
}


