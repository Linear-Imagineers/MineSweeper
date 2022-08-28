// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
//Other includes
#include "GameScreen.h"

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
};

enum
{
    ID_Hello = 1
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
    : wxFrame(NULL, wxID_ANY, "Hello World", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER)
{
    Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);

    //right now it jumps straight into the game screen
    GameScreen * gameScreen = new GameScreen(this);
    gameScreen->SetFocus();
}

void MainWindow::OnExit(wxCommandEvent& event)
{
    Close(true);
}
