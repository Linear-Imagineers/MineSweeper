#pragma once
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/event.h>

#include "MinesweeperGame.h"

class GameScreen : public wxPanel {
public:
	// GameScreen constructor
	GameScreen(wxWindow* parent);

	// Event listener for size changes
	void resize(wxSizeEvent& event);

	// A visual tile in the grid
	// For some reference, see https://wiki.wxwidgets.org/Painting_your_custom_control
	class wxTile : public wxWindow {
	public:
		// wxTile constructor
		wxTile(wxWindow* parent, int x, int y);

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
		// The coordinates of this tile
		int x, y;
		
		// The state of this tile
		State state;

		// Required for the event table in the implementation file (see https://docs.wxwidgets.org/3.2/overview_events.html)
		wxDECLARE_EVENT_TABLE();
	};

	// Dynamic array to all the tiles
	wxTile*** tiles;

private:

protected:
	// Pointer to the current game that is being played
	MinesweeperGame* gameInstance;
};
