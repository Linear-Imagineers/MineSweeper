#ifndef __HEADER_MAINWINDOW
#define __HEADER_MAINWINDOW
#pragma once
#include <wx/wxprec.h>

#include "StartMenu.h"
#include "PauseMenu.h"
#include "SettingsMenu.h"
#include "GameScreen.h"
#include <wx/sizer.h>

class MainWindow : public wxFrame
{
public:
    // Enum for swithcing between panels
    enum Panels {
        Start,
        Pause,
        Settings,
        Game,
        Over
    };
    MainWindow();
    // Function for switching between different panels
    void ShowPanel(Panels panel);

private:
    // Main sizer of the frame
    wxBoxSizer* sizer;
    
    // All the panels of the aplication
    PauseMenu* pauseMenu;
    SettingsMenu* settingsMenu;
    StartMenu* startMenu;
    GameScreen* gameScreen;
    GameOverScreen* gameOverScreen;

    // Event handlers
    void OnKeyDown(wxKeyEvent& event);
    void OnExit(wxCommandEvent& event);
};

#endif