#include "StartMenu.h"
#include "GameScreen.h"
#include "SettingsMenu.h"
#include <wx/msgdlg.h>
#include <iostream>
#include "MainWindow.h"

StartMenu::StartMenu(wxWindow* parent) : wxPanel(parent)
{   
    // Sets the min default size for the panel, such that it matches its parent
    this->SetMinSize(parent->GetSize());

    // A sizer such that all the buttons are easily aligned in the vertical direction
    wxBoxSizer* ButtonSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(ButtonSizer);


    // instantiating all properties for the startbutton
    wxSize StartGameButtonSize = wxSize(200, 50);
    wxString StartGameButtonText = "Start Game";

    // Instantiate start game button
    wxButton* StartGameButton = new wxButton(this, wxID_ANY, StartGameButtonText, wxDefaultPosition, StartGameButtonSize);
    // Binding the startbutton to the corresponding event handler
    StartGameButton->Bind(wxEVT_BUTTON, &StartMenu::OnStartGame, this);

    // instantiating all properties for the settingsbutton
    wxSize SettingsButtonSize = wxSize(200, 50);
    wxString SettingsButtonText = "Settings";

    // Instantiate settingsbutton
    wxButton* SettingsButton = new wxButton(this, wxID_ANY, SettingsButtonText, wxDefaultPosition, SettingsButtonSize);
    // Binding the settingsbutton to the corresponding event handler
    SettingsButton->Bind(wxEVT_BUTTON, &StartMenu::OnSettings, this);

    // Adding the buttons to the sizer
    ButtonSizer->Add(StartGameButton, 0, wxALIGN_CENTER | wxTOP, 30);
    ButtonSizer->Add(SettingsButton, 0, wxALIGN_CENTER | wxTOP, 30);
}

// Event handler for starting a game
void StartMenu::OnStartGame(wxCommandEvent& event)
{
    //MinesweeperGame* NewGame = new MinesweeperGame(1, true, 10, 10);
    ((MainWindow*)GetParent())->ShowPanel(MainWindow::Panels::Game);
}

// Event handler for going to the settings menu
void StartMenu::OnSettings(wxCommandEvent& event) {
    ((MainWindow*)GetParent())->ShowPanel(MainWindow::Panels::Settings);
}

