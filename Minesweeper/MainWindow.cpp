// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
//Other includes
#include "GameScreen.h"
#include "StartMenu.h"
#include "PauseMenu.h"
#include "SettingsMenu.h"
//#include "PanelManager.h"
#include "MainWindow.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

enum
{
    ID_Hello = 1
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainWindow* frame = new MainWindow();
    frame->Show(true);
    return true; 
}


MainWindow::MainWindow()
    : wxFrame(NULL, wxID_ANY, "Hello World")
{
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
    //PanelManager* manager = new PanelManager(this);

    Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);
    Bind(wxEVT_CHAR_HOOK, &MainWindow::OnKeyDown, this, wxID_ANY);
}


void MainWindow::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainWindow::OnKeyDown(wxKeyEvent& event) {
    // Checking if esc is pressed
    if (event.GetKeyCode() == 27) {
        wxMessageBox(wxString::Format("Pause Game"));
        event.Skip();
    }
    //wxMessageBox(wxString::Format("KeyDown: %i\n", (int)event.GetKeyCode()));
}
