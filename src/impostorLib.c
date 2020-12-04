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

    Texture2D logo,menu,black,RL,credits,save,load,newGame,pause,settings,win,lose;
    int btnWidth,btnHeight,btnSpace,btnCenter,btnInitialPosition,btnRowDistance;
    switch (game->resolution){
        case 1:     // Monitor normal
            logo = LoadTexture("./res/animations/1920x1080/Logo.png");
            menu = LoadTexture("./res/animations/1920x1080/Menu.png");
            black = LoadTexture("./res/animations/1920x1080/black.png");
            RL = LoadTexture("./res/animations/1920x1080/raylib_logo.png");
            credits = LoadTexture("./res/animations/1920x1080/Credits.png");
            save = LoadTexture("./res/animations/1920x1080/Save.png");   
            load = LoadTexture("./res/animations/1920x1080/Load.png");
            newGame = LoadTexture("./res/animations/1920x1080/NewGame.png");
            pause = LoadTexture("./res/animations/1920x1080/Pause.png");
            settings = LoadTexture("./res/animations/1920x1080/Settings.png");
            win = LoadTexture("");
            lose = LoadTexture("");
            btnWidth = 460;
            btnHeight = 90;
            btnInitialPosition = 400;
            btnRowDistance = 120;
            break;
        case 2:     // Monitor lap
            logo = LoadTexture("./res/animations/1366x768/Logo.png");
            menu = LoadTexture("./res/animations/1366x768/Menu.png");
            black = LoadTexture("./res/animations/1366x768/black.png");
            RL = LoadTexture("./res/animations/1366x768/raylib_logo.png");
            credits = LoadTexture("./res/animations/1366x768/Credits.png");
            save = LoadTexture("./res/animations/1366x768/Save.png");   
            load = LoadTexture("./res/animations/1366x768/Load.png");
            newGame = LoadTexture("./res/animations/1366x768/NewGame.png");
            pause = LoadTexture("./res/animations/1366x768/Pause.png");
            settings = LoadTexture("./res/animations/1366x768/Settings.png");
            win = LoadTexture("");
            lose = LoadTexture("");
            btnWidth = 450;
            btnHeight = 70;
            break;
        case 3:     // Monitor feo
            logo = LoadTexture("./res/animations/1024x768/Logo.png");
            menu = LoadTexture("./res/animations/1024x768/Menu.png");
            black = LoadTexture("./res/animations/1024x768/black.png");
            RL = LoadTexture("./res/animations/1024x768/raylib_logo.png");
            credits = LoadTexture("./res/animations/1024x768/Credits.png");
            save = LoadTexture("./res/animations/1024x768/Save.png");   
            load = LoadTexture("./res/animations/1024x768/Load.png");
            newGame = LoadTexture("./res/animations/1024x768/NewGame.png");
            pause = LoadTexture("./res/animations/1024x768/Pause.png");
            settings = LoadTexture("./res/animations/1024x768/Settings.png");
            win = LoadTexture("");
            lose = LoadTexture("");
            btnWidth = 450;
            btnHeight = 70;
            break;
        case 4:     // Monitor Mac
            logo = LoadTexture("./res/animations/1280x700/Logo.png");
            menu = LoadTexture("./res/animations/1280x700/Menu.png");
            black = LoadTexture("./res/animations/1280x700/black.png");
            RL = LoadTexture("./res/animations/1280x700/raylib_logo.png");
            credits = LoadTexture("./res/animations/1280x700/Credits.png");
            save = LoadTexture("./res/animations/1280x700/Save.png");   
            load = LoadTexture("./res/animations/1280x700/Load.png");
            newGame = LoadTexture("./res/animations/1280x700/NewGame.png");
            pause = LoadTexture("./res/animations/1280x700/Pause.png");
            settings = LoadTexture("./res/animations/1280x700/Settings.png");
            win = LoadTexture("");
            lose = LoadTexture("");
            btnWidth = 450;
            btnHeight = 70;
            //btnSpace = ;
            //btnCenter = ;
            btnInitialPosition = 280;
            btnRowDistance = 82;
            break;
        default:    // Default normal
            logo = LoadTexture("./res/animations/1920x1080/Logo.png");
            menu = LoadTexture("./res/animations/1920x1080/Menu.png");
            black = LoadTexture("./res/animations/1920x1080/black.png");
            RL = LoadTexture("./res/animations/1920x1080/raylib_logo.png");
            credits = LoadTexture("./res/animations/1920x1080/Credits.png");
            save = LoadTexture("./res/animations/1920x1080/Save.png");   
            load = LoadTexture("./res/animations/1920x1080/Load.png");
            newGame = LoadTexture("./res/animations/1920x1080/NewGame.png");
            pause = LoadTexture("./res/animations/1920x1080/Pause.png");
            settings = LoadTexture("./res/animations/1920x1080/Settings.png");
            win = LoadTexture("");
            lose = LoadTexture("");
            btnWidth = 460;
            btnHeight = 90;
            break;
    }

    
    bool        exitWindow = false;
    bool        showMessageBox = false;
    int         state = 0;
    int         splashCounter = 0;
    int         transCounter = 0; 
    float       alpha = 0.0f;
    
    Music ostMenu = LoadMusicStream("./res/music/ost_menu.mp3");
    Music ostGame = LoadMusicStream("./res/music/ost_game.mp3");
    SetMusicVolume(ostMenu,0.1);
    SetMusicVolume(ostGame,0.1);
    PlayMusicStream(ostMenu);
    float timePlayed = 0.0f;
    int musicFlag = 0;

    int resActive = 0;
    bool resEditMode = false;
    int volumeLevel = 60;   
    
    while (!exitWindow){
        exitWindow = WindowShouldClose();
        if (IsKeyPressed(KEY_ESCAPE)) showMessageBox = !showMessageBox;

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
                            DrawTexture(black,0,0,Fade(BLACK,alpha));
                            break;
                        case 1 :
                            DrawTexture(logo,0,0,RAYWHITE);
                            break;
                        case 2 : 
                            DrawTexture(black,0,0,BLACK);
                            break;
                    }
                    break;
                case POWERED:
                    switch(state){
                        case 1 :
                            DrawTexture(RL,0,0,RAYWHITE);
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
                                (game->screenCenterWidth/2)-150, 
                                //game->screenCenterWidth/2,  
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
                    //game->screenCenterWidth-225, 280, btnWidth, btnHeight
                    //(btnInitialPosicion)+(0)(btnRowDistance)
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, btnInitialPosition, btnWidth, btnHeight}, "New Game")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 410, 460, 90 }, "New Game")) { 
                        fprintf(stdout,"New Game\n"); 
                        gameScene = NEWGAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 362, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(1*btnRowDistance), btnWidth, btnHeight }, "Load Game")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 530, 460, 90 }, "Load Game")) {
                        fprintf(stdout,"Load Game\n");
                        gameScene = LOADGAME;
                        state = 0; 
                    }
                    //game->screenCenterWidth-225, 444, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(2*btnRowDistance), btnWidth, btnHeight }, "Settings")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 650, 460, 90 }, "Settings")) {
                        fprintf(stdout,"Settings\n"); 
                        gameScene = SETTINGS;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 526, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(3*btnRowDistance), btnWidth, btnHeight }, "Credits")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 770, 460, 90 }, "Credits")) { 
                        fprintf(stdout,"Credits\n"); 
                        gameScene = CREDITS;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Exit")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 890, 460, 90 }, "Exit")) { 
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
                        MovementInBoard(game);
                        //fprintf(stdout,"x=[%f] y=[%f]||x=[%d] y=[%d]\n",game->board->camera.target.x,game->board->camera.target.y,(int)((game->board->camera.target.x)*.5),(int)((game->board->camera.target.y)*1.1));
                        
                        //
                        //
                        int initXHUD = (int)((game->board->camera.target.x)-960);
                        
                        //
                        //
                        int initYHUD = (int)((game->board->camera.target.y)+270);
                        DrawRectangle(
                            initXHUD,
                            initYHUD,
                            game->screenWidth,
                            game->screenHeight/4,
                            DARKGRAY
                        );    
                        GuiGroupBox((Rectangle){ initXHUD + 25, initYHUD + 30, 125, 150 }, "OPTIONS");
                        if (GuiButton((Rectangle){ initXHUD + 30, initYHUD + 40, 115, 30 }, "Tirar Dado")) {
                            fprintf(stdout,"Hola");
                        }
                        if (GuiButton((Rectangle){ initXHUD + 30, initYHUD + 75, 115, 30 }, "Suggest")) { 
                            fprintf(stdout,"Hola");

                        }
                        if (GuiButton((Rectangle){ initXHUD + 30, initYHUD + 110, 115, 30 }, "Notebook")) {
                            fprintf(stdout,"Hola");

                        }
                    EndMode2D();
                    
                    break;
                case PAUSE:
                    DrawTexture(pause,0, 0,RAYWHITE);
                    //game->screenCenterWidth-225, 198, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)-(1*btnRowDistance), btnWidth, btnHeight }, "Quit Current Game")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 290, 460, 90 }, "Quit Current Game")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 280, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, btnInitialPosition, btnWidth, btnHeight }, "Save Game")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 410, 460, 90 }, "Save Game")) {
                        fprintf(stdout,"Save Game\n");
                        gameScene = SAVEGAME;
                        state = 0; 
                    }
                    //game->screenCenterWidth-225, 362, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(1*btnRowDistance), btnWidth, btnHeight }, "Load Game")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 530, 460, 90 }, "Load Game")) {
                        fprintf(stdout,"Load Game\n"); 
                        gameScene = LOADGAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 444, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(2*btnRowDistance), btnWidth, btnHeight }, "Settings")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 650, 460, 90 }, "Settings")) { 
                        fprintf(stdout,"Settings\n"); 
                        gameScene = SETTINGS;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 526, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(3*btnRowDistance), btnWidth, btnHeight }, "Restart")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 770, 460, 90 }, "Restart")) { 
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Cancel")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 890, 460, 90 }, "Cancel")) { 
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
                    DrawTexture(newGame,0, 0,RAYWHITE);
                    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    //game->screenCenterWidth-350, 290, 200, 40
                    //if (GuiTextBox((Rectangle){ game->screenCenterWidth-350, 290, 200, 40 }, game->nameTB[0], 30, game->nameEditMode[0])){
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

                    //game->screenCenterWidth+19, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Return to Menu")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth+20, 890, 460, 90 }, "Return to Menu")) {
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    //game->screenCenterWidth-465, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Begin Game")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-500, 890, 460, 90 }, "Begin Game")) {
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
                    DrawTexture(load,0, 0,RAYWHITE);
                    //game->screenCenterWidth-225, 280, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, btnInitialPosition, btnWidth, btnHeight }, "Slot 1")) {  
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 410, 460, 90 }, "Slot 1")) {  
                        fprintf(stdout,"Slot 1\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 362, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(1*btnRowDistance), btnWidth, btnHeight }, "Slot 2")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 530, 460, 90 }, "Slot 2")) {
                        fprintf(stdout,"Slot 2\n");
                        gameScene = GAME;
                        state = 0; 
                    }
                    //game->screenCenterWidth-225, 444, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(2*btnRowDistance), btnWidth, btnHeight }, "Slot 3")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 650, 460, 90 }, "Slot 3")) { 
                        fprintf(stdout,"Slot 3\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth+19, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Return to Menu")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth+20, 890, 460, 90 }, "Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    //game->screenCenterWidth-465, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Exit Game")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-500, 890, 460, 90 }, "Exit Game")) {
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    break;
                case SAVEGAME:
                    DrawTexture(save,0, 0,RAYWHITE);
                    //game->screenCenterWidth-225, 280, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, btnInitialPosition, btnWidth, btnHeight }, "Slot 1")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 410, 460, 90 }, "Slot 1")) { 
                        fprintf(stdout,"Slot 1\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth-225, 362, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(1*btnRowDistance), btnWidth, btnHeight }, "Slot 2")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 530, 460, 90 }, "Slot 2")) { 
                        fprintf(stdout,"Slot 2\n");
                        gameScene = GAME;
                        state = 0; 
                    }
                    //game->screenCenterWidth-225, 444, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-225, (btnInitialPosition)+(2*btnRowDistance), btnWidth, btnHeight }, "Slot 3")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-230, 650, 460, 90 }, "Slot 3")) { 
                        fprintf(stdout,"Slot 3\n"); 
                        gameScene = GAME;
                        state = 0;
                    }
                    //game->screenCenterWidth+19, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Return to Menu")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth+20, 890, 460, 90 }, "Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    //game->screenCenterWidth-465, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Exit Game")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-500, 890, 460, 90 }, "Exit Game")) {
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    break;
                case SETTINGS:
                    DrawTexture(settings,0, 0,RAYWHITE);

                    //game->screenCenterWidth-225, 340, btnWidth, 50
                    volumeLevel = GuiSliderBar((Rectangle){ game->screenCenterWidth-225, 340, btnWidth, 50 }, "Volume", TextFormat("%i", (int)volumeLevel), volumeLevel, 0, 100);
                    //volumeLevel = GuiSliderBar((Rectangle){ game->screenCenterWidth-230, 510, 460, 50 }, "Volume", TextFormat("%i", (int)volumeLevel), volumeLevel, 0, 100);
                    
                    SetMusicVolume(ostMenu,volumeLevel/100);
                    SetMusicVolume(ostGame,volumeLevel/100);
                    
                    //game->screenCenterWidth+19, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Return to Menu")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth+20, 890, 460, 90 }, "Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                        StopMusicStream(ostMenu);
                        PlayMusicStream(ostMenu);
                    }
                    //game->screenCenterWidth-465, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Exit Game")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-500, 890, 460, 90 }, "Exit Game")) {
                        fprintf(stdout,"Exit\n"); 
                        gameScene = THANKS;
                        state = 0;
                    }
                    GuiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
                    //game->screenCenterWidth-225, 280, 130, 50
                    if (GuiDropdownBox((Rectangle){ game->screenCenterWidth-225, 280, 130, 50 },"#01#1920x1080;#02#1366x768;#03#1024x768;#04#1280x700",&resActive,resEditMode)){
                    //if (GuiDropdownBox((Rectangle){ game->screenCenterWidth-230, 410, 125, 50 },"#01#1920x1080;#02#1366x768;#03#1024x768;#04#1280x700",&resActive,resEditMode)){
                        resEditMode = !resEditMode;
                        fprintf(stdout,"Resolution: %d\n",resActive);
                        //Actualizar Resolution settings 
                    }
                    break;

                case CREDITS:
                    DrawTexture(credits,0, 0,RAYWHITE);
                    //game->screenCenterWidth+19, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth+19, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Return to Menu")) { 
                    //if (GuiButton((Rectangle){ game->screenCenterWidth+20, 890, 460, 90 }, "Return to Menu")) { 
                        fprintf(stdout,"Menu\n"); 
                        gameScene = MENU;
                        state = 0;
                    }
                    //game->screenCenterWidth-465, 608, btnWidth, btnHeight
                    if (GuiButton((Rectangle){ game->screenCenterWidth-465, (btnInitialPosition)+(4*btnRowDistance), btnWidth, btnHeight }, "Exit Game")) {
                    //if (GuiButton((Rectangle){ game->screenCenterWidth-500, 890, 460, 90 }, "Exit Game")) {
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
                                (game->screenCenterWidth/2)+100,
                                //(game->screenCenterWidth/4)*3, 
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
                    exitWindow = true;
                    break;
                default:
                    break;
            }
            if (showMessageBox){
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(RAYWHITE, 0.8f));
                //GetScreenWidth()/2 - 125, GetScreenHeight()/2 - 40, 400, 100
                int result = GuiMessageBox((Rectangle){ GetScreenWidth()/2 - 200, GetScreenHeight()/2 - 50, 400, 100 }, GuiIconText(RICON_EXIT, "Close Window"), "Do you really want to exit?", "Yes;No"); 
                //int result = GuiMessageBox((Rectangle){ GetScreenWidth()/2 - 125, GetScreenHeight()/2 - 50, 400, 100 }, GuiIconText(RICON_EXIT, "Close Window"), "Do you really want to exit?", "Yes;No"); 
            
                if ((result == 0) || (result == 2)) showMessageBox = false;
                else if (result == 1) gameScene = THANKS;
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
    srand(time(NULL));    
    game->board = NewBoard(game);
    newPlayerList(game);
    InitCamera(game);
    game->envelope = calloc(3, sizeof(struct Card_struct));
    initializeCards(game);
    //printPlayersAndCards(game);
}
GameState newImpostorGame(){
    GameState game = malloc(sizeof(struct ImpostorGame));
    game->resolution = 1;
    switch(game->resolution){
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
    for(int i=0;i<6;i++){
        game->typeTBActive[i] = 1;
        game->typeTBEditMode[i] = false;
        game->nameTB[i] = "Ingrese nombre";
        game->nameEditMode[i] = false; 
    }
    
    game->colorTB[0] = "Blue";
    game->colorTB[1] = "Green";
    game->colorTB[2] = "Purple";
    game->colorTB[3] = "Red";
    game->colorTB[4] = "White";
    game->colorTB[5] = "Yellow";
    InitWindow(game->screenWidth, game->screenHeight, "raylib");
    SetExitKey(0);
    SetTargetFPS(game->fps);
    InitAudioDevice();
    return game;
}
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
    /**
     * This is where the character can either be told to
     * walk: which is marked with an 'f'
     * teleport inside a room: which is marked with a 'd'
     * or be in a room: which is marked with an 'r'
     */
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

