#pragma once
#include <wx/panel.h>
#include <wx/button.h>

class GameScreen : public wxPanel {
public:
	GameScreen(wxWindow* parent);
};

enum {
	ID_Button = 2
};