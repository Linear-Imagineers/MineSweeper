#include "GameScreen.h"

GameScreen::GameScreen(wxWindow * parent) :
	wxPanel(parent)
{
	//quick lil test
	int buttonSize = 30;
	parent->SetSize(buttonSize*11, buttonSize*12);
	wxButton* buttons[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			wxPoint pos = wxPoint(i * buttonSize, j * buttonSize);
			wxSize size = wxSize(buttonSize, buttonSize);

			wxButton* button = new wxButton(this, wxID_ANY, wxEmptyString, pos, size);
			buttons[i][j] = button;
		}
	}

}
