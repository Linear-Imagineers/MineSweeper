#pragma once
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/event.h>
#include "GameOverScreen.h"
#include "MinesweeperGame.h"

class GameScreen : public wxPanel {
public:
	// GameScreen constructor
	GameScreen(wxWindow* parent);

	// Event listener for size changes
	void resize(wxSizeEvent& event);

	// A visual tile in the grid
	// For some reference, see https://wiki.wxwidgets.org/Painting_your_custom_control
	class Tile : public wxWindow {
	public:
		// wxTile constructor
		Tile(GameScreen* gameScreen, int x, int y);

		// The state of a tile
		enum State {
			flag,
			bomb,
			closed,
			open
		};

		// The UI size of tiles
		static const int size = 30;

		// Paint event handler
		void paintEvent(wxPaintEvent& evt);

		// Left click event handler
		void leftClick(wxMouseEvent& event);
		// Reft click event handler
		void rightClick(wxMouseEvent& event);

	private:
		GameScreen* gameScreen;
		MinesweeperGame* gameInstance;
		Tile*** tiles;

		// The coordinates of this tile
		int x, y;
		
		// The state of this tile
		State state;

		// End of the game when a change in gameState has been noticed, gives popup message and reveals all tiles
		void gameEnd();

		// reveals the 8 surrounding tiles next to the center zero and recursive incase its also a zero
		void revealNeighbours(int x, int y);

		// reveal tile, either open if not closed, change to bomb if bomb and check for end condition
		void revealTile(int x, int y);

		// Required for the event table in the implementation file (see https://docs.wxwidgets.org/3.2/overview_events.html)
		wxDECLARE_EVENT_TABLE();
	};

private:
	// Pointer to the current game that is being played
	MinesweeperGame* gameInstance;

	// Keep track of the amount of current flags on the grid
	int currentFlags = 0;

	// Dynamic array to all the tiles
	Tile*** tiles;
};
