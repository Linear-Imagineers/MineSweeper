#pragma once
#include <wx/panel.h>
#include <wx/button.h>

#include "MinesweeperGame.h"

class GameScreen : public wxPanel {
public:
	GameScreen(wxWindow* parent);
private:
	// Pointer to the current game that is being played
	MinesweeperGame* gameInstance;
};
