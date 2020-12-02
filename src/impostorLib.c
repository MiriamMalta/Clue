#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "raylib.h"
#include "impostorLib.h"
#include "mechanicsLib.h"
#include "graphsLib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION            // Avoid including raygui implementation again


//Aqui juntamos todo el codigo

void playImpostor(GameState game){
    GuiLoadStyle("./res/styles/impostor/impostor.rgs");
    GameScreen  gameScene = LOGO;
    int         state = 0;
    int         splashCounter = 0;
    int         transCounter = 0; 
    int         exit = true;
    float       alpha = 0.0f;
    Music ostMenu = LoadMusicStream("./res/music/ost_menu.mp3");
    Music ostGame = LoadMusicStream("./res/music/ost_game.mp3");
    SetMusicVolume(ostMenu,0.1);
    SetMusicVolume(ostGame,0.1);
    PlayMusicStream(ostMenu);
    float timePlayed = 0.0f;
    int musicFlag = 0;
    Texture2D logo = LoadTexture("./res/animations/Logo2.png");
    Texture2D menu = LoadTexture("./res/animations/Menu.png");
    Texture2D black = LoadTexture("./res/animations/black.png");
    Texture2D RL = LoadTexture("./res/animations/raylib_logo.png");
    Texture2D credits = LoadTexture("./res/animations/Credits.png");
    Texture2D save = LoadTexture("./res/animations/Save.png");   
    initImpostor(game);
    
    while (!WindowShouldClose() && exit){
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
                        gameScene = POWERED;
                        state = 0;
                    }
                }
                break;
            case POWERED:
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
                        gameScene = DISCLAIMER;
                        state = 0;
                    }
                }
                break;
            case DISCLAIMER:
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
                        gameScene = MENU;
                        state = 0;
                    }
                }
                break;
            case MENU:
                if(musicFlag == 0){
                    StopMusicStream(ostMenu);
                    PlayMusicStream(ostMenu);
                    musicFlag = 1;
                    timePlayed = 0.0;

                }else if (timePlayed >= 99.0){
                    musicFlag = 0;
                }else{
                    UpdateMusicStream(ostMenu);
                    timePlayed = GetMusicTimePlayed(ostMenu)/GetMusicTimeLength(ostMenu)*100;
                }
                break;
            case GAME:
                if(musicFlag == 0 ){
                    StopMusicStream(ostGame);
                    PlayMusicStream(ostGame);
                    musicFlag = 1;
                    timePlayed = 0.0;
                }else if(timePlayed >= 99.0){
                    musicFlag = 0;
                }else{
                    UpdateMusicStream(ostGame);
                    timePlayed = GetMusicTimePlayed(ostGame)/GetMusicTimeLength(ostGame)*100;
                }
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

            case THANKS:
                CloseAudioDevice();
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
                        gameScene = EXIT;
                        state = 0;
                    }
                }
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
                            DrawTexture(black,0,0,BLACK);
                            DrawText(TextSubtext("DK SS",0,splashCounter/13),game->screenWidth/3 + 25, game->screenHeight*2/3 + 18, 23, WHITE);
                            DrawTexture(logo,game->screenWidth/3 + 25, game->screenHeight/4,RAYWHITE);
                            break;
                        case 2 : 
                            DrawTexture(black,0,0,BLACK);
                            break;
                    }
                    break;
                case POWERED:
                    switch(state){
                        case 1 :
                            DrawText("Powered by", game->screenWidth/3 + 25, game->screenHeight/5 - 5, 20, BLACK);
                            DrawTexture(RL, game->screenWidth/2 - RL.width/2 + 5, game->screenHeight/2 - RL.height/2 + game->screenHeight/35, RAYWHITE);
                            break;
                        case 2 :
                            DrawTexture(black,0,0,Fade(BLACK,alpha));
                            break;
                    }
                    break;
                case DISCLAIMER:
                    switch(state){
                        case 0 : 
                            DrawTexture(black,0,0,Fade(BLACK,alpha));
                            break;
                        case 1 :
                            DrawTexture(black,0,0,BLACK);
                            DrawText(
                                "This Game is for Educational purposes. No nos demanden pliz.", 
                                //(game->screenCenterWidth/2)-150, 
                                game->screenCenterWidth/2,  
                                game->screenCenterHeight, 
                                30, 
                                WHITE
                            );
                            break;
                        case 2 :
                            DrawTexture(black,0,0,Fade(BLACK,alpha));
                            break;
                    }
                    break;
                case MENU:
                    DrawTexture(menu,0, 0,RAYWHITE);
                    //game->screenCenterWidth-225, 280, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 410, 460, 90 }, "New Game")) { 
                        fprintf(stdout,"New Game\n"); 
                        UnloadMusicStream(ostMenu);
                        PlayMusicStream(ostGame);
                        musicFlag = 0;
                        timePlayed = 0.0;
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 362, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 530, 460, 90 }, "Load Game")) {
                        fprintf(stdout,"Load Game\n");
                        gameScene = LOADGAME;
                        state = 0; 
                    }
                    //game->screenCenterWidth-225, 444, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 650, 460, 90 }, "Settings")) {
                        fprintf(stdout,"Settings\n"); 
                        gameScene = SETTINGS;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 526, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 770, 460, 90 }, "Credits")) { 
                        fprintf(stdout,"Credits\n"); 
                        gameScene = CREDITS;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 608, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 890, 460, 90 }, "Exit")) { 
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
            
                    break;
                case GAME:
                    
                    
                    BeginMode2D(game->board->camera);
                        DrawTexture(game->board->mapBackground, 0, 0, WHITE);
                        DrawTexture(game->board->map, 0, 0, WHITE);
                        MovementInBoard(game);
                        //fprintf(stdout,"x=[%f] y=[%f]||x=[%d] y=[%d]\n",game->board->camera.target.x,game->board->camera.target.y,(int)((game->board->camera.target.x)*.5),(int)((game->board->camera.target.y)*1.1));
                    EndMode2D();
                        if(IsKeyDown(KEY_P)){
                            int initXHUD = (int)((game->board->camera.target.x)-960);
                            int initYHUD = (int)((game->board->camera.target.y)+270);
                            //DrawRectangle(initXHUD,initYHUD,game->screenWidth,game->screenHeight/4,DARKGRAY);
                                
                            //GuiGroupBox((Rectangle){ initXHUD + 25, initYHUD + 30, 125, 150 }, "OPTIONS");
                            if (GuiButton((Rectangle){ initXHUD + 30, initYHUD + 40, 115, 30 }, "Tirar Dado")) {
                                fprintf(stdout,"Hola");
                            }
                            if (GuiButton((Rectangle){ initXHUD + 30, initYHUD + 75, 115, 30 }, "Suggest")) { 
                                fprintf(stdout,"Hola");

                            }
                            if (GuiButton((Rectangle){ initXHUD + 30, initYHUD + 110, 115, 30 }, "Notebook")) {
                                fprintf(stdout,"Hola");

                            }
                        }
                    
                    break;
                case NEWGAME:
                    break;

                case LOADGAME:
                    DrawTexture(save,0, 0,RAYWHITE);
                    //game->screenCenterWidth-225, 280, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 410, 460, 90 }, "Slot 1")) {  
                        fprintf(stdout,"Slot 1\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 362, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 530, 460, 90 }, "Slot 2")) {
                        fprintf(stdout,"Slot 2\n");
                        gameScene = GAME;
                        state = 0; 
                    }
                    //game->screenCenterWidth-225, 444, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 650, 460, 90 }, "Slot 3")) { 
                        fprintf(stdout,"Slot 3\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 526, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 770, 460, 90 }, "Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 608, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 890, 460, 90 }, "Exit")) {
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    break;
                case SAVEGAME:
                    DrawTexture(save,0, 0,RAYWHITE);
                    //game->screenCenterWidth-225, 280, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 410, 460, 90 }, "Slot 1")) { 
                        fprintf(stdout,"Slot 1\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 362, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 530, 460, 90 }, "Slot 2")) { 
                        fprintf(stdout,"Slot 2\n");
                        gameScene = GAME;
                        state = 0; 
                    }
                    //game->screenCenterWidth-225, 444, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 650, 460, 90 }, "Slot 3")) { 
                        fprintf(stdout,"Slot 3\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 526, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 770, 460, 90 }, "Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 608, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 890, 460, 90 }, "Exit")) {
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    break;
                case SETTINGS:
                    break;

                case CREDITS:
                    DrawTexture(credits,0, 0,RAYWHITE);
                    //game->screenCenterWidth-225, 526, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 770, 460, 90 }, "Menu")) {  
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    // game->screenCenterWidth-225, 608, 450, 70
                    if (GuiButton((Rectangle){ game->screenCenterWidth-230, 890, 460, 90 }, "Exit")) {  
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    break;

                case GREETIGS:
                    break;
                case THANKS:
                    switch(state){
                        case 0 : 
                            DrawTexture(black,0,0,Fade(BLACK,alpha));
                            break;
                        case 1 :
                            DrawTexture(black,0,0,BLACK);
                            DrawText(
                                "Gracias por jugar esta basura.", 
                                //(game->screenCenterWidth/2)+100
                                (game->screenCenterWidth/4)*3, 
                                game->screenCenterHeight, 
                                30, 
                                WHITE
                            );
                            break;
                        case 2 :
                            DrawTexture(black,0,0,Fade(BLACK,alpha));
                            break;
                    }
                    break;
                case EXIT:
                    exit = false;
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
// Initialization (called one time)
void initImpostor(GameState game){
    srand(time(NULL));    newPlayerList(game);
    game->board = NewBoard(game);
    SetPlayersInBoard(game);
    InitCamera(game);
    game->envelope = calloc(3, sizeof(char));
    InitializeCards(game);
}
GameState newImpostorGame(){
    GameState game = malloc(sizeof(struct ImpostorGame));
    int res = 1;
    switch(res){
        case 1:     // Monitor normal
            game->screenWidth = 1920;
            game->screenHeight = 1080;
            break;
        case 2:     // Monitor lap
            game->screenWidth = 1366;
            game->screenHeight = 768;
            break;
        case 3:     // Monitor feo
            game->screenWidth = 1024;
            game->screenHeight = 768;
            break;
        case 4:     // Monitor Mac
            game->screenWidth = 1280;
            game->screenHeight = 700;
            break;
        default:    // Default normal
            game->screenWidth = 1920;
            game->screenHeight = 1080;
            break;
    }
    game->fps = 60;
    game->speed = 200.0f;
    game->screenCenterWidth = (int)game->screenWidth/2;
    game->screenCenterHeight = (int)game->screenHeight/2;
    game->playersAlive = 0;
    InitWindow(game->screenWidth,game->screenHeight, "raylib");
    SetTargetFPS(game->fps);
    InitAudioDevice();
    return game;
}
Board NewBoard(GameState game){
    Board board = malloc(sizeof(struct BoardGame));
    board->mapBackground = LoadTexture("./res/assets/map/Space.png");
    board->map = LoadTexture("./res/assets/map/Sketch.png");
    float initialX = 1723.0f, intialY = 1699.0f;
    for(int x=0;x<24;x++){
        for(int y=0;y<24;y++){
            board->boxes[x][y].tilePosition = (Vector2){initialX+(x*86),intialY+(y*86)};
            board->boxes[x][y].status = '-';
            board->boxes[x][y].isRoom = 0;
        }
    }
    for(int x=0;x<24;x++){
        for(int y=0;y<24;y++){
            // This is where the character can either be told to 
                // walk: which is marked with an 'f'
                // teleport inside a room: which is marked with a 'd'
                // or be in a room: which is marked with an 'r'
            if(x == 0 || x == 23){
                if(y >= 3 && y <= 20)
                    board->boxes[y][x].status = 'f';
                if(y == 0 || y == 23)
                    board->boxes[y][x].status = 'r';
                if(y == 2 || y == 21)
                    board->boxes[y][x].status = 'd';}
            if(x == 1 || x == 22)
                if(y >= 3 && y <= 20)
                    board->boxes[y][x].status = 'f';
            if(x == 11 || x == 12)
                if((y >= 2 && y <= 8) || (y >= 15 && y <= 21))
                    board->boxes[y][x].status = 'f';
            if(y == 0 || y == 1 || y == 22 || y == 23)
                if((x >= 3 && x <= 9) || (x >= 14 && x <= 20))
                    board->boxes[y][x].status = 'f';
            if(y == 11 || y == 12)
                if((x >= 2 && x <= 8) || (x >= 15 && x <= 21))
                    board->boxes[y][x].status = 'f';
            if(y == 2 || y == 21)
                if(x == 3 || x == 9 || x == 10 || x == 13 || x == 14 || x == 20)
                    board->boxes[y][x].status = 'f';
            if(y == 3 || y == 20)
                if(x == 2 || x == 3 || x == 20 || x == 21)
                    board->boxes[y][x].status = 'f';
            if(y == 6 || y == 17){
                if((x >= 2 && x <= 4) || (x >= 8 && x <= 15))
                    board->boxes[y][x].status = 'f';
                if(x == 6 || x == 17)
                    board->boxes[y][x].status = 'r';
                if(x == 5 || x == 7 || x == 16)
                    board->boxes[y][x].status = 'd';}
            if(x == 8 || x == 15 || x == 17)
                if(y >= 8 && y <= 15)
                    board->boxes[y][x].status = 'f';
            if(y == 8 || y == 15)
                if(x >= 8 && x <= 15)
                    board->boxes[y][x].status = 'f';
            if(x == 12)
                if(y == 0 || y == 23)
                    board->boxes[y][x].status = 'r';
            if(x == 2 || x == 10 || x == 13 || x == 21)
                if(y == 0 || y == 23)
                    board->boxes[y][x].status = 'd';
            if(x == 17)
                if(y == 7 || y == 16)
                    board->boxes[y][x].status = 'd';
            if(x == 9 || x == 14)
                if(y == 11 || y == 12)
                    board->boxes[y][x].status = 'd';
            if(y == 9 || y == 14)
                if(x == 11 || x == 12)
                    board->boxes[y][x].status = 'd';
            if(x == 12)
                if(y == 12)
                    board->boxes[y][x].status = 'c';
        }
    }
    //MoveCharacter(game, x, y);
    //for(int x=0;x<24;x++){for(int y=0;y<24;y++){if((x == 2 && y == 0) || (x == 0 && y == 2))}}    
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
    player->movesLeft = 0;
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