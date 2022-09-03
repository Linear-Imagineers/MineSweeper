#include "GameOverScreen.h"
#include <wx/button.h>

GameOverScreen::GameOverScreen(wxWindow* parent) :
	wxPanel(parent) {
	wxString GameOverButtonText = "Ok...";
	wxButton* GameOverButton = new wxButton(this, wxID_ANY, GameOverButtonText, wxDefaultPosition, wxDefaultSize);
}