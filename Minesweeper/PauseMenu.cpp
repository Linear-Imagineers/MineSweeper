#include "PauseMenu.h"

enum {
    SettingsID = 3
};

PauseMenu::PauseMenu(wxWindow* parent) : wxPanel(parent) {
    wxPoint SettingsButtonPos = wxPoint(100, 150);
    wxSize SettingsButtonSize = wxSize(200, 50);
    wxString SettingsButtonText = "Test";

    // Instantiate start game button
    wxButton* SettingsButton = new wxButton(this, SettingsID, SettingsButtonText, SettingsButtonPos, SettingsButtonSize);
	//this->SetBackgroundColour(wxColour(*wxWHITE));
}