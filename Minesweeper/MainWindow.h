#ifndef __HEADER_MAINWINDOW
#define __HEADER_MAINWINDOW
#pragma once
#include <wx/wxprec.h>

class MainWindow : public wxFrame
{
public:
    wxBoxSizer* sizer;

    StartMenu* startMenu;
    PauseMenu* pauseMenu;
    SettingsMenu* settingsMenu;

    MainWindow();

private:
    void OnExit(wxCommandEvent& event);
    void OnKeyDown(wxKeyEvent& event);
};

#endif