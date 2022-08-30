#include "PauseMenu.h"
#include "MainWindow.h"

PauseMenu::PauseMenu(wxWindow* parent) : wxPanel(parent) { 
    
    // Sets the min default size for the panel, such that it matches its parent
    this->SetMinSize(parent->GetSize());

    // A sizer such that all the buttons are easily aligned in the vertical direction
    wxBoxSizer* ButtonSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(ButtonSizer);


    // instantiating all properties for the resumebutton
    wxSize ResumeButtonSize = wxSize(200, 50);
    wxString ResumeButtonText = "Resume Game";

    // Instantiate resume game button
    wxButton* ResumeButton = new wxButton(this, wxID_ANY, ResumeButtonText, wxDefaultPosition, ResumeButtonSize);
    // Binding the resume button to the corresponding event handler
    ResumeButton->Bind(wxEVT_BUTTON, &PauseMenu::OnResumeGame, this);

    // instantiating all properties for the settingsbutton
    wxSize SettingsButtonSize = wxSize(200, 50);
    wxString SettingsButtonText = "Settings";

    // Instantiate settings game button
    wxButton* SettingsButton = new wxButton(this, wxID_ANY, SettingsButtonText, wxDefaultPosition, SettingsButtonSize);
    // Binding the settings button to the corresponding event handler
    SettingsButton->Bind(wxEVT_BUTTON, &PauseMenu::OnSettings, this);

    // instantiating all properties for the exitbutton
    wxSize ExitButtonSize = wxSize(200, 50);
    wxString ExitButtonText = "Exit";

    // Instantiate exit button
    wxButton* ExitButton = new wxButton(this, wxID_ANY, ExitButtonText, wxDefaultPosition, ExitButtonSize);
    // Binding the exit button to the corresponding event handler
    ExitButton->Bind(wxEVT_BUTTON, &PauseMenu::OnExit, this);

    // Adding all buttons to the sizer
    ButtonSizer->Add(ResumeButton, 0, wxALIGN_CENTER | wxTOP, 30);
    ButtonSizer->Add(SettingsButton, 0, wxALIGN_CENTER | wxTOP, 30);
    ButtonSizer->Add(ExitButton, 0, wxALIGN_CENTER | wxTOP, 30);

}

// Event handler for going back to the game screen
void PauseMenu::OnResumeGame(wxCommandEvent& event) {
    ((MainWindow*)GetParent())->ShowPanel(MainWindow::Panels::Game);
}
// Event handler for going to the settings menu
void PauseMenu::OnSettings(wxCommandEvent& event) {
    ((MainWindow*)GetParent())->ShowPanel(MainWindow::Panels::Settings);
}
// Event handler for going back to the startmenu
void PauseMenu::OnExit(wxCommandEvent& event) {
    ((MainWindow*)GetParent())->ShowPanel(MainWindow::Panels::Start);
}