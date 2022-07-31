#include "StartMenu.h"

StartMenu::StartMenu(wxWindow* parent) :
    wxPanel(parent)
{
    //Draw all the controlls of the starting menu
        //Adjust settings for new game
        //Create new game
            //switch to new scene (gamescreen)
}

MinesweeperGame StartMenu::startGame()
{
    //Instantiate game (from backend)
    return MinesweeperGame();
}
