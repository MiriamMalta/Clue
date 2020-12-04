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
#undef RAYGUI_IMPLEMENTATION

/**
 * The main canvas of the game, is divided by:
 * - The initialization part
 * - The music & transitions loop part
 * - The GUI & logic loop part
 */
void playImpostor(GameState game){
    GuiLoadStyle("./res/styles/impostor/impostor.rgs");
    GameScreen  gameScene = LOGO;
    ScreenRes sRes;
    
    bool        exitWindow = false;
    bool        showMessageBox = false;
    int         state = 0;
    int         splashCounter = 0;
    int         transCounter = 0; 
    float       alpha = 0.0f;
    
    Music ostMenu = LoadMusicStream("./res/music/ost_menu.mp3");
    Music ostGame = LoadMusicStream("./res/music/ost_game.mp3");
    SetMusicVolume(ostMenu,game->volume/100);
    SetMusicVolume(ostGame,game->volume/100);
    PlayMusicStream(ostMenu);
    float timePlayed = 0.0f;
    int musicFlag = 0;

    int resActive = 0;
    bool resEditMode = false; 
    
    // Main Loop
    while (!exitWindow){
        exitWindow = WindowShouldClose();
        if (IsKeyPressed(KEY_ESCAPE)) showMessageBox = !showMessageBox;

        splashCounter +=4;
        transCounter ++;
        // Transitions & calculus part
        switch (gameScene){
            case LOGO:
                if(state == 0) {
                    if(alpha<1.0)alpha += 0.05;
                    else state = 1;
                }
                else if (state == 1){
                    alpha = 1.0;
                    if(transCounter % 200==0) state = 2;
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
                    if(transCounter % 200==0) state = 2;
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
                    if(transCounter % 200==0) state = 2;
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
            case WIN:
                break;
            case LOSE:
                break;
            case PAUSE:
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
            case LOADGAME:
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

            case SETTINGS:
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

            case CREDITS:
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

            case GREETIGS:
                break;

            case THANKS:
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
                        CloseAudioDevice();
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
            if(resEditMode) GuiLock;
            switch (gameScene){
                case LOGO:
                    switch(state){
                        case 0 : 
                            DrawTexture(game->screens[sBLACK],0,0,Fade(BLACK,alpha));
                            break;
                        case 1 :
                            DrawTexture(game->screens[sLOGO],0,0,RAYWHITE);
                            break;
                        case 2 : 
                            DrawTexture(game->screens[sBLACK],0,0,BLACK);
                            break;
                    }
                    break;
                case POWERED:
                    switch(state){
                        case 1 :
                            DrawTexture(game->screens[sRAYLOGO],0,0,RAYWHITE);
                            break;
                        case 2 :
                            DrawTexture(game->screens[sBLACK],0,0,Fade(BLACK,alpha));
                            break;
                    }
                    break;
                case DISCLAIMER:
                    switch(state){
                        case 0 : 
                            DrawTexture(game->screens[sBLACK],0,0,Fade(BLACK,alpha));
                            break;
                        case 1 :
                            DrawTexture(game->screens[sBLACK],0,0,BLACK);
                            DrawText(
                                "This Game is for Educational purposes. No nos demanden pliz.", 
                                (game->screenCenterWidth/2)-150,
                                game->screenCenterHeight, 
                                30, 
                                WHITE
                            );
                            break;
                        case 2 :
                            DrawTexture(game->screens[sBLACK],0,0,Fade(BLACK,alpha));
                            break;
                    }
                    break;
                case MENU:
                    DrawTexture(game->screens[sMENU],0, 0,RAYWHITE);
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, game->btnInitialPosition, game->btnWidth, game->btnHeight}, "New Game")) { 
                        fprintf(stdout,"New Game\n"); 
                        gameScene = NEWGAME;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(1*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Load Game")) {
                        fprintf(stdout,"Load Game\n");
                        gameScene = LOADGAME;
                        state = 0; 
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(2*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Settings")) {
                        fprintf(stdout,"Settings\n"); 
                        gameScene = SETTINGS;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(3*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Credits")) { 
                        fprintf(stdout,"Credits\n"); 
                        gameScene = CREDITS;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Exit")) { 
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    break;
                case GAME:
                    if(IsKeyPressed(KEY_P)){
                        fprintf(stdout,"Si jala\n");    
                        gameScene = PAUSE;
                        state = 0;
                    }
                    BeginMode2D(game->board->camera);
                        DrawTexture(game->board->mapBackground, 0, 0, WHITE);
                        DrawTexture(game->board->map, 0, 0, WHITE);
                        int initXHUD = (int)((game->board->camera.target.x)-960);
                        int initYHUD = (int)((game->board->camera.target.y)+270);

                        MovementInBoard(game);
                    EndMode2D();
                    int offset = game->screenHeight - 200;
                    DrawRectangle(
                            0,
                            offset,
                            game->screenWidth,
                            game->screenHeight/4,
                            DARKGRAY
                    );

                    GuiGroupBox((Rectangle){ 10, offset + 10, 125, 150 }, "OPTIONS");
                    if (GuiButton((Rectangle){ 15, offset + 20, 115, 30 }, "Tirar Dado")) {
                        fprintf(stdout,"Hola");
                    }
                    if (GuiButton((Rectangle){ 15, offset + 55, 115, 30 }, "Suggest")) {
                        fprintf(stdout,"Hola");

                    }
                    if (GuiButton((Rectangle){ 15, offset + 95, 115, 30 }, "Notebook")) {
                        fprintf(stdout,"Hola");
                    }
                    break;
                case PAUSE:
                    DrawTexture(game->screens[sPAUSE],0, 0,RAYWHITE);
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)-(1*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Quit Current Game")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, game->btnInitialPosition, game->btnWidth, game->btnHeight }, "Save Game")) {
                        fprintf(stdout,"Save Game\n");
                        gameScene = SAVEGAME;
                        state = 0; 
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(1*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Load Game")) {
                        fprintf(stdout,"Load Game\n"); 
                        gameScene = LOADGAME;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(2*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Settings")) { 
                        fprintf(stdout,"Settings\n"); 
                        gameScene = SETTINGS;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(3*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Restart")) { 
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Cancel")) { 
                        fprintf(stdout,"GAME\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    break;
                case WIN:
                    break;
                case LOSE:
                    break;
                case NEWGAME:
                    DrawTexture(game->screens[sNEWGAME],0, 0,RAYWHITE);
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-500, 290, 200, 40 }, game->nameTB[0], 30, game->nameEditMode[0])){
                        game->nameEditMode[0] = !game->nameEditMode[0];
                        fprintf(stdout,"%s\n",game->nameTB[0]);
                    }
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-500, 335, 200, 40 }, game->nameTB[1], 30, game->nameEditMode[1])){
                        game->nameEditMode[1] = !game->nameEditMode[1];
                        fprintf(stdout,"%s\n",game->nameTB[1]);
                    }
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-500, 380, 200, 40 }, game->nameTB[2], 30, game->nameEditMode[2])){
                        game->nameEditMode[2] = !game->nameEditMode[2];
                        fprintf(stdout,"%s\n",game->nameTB[2]);
                    }
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-500, 425, 200, 40 }, game->nameTB[3], 30, game->nameEditMode[3])){
                        game->nameEditMode[3] = !game->nameEditMode[3];
                        fprintf(stdout,"%s\n",game->nameTB[3]);
                    }
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-500, 470, 200, 40 }, game->nameTB[4], 30, game->nameEditMode[4])){
                        game->nameEditMode[4] = !game->nameEditMode[4];
                        fprintf(stdout,"%s\n",game->nameTB[4]);
                    }
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-500, 515, 200, 40 }, game->nameTB[5], 30, game->nameEditMode[5])){
                        game->nameEditMode[5] = !game->nameEditMode[5];
                        fprintf(stdout,"%s\n",game->nameTB[5]);
                    }
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-250, 290, 200, 40 }, game->colorTB[0], 30, false)){}
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-250, 335, 200, 40 }, game->colorTB[1], 30, false)){}
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-250, 380, 200, 40 }, game->colorTB[2], 30, false)){}
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-250, 425, 200, 40 }, game->colorTB[3], 30, false)){}
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-250, 470, 200, 40 }, game->colorTB[4], 30, false)){}
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiTextBox((Rectangle){ game->screenCenterWidth-250, 515, 200, 40 }, game->colorTB[5], 30, false)){}
                    
                    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiDropdownBox((Rectangle){ game->screenCenterWidth, 515, 200, 40 }, "#01#PLAYER;#02#COMPUTER;#03#NONE", &game->typeTBActive[5], game->typeTBEditMode[5])){
                        game->typeTBEditMode[5] = !game->typeTBEditMode[5];
                        fprintf(stdout,"%d\n",game->typeTBActive[5]);
                    } 
                    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiDropdownBox((Rectangle){ game->screenCenterWidth, 470, 200, 40 }, "#01#PLAYER;#02#COMPUTER;#03#NONE", &game->typeTBActive[4], game->typeTBEditMode[4])){
                        game->typeTBEditMode[4] = !game->typeTBEditMode[4];
                        fprintf(stdout,"%d\n",game->typeTBActive[4]);
                    } 
                    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiDropdownBox((Rectangle){ game->screenCenterWidth, 425, 200, 40 }, "#01#PLAYER;#02#COMPUTER;#03#NONE", &game->typeTBActive[3], game->typeTBEditMode[3])){
                        game->typeTBEditMode[3] = !game->typeTBEditMode[3];
                        fprintf(stdout,"%d\n",game->typeTBActive[3]);
                    } 
                    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiDropdownBox((Rectangle){ game->screenCenterWidth, 380, 200, 40 }, "#01#PLAYER;#02#COMPUTER;#03#NONE", &game->typeTBActive[2], game->typeTBEditMode[2])){
                        game->typeTBEditMode[2] = !game->typeTBEditMode[2];
                        fprintf(stdout,"%d\n",game->typeTBActive[2]);
                    } 
                    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiDropdownBox((Rectangle){ game->screenCenterWidth, 335, 200, 40 }, "#01#PLAYER;#02#COMPUTER;#03#NONE", &game->typeTBActive[1], game->typeTBEditMode[1])){
                        game->typeTBEditMode[1] = !game->typeTBEditMode[1];
                        fprintf(stdout,"%d\n",game->typeTBActive[1]);
                    } 
                    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiDropdownBox((Rectangle){ game->screenCenterWidth, 290, 200, 40 }, "#01#PLAYER;#02#COMPUTER;#03#NONE", &game->typeTBActive[0], game->typeTBEditMode[0])){
                        game->typeTBEditMode[0] = !game->typeTBEditMode[0];
                        fprintf(stdout,"%d\n",game->typeTBActive[0]);
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Begin Game")) {
                        fprintf(stdout,"Game\n"); 
                        UnloadMusicStream(ostMenu);
                        PlayMusicStream(ostGame);
                        musicFlag = 0;
                        timePlayed = 0.0;
                        gameScene = GAME;
                        state = 0;
                        initImpostor(game);
                    }
                    break;

                case LOADGAME:
                    DrawTexture(game->screens[sLOAD],0, 0,RAYWHITE);
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, game->btnInitialPosition, game->btnWidth, game->btnHeight }, "Slot 1")) {  
                        fprintf(stdout,"Slot 1\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(1*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Slot 2")) {
                        fprintf(stdout,"Slot 2\n");
                        gameScene = GAME;
                        state = 0; 
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(2*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Slot 3")) { 
                        fprintf(stdout,"Slot 3\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Exit Game")) {
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    break;
                case SAVEGAME:
                    DrawTexture(game->screens[sSAVE],0, 0,RAYWHITE);
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, game->btnInitialPosition, game->btnWidth, game->btnHeight }, "Slot 1")) {
                        fprintf(stdout,"Slot 1\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(1*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Slot 2")) { 
                        fprintf(stdout,"Slot 2\n");
                        gameScene = GAME;
                        state = 0; 
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-game->btnCenter, (game->btnInitialPosition)+(2*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Slot 3")) { 
                        fprintf(stdout,"Slot 3\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Exit Game")) {
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    break;
                case SETTINGS:
                    DrawTexture(game->screens[sSETTINGS],0, 0,RAYWHITE);

                    game->volume = GuiSliderBar((Rectangle){ game->screenCenterWidth-225, 340, game->btnWidth, 50 }, "Volume", TextFormat("%i", (int)game->volume), game->volume, 0, 100);
                    
                    SetMusicVolume(ostMenu,game->volume/100);
                    SetMusicVolume(ostGame,game->volume/100);
                    
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Save & Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        SaveSettings(game);
                        gameScene = MENU;
                        state = 0;
                        StopMusicStream(ostMenu);
                        PlayMusicStream(ostMenu);
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Exit Game")) {
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    if (GuiDropdownBox((Rectangle){ game->screenCenterWidth-225, 280, 130, 50 },"#01#1920x1080;#02#1366x768;#03#1024x768;#04#1280x700",&resActive,resEditMode)){
                        resEditMode = !resEditMode;
                        fprintf(stdout,"Resolution: %d\n",resActive);
                        game->resolution = resActive;
                    }
                    break;

                case CREDITS:
                    DrawTexture(game->screens[sCREDITS],0, 0,RAYWHITE);
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (game->btnInitialPosition)+(4*game->btnRowDistance), game->btnWidth, game->btnHeight }, "Exit Game")) {
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
                            DrawTexture(game->screens[sBLACK],0,0,Fade(BLACK,alpha));
                            break;
                        case 1 :
                            DrawTexture(game->screens[sBLACK],0,0,BLACK);
                            DrawText(
                                "Gracias por jugar esta basura.", 
                                (game->screenCenterWidth/2)+100,
                                game->screenCenterHeight, 
                                30, 
                                WHITE
                            );
                            break;
                        case 2 :
                            DrawTexture(game->screens[sBLACK],0,0,Fade(BLACK,alpha));
                            break;
                    }
                    break;
                case EXIT:
                    exitWindow = true;
                    break;
                default:
                    break;
            }
            if (showMessageBox){
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(RAYWHITE, 0.8f));
                int result = GuiMessageBox((Rectangle){ GetScreenWidth()/2 - 200, GetScreenHeight()/2 - 50, 400, 100 }, GuiIconText(RICON_EXIT, "Close Window"), "Do you really want to exit?", "Yes;No"); 
                
                if ((result == 0) || (result == 2)) showMessageBox = false;
                else if (result == 1) gameScene = THANKS;
            }
        EndDrawing();
    }
    
}

