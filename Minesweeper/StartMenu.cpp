#include "StartMenu.h"
#include "GameScreen.h"
#include "SettingsMenu.h"
#include <wx/msgdlg.h>
#include <iostream>

enum {
    StartGameID = 3,
    SettingsID = 4
};

// temporary commented out since otherwise it did not run for me
StartMenu::StartMenu(wxWindow* parent) :
    wxPanel(parent)
{
    // Binds the click event with id PanelId to the startGame function
    Bind(wxEVT_BUTTON, &StartMenu::OnStartGame, this, StartGameID);
    Bind(wxEVT_BUTTON, &StartMenu::OnSettings, this, SettingsID);
    

    // wxPosition object
    wxPoint StartGameButtonPos = wxPoint(100, 50);
    wxSize StartGameButtonSize = wxSize(200, 50);
    wxString StartGameButtonText = "Start Game";

    // Instantiate start game button
    wxButton* StartGameButton = new wxButton(this, StartGameID, StartGameButtonText, StartGameButtonPos, StartGameButtonSize);


    wxPoint SettingsButtonPos = wxPoint(100, 150);
    wxSize SettingsButtonSize = wxSize(200, 50);
    wxString SettingsButtonText = "Settings";

    // Instantiate start game button
    wxButton* SettingsButton = new wxButton(this, SettingsID, SettingsButtonText, SettingsButtonPos, SettingsButtonSize);
    
}

void StartMenu::OnStartGame(wxCommandEvent& event)
{
    //MinesweeperGame* NewGame = new MinesweeperGame(1, true, 10, 10);
    this->Hide();
    GameScreen* gameScreen = new GameScreen(GetParent());
}

void StartMenu::OnSettings(wxCommandEvent& event) {
    this->Hide();
    SettingsMenu* settingsScreen = new SettingsMenu(GetParent());
}

