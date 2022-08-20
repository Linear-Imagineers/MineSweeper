#pragma once
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/bitmap.h>

#include "MinesweeperGame.h"

class GameScreen : public wxPanel {
public:
	GameScreen(wxWindow* parent);
	
	void UpdateTile(wxCommandEvent& event);

	class TileButton : public wxButton {	
	public:
		// Constructor
		TileButton(wxWindow* parent, wxPoint pos, wxSize sz, int x, int y);

		// Overrides the normal drawing function, draws button according to state
		void Update() override;

		//Coordinates in the grid
		int x, y;

		//Keeps track of the current state of the tile
		int CurrentState;

		//Every possible state for the tile
		enum TileState {
			flag = 0,
			bomb = 1,
			closed = 2,
			open = 3
		};

	};
	
	// Dynamic array to all the tiles
	TileButton*** tiles;

private:
	// Keep track of the amount of current flags on the grid
	int currentFlags = 0;
protected:
	// Pointer to the current game that is being played
	MinesweeperGame* gameInstance;
};