/**
 * Free the dynamic global data and close the game
 */
void endImpostor(GameState game){
    free(game->board);
    free(game->playerInTurn);
    free(game);
    CloseWindow();
}
/**
 * Initilize the data for the Impostor Game.
 */
void initImpostor(GameState game){
    srand(time(NULL));    
    game->board = NewBoard(game);
    newPlayerList(game);
    InitCamera(game);
    game->envelope = calloc(3, sizeof(struct Card_struct));
    initializeCards(game);
}

/**
 * Initialization of the Window and the assets. Here:
 * - Load the saved Settings
 * - Load the resources
 * - Adjust the resolution
 * - Initialize the Audio
 * - Set the information Layer of the elements
 */
GameState newImpostorGame(){
    GameState game = malloc(sizeof(struct ImpostorGame));
    ScreenRes sRes;
    
    LoadSettings(game);

    switch(game->resolution){
        case 0:     // Monitor normal
            game->screenWidth = 1920;
            game->screenHeight = 1080;
            break;
        case 1:     // Monitor lap
            game->screenWidth = 1366;
            game->screenHeight = 768;
            break;
        case 2:     // Monitor feo
            game->screenWidth = 1024;
            game->screenHeight = 768;
            break;
        case 3:     // Monitor Mac
            game->screenWidth = 1280;
            game->screenHeight = 700;
            break;
    }
    game->fps = 60;
    game->screenCenterWidth = (int)game->screenWidth/2;
    game->screenCenterHeight = (int)game->screenHeight/2;
    InitWindow(game->screenWidth, game->screenHeight, "raylib");
    SetExitKey(0);
    SetTargetFPS(game->fps);
    InitAudioDevice();
    switch (game->resolution){
        case 0:     // Monitor normal
            game->screens[sLOGO] = LoadTexture("./res/animations/1920x1080/Logo.png");
            game->screens[sMENU] = LoadTexture("./res/animations/1920x1080/Menu.png");
            game->screens[sBLACK] = LoadTexture("./res/animations/1920x1080/black.png");
            game->screens[sRAYLOGO] = LoadTexture("./res/animations/1920x1080/raylib_logo.png");
            game->screens[sCREDITS] = LoadTexture("./res/animations/1920x1080/Credits.png");
            game->screens[sSAVE] = LoadTexture("./res/animations/1920x1080/Save.png");   
            game->screens[sLOAD] = LoadTexture("./res/animations/1920x1080/Load.png");
            game->screens[sNEWGAME] = LoadTexture("./res/animations/1920x1080/NewGame.png");
            game->screens[sPAUSE] = LoadTexture("./res/animations/1920x1080/Pause.png");
            game->screens[sSETTINGS] = LoadTexture("./res/animations/1920x1080/Settings.png");
            game->btnWidth = 460;
            game->btnHeight = 90;
            game->btnInitialPosition = 400;
            game->btnRowDistance = 120;
            game->btnCenter = (int)game->btnWidth/2;
            break;
        case 1:     // Monitor lap
            game->screens[sLOGO] = LoadTexture("./res/animations/1366x768/Logo.png");
            game->screens[sMENU] = LoadTexture("./res/animations/1366x768/Menu.png");
            game->screens[sBLACK] = LoadTexture("./res/animations/1366x768/black.png");
            game->screens[sRAYLOGO] = LoadTexture("./res/animations/1366x768/raylib_logo.png");
            game->screens[sCREDITS] = LoadTexture("./res/animations/1366x768/Credits.png");
            game->screens[sSAVE] = LoadTexture("./res/animations/1366x768/Save.png");   
            game->screens[sLOAD] = LoadTexture("./res/animations/1366x768/Load.png");
            game->screens[sNEWGAME] = LoadTexture("./res/animations/1366x768/NewGame.png");
            game->screens[sPAUSE] = LoadTexture("./res/animations/1366x768/Pause.png");
            game->screens[sSETTINGS] = LoadTexture("./res/animations/1366x768/Settings.png");
            game->btnWidth = 450;
            game->btnHeight = 70;
            game->btnInitialPosition = 290;
            game->btnRowDistance = 90;
            game->btnCenter = (int)game->btnWidth/2;
            break;
        case 2:     // Monitor feo
            game->screens[sLOGO] = LoadTexture("./res/animations/1024x768/Logo.png");
            game->screens[sMENU] = LoadTexture("./res/animations/1024x768/Menu.png");
            game->screens[sBLACK] = LoadTexture("./res/animations/1024x768/black.png");
            game->screens[sRAYLOGO] = LoadTexture("./res/animations/1024x768/raylib_logo.png");
            game->screens[sCREDITS] = LoadTexture("./res/animations/1024x768/Credits.png");
            game->screens[sSAVE] = LoadTexture("./res/animations/1024x768/Save.png");   
            game->screens[sLOAD] = LoadTexture("./res/animations/1024x768/Load.png");
            game->screens[sNEWGAME] = LoadTexture("./res/animations/1024x768/NewGame.png");
            game->screens[sPAUSE] = LoadTexture("./res/animations/1024x768/Pause.png");
            game->screens[sSETTINGS] = LoadTexture("./res/animations/1024x768/Settings.png");
            game->btnWidth = 450;
            game->btnHeight = 70;
            game->btnInitialPosition = 290;
            game->btnRowDistance = 90;
            game->btnCenter = (int)game->btnWidth/2;
            break;
        case 3:     // Monitor Mac
            game->screens[sLOGO] = LoadTexture("./res/animations/1280x700/Logo.png");
            game->screens[sMENU] = LoadTexture("./res/animations/1280x700/Menu.png");
            game->screens[sBLACK] = LoadTexture("./res/animations/1280x700/black.png");
            game->screens[sRAYLOGO] = LoadTexture("./res/animations/1280x700/raylib_logo.png");
            game->screens[sCREDITS] = LoadTexture("./res/animations/1280x700/Credits.png");
            game->screens[sSAVE] = LoadTexture("./res/animations/1280x700/Save.png");   
            game->screens[sLOAD] = LoadTexture("./res/animations/1280x700/Load.png");
            game->screens[sNEWGAME] = LoadTexture("./res/animations/1280x700/NewGame.png");
            game->screens[sPAUSE] = LoadTexture("./res/animations/1280x700/Pause.png");
            game->screens[sSETTINGS] = LoadTexture("./res/animations/1280x700/Settings.png");
            game->btnWidth = 450;
            game->btnHeight = 70;
            game->btnInitialPosition = 280;
            game->btnRowDistance = 82;
            game->btnCenter = (int)game->btnWidth/2;
            break;
    }
    game->playersAlive = 0;
    for(int i=0;i<6;i++){
        game->typeTBActive[i] = 0;
        game->typeTBEditMode[i] = false;
        memset(game->nameTB[i], 0, 50);
        strcpy(game->nameTB[i], "Ingrese nombre");
        game->nameEditMode[i] = false; 
    }
    game->colorTB[0] = "Blue";
    game->colorTB[1] = "Green";
    game->colorTB[2] = "Purple";
    game->colorTB[3] = "Red";
    game->colorTB[4] = "White";
    game->colorTB[5] = "Yellow";
    return game;
}

/**
 * Initialization of the board and the boxes
 * 
 * - means unavailable
 * f means free
 * r means room
 * d means door
 * 
 */
Board NewBoard(GameState game){
    Board board = malloc(sizeof(struct BoardGame));
    board->mapBackground = LoadTexture("./res/assets/map/Space.png");
    board->map = LoadTexture("./res/assets/map/Board.png");
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
    return board;
}

/**
 * Initialization of one Player
 * game     ->  Context of the game
 * color    ->  Color of the new player
 */
Player newPlayer(GameState game,char* color){
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
    player->x = CalculateRandomPlacements();
    player->y = 8;
    player->position = game->board->boxes[player->x][player->y].tilePosition;
    return player;
}

