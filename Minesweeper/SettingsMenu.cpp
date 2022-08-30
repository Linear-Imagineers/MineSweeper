#include "SettingsMenu.h"
#include <wx/msgdlg.h>
#include "MainWindow.h"

SettingsMenu::SettingsMenu(wxWindow* parent) : wxPanel(parent) {
	// Sets the min default size for the panel, such that it matches its parent
    this->SetMinSize(parent->GetSize());

    // A sizer such that all the buttons are easily aligned in the vertical direction
    wxBoxSizer* ButtonSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(ButtonSizer);

    // Instantiating all properties for the exitbutton
    wxSize ExitButtonSize = wxSize(200, 50);
    wxString ExitButtonText = "Exit";
    // Instantiating all properties for the flag option (right/left click)
    wxSize FlagOptionSize = wxSize(200, 50);
    wxString FlagOptionText = "Flag option";
    // Instantiating all properties for the stats menu
    wxSize StatButtonSize = wxSize(200, 50);
    wxString StatButtonText = "Statistics";

    // TO DO (optional)
    // Make it so that the exit button returns to the last visited screen, instead of going to the start menu by default

    // Instantiate EXIT BUTTON
    wxButton* ExitButton = new wxButton(this, wxID_ANY, ExitButtonText, wxDefaultPosition, ExitButtonSize);
    // Instantiate FLAG OPTION
    wxButton* FlagOption = new wxButton(this, wxID_ANY, FlagOptionText, wxDefaultPosition, FlagOptionSize);
    // Instantiate STATS MENU
    wxButton* StatButton = new wxButton(this, wxID_ANY, StatButtonText, wxDefaultPosition, StatButtonSize);
    
    // Binding the exit button to the corresponding event handler
    ExitButton->Bind(wxEVT_BUTTON, &SettingsMenu::OnExit, this);
    FlagOption->Bind(wxEVT_BUTTON, &SettingsMenu::OnFlagOption, this);
    StatButton->Bind(wxEVT_BUTTON, &SettingsMenu::OnStat, this);


    // Adding all buttons to the sizer
    ButtonSizer->Add(ExitButton, 0, wxALIGN_CENTER | wxTOP, 30);
    ButtonSizer->Add(FlagOption, 0, wxALIGN_CENTER, 30);
    ButtonSizer->Add(StatButton, 0, wxALIGN_CENTER, 30);
}

// Event handler for going back to the start menu
void SettingsMenu::OnExit(wxCommandEvent& event) {
    ((MainWindow*)GetParent())->ShowPanel(MainWindow::Panels::Start);
}

void SettingsMenu::OnFlagOption(wxCommandEvent& event) {
    // Options: right or left-click to flag a tile
}

void SettingsMenu::OnStat(wxCommandEvent& event) {
    ((MainWindow*)GetParent())->ShowPanel(MainWindow::Panels::Statistics);
}
