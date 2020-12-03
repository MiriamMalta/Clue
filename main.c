/*******************************************************************************************
*
*   Impostor is a Among Us flavored Clue game
*
*   Welcome!
*
*   To compile the game:
*   
*   Copyright (c) 2020 Miriam Malta (@MiliGuagu) and Ricardo Navarro (@Darksw20)
*
********************************************************************************************/

#include <stdio.h>
#include "src/impostorLib.h"
#include "src/test.h"

int main(){
    DoTests();
    GameState game = newImpostorGame();
    playImpostor(game);
    endImpostor(game);
    return 0;
}