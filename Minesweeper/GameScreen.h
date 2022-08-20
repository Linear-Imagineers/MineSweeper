#pragma once
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/event.h>

#include "MinesweeperGame.h"

class GameScreen : public wxPanel {
public:
	GameScreen(wxWindow* parent);

	void resize(wxSizeEvent& event);

	// A tile in the grid
	// For some reference, see https://wiki.wxwidgets.org/Painting_your_custom_control
	class wxTile : public wxWindow {
	public:
		// Constructor
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

		// Paint event
		void paintEvent(wxPaintEvent& evt);

		// Rendering method
		void render(wxDC& dc);

		// Left click event handler
		void leftClick(wxMouseEvent& event);
		// Reft click event handler
		void rightClick(wxMouseEvent& event);

	private:
		// The coordinates of this tile
		int x, y;

		// TODO remove, debugging
		// The amount of times this tile was painted
		int paints;
		
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
