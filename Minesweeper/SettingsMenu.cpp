#include "SettingsMenu.h"
#include <wx/msgdlg.h>
#include <wx/button.h>
#include "MainWindow.h"

SettingsMenu::SettingsMenu(wxWindow* parent) : wxPanel(parent) {
	// Sets the min default size for the panel, such that it matches its parent
    this->SetMinSize(parent->GetSize());

    // A sizer such that all the buttons are easily aligned in the vertical direction
    wxBoxSizer* ButtonSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(ButtonSizer);

    // instantiating all properties for the exitbutton
    wxSize ExitButtonSize = wxSize(200, 50);
    wxString ExitButtonText = "Exit";

    // Instantiate exit button
    wxButton* ExitButton = new wxButton(this, wxID_ANY, ExitButtonText, wxDefaultPosition, ExitButtonSize);
    // Binding the exit button to the corresponding event handler
    ExitButton->Bind(wxEVT_BUTTON, &SettingsMenu::OnExit, this);

    // Adding all buttons to the sizer
    ButtonSizer->Add(ExitButton, 0, wxALIGN_CENTER | wxTOP, 30);
}

// Event handler for going back to the start menu
void SettingsMenu::OnExit(wxCommandEvent& event) {
    ((MainWindow*)GetParent())->ShowPanel(MainWindow::Panels::Start);
}