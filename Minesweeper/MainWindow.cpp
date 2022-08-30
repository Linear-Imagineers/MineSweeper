// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
//Other includes
#include "GameScreen.h"
#include "MainWindow.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

// TODO improve unhandled exception handling:
//   currently crashes the program, without showing exception message

bool MyApp::OnInit()
{
    MainWindow* frame = new MainWindow();
    frame->Show(true);
    return true; 
}


MainWindow::MainWindow()
    // Disallow frame resizing
    : wxFrame(NULL, wxID_ANY, "MineSweeper", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER)
{
    // Sizer allows for resizing of the frame, controlling which panel can be shown and organization of the buttons
    sizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(sizer);

    // Iniatilizing all the different panels of the aplication
    gameScreen = new GameScreen(this);
    startMenu = new StartMenu(this);
    pauseMenu = new PauseMenu(this);
    settingsMenu = new SettingsMenu(this);
    statisticsMenu = new StatisticsMenu(this);


    // Adding the panels to the sizer, so that we can manage which one is viewed
    sizer->Add(startMenu);
    sizer->Add(pauseMenu);
    sizer->Add(settingsMenu);
    sizer->Add(statisticsMenu);
    sizer->Add(gameScreen);

    // On startup we display the startmenu
    ShowPanel(Start);

    // Binding of events to corresponding functions
    Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);
    Bind(wxEVT_CHAR_HOOK, &MainWindow::OnKeyDown, this, wxID_ANY);
}

// Function which takes an enum, which will display the corresponding panel
void MainWindow::ShowPanel(Panels panel)
{
    // A panel is shown if it matches the second argument of the show function, otherwise it is hidden
    sizer->Show(startMenu, panel == Start);
    sizer->Show(pauseMenu, panel == Pause);
    sizer->Show(settingsMenu, panel == Settings);
    sizer->Show(statisticsMenu, panel == Statistics);
    sizer->Show(gameScreen, panel == Game);
    // Forces new layout on children objects
    sizer->Layout();
}

// Event handler for keyboard presses
void MainWindow::OnKeyDown(wxKeyEvent& event) {
    // Checking if esc is pressed
    if (event.GetKeyCode() == wxKeyCode::WXK_ESCAPE) {
        // Switch to pause menu only if the current shown panel is the gamescreen
        if (gameScreen->IsShown()) {
            ShowPanel(Pause);
        }    
    }
}

// Event handler for exiting the program
void MainWindow::OnExit(wxCommandEvent& event)
{
    Close(true);
}
