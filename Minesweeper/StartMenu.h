#pragma once
#include <wx/panel.h>

#include "MinesweeperGame.h"

class StartMenu : public wxPanel {
public:
	StartMenu(wxWindow* parent);
private:
	MinesweeperGame startGame();
};