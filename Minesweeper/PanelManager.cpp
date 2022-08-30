#include "PanelManager.h"

PanelManager::PanelManager(wxWindow* parent) {
    wxPoint StartGameButtonPos = wxPoint(100, 50);
    wxSize StartGameButtonSize = wxSize(200, 50);
    wxString StartGameButtonText = "Start Game";

    // Instantiate start game button
    wxButton* StartGameButton = new wxButton(this, 0, StartGameButtonText, StartGameButtonPos, StartGameButtonSize);
    
    
    sizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(sizer);

    startMenu = new StartMenu(this);
    /*pauseMenu = new PauseMenu(this);
    pauseMenu->Hide();
    settingsMenu = new SettingsMenu(this);
    settingsMenu->Hide();*/

    sizer->Add(startMenu);
    /*sizer->Add(pauseMenu);
    sizer->Add(settingsMenu);*/
    sizer->Layout();
}

void PanelManager::ShowPanel(int iPanel)
{
    sizer->Show(startMenu, iPanel == 0);
    sizer->Show(pauseMenu, iPanel == 1);
    sizer->Show(settingsMenu, iPanel == 2);
    sizer->Layout();
}