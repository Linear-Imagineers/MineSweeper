#pragma once
#include <wx/panel.h>
#include <wx/button.h>

#include "MinesweeperGame.h"

class GameScreen : public wxPanel {
public:
	GameScreen(wxWindow* parent);

	class tileButton : public wxButton {
		// Overrides the normal drawing function, draws button according to state
		void Update() override;

	private:
		//Every possible state for the tile
		enum TileState {
			flag = 0,
			bomb = 1,
			closed = 2,
			open = 3
		};

	};
private:
	// Dynamic array to all the tiles
	tileButton** tiles = new tileButton * [];
protected:
	// Pointer to the current game that is being played
	MinesweeperGame* gameInstance;
};
