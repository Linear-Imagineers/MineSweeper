// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
//Other includes
#include "GameScreen.h"
#include "StartMenu.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MainWindow : public wxFrame
{
public:
    MainWindow();

private:
    void OnExit(wxCommandEvent& event);
    void OnKeyDown(wxKeyEvent& event);
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
    Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);
    Bind(wxEVT_CHAR_HOOK, &MainWindow::OnKeyDown, this);

    StartMenu* startMenu = new StartMenu(this);
    startMenu->SetFocus();
    //right now it jumps straight into the game screen
    //GameScreen * gameScreen = new GameScreen(this);
    //gameScreen->SetFocus();
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
