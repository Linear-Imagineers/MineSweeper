#include "GameScreen.h"
#include <wx/msgdlg.h>

enum {
	ButtonID = 2
};

GameScreen::GameScreen(wxWindow* parent) :
	wxPanel(parent)
{
	//Bind Click event to update function
	Bind(wxEVT_BUTTON, &GameScreen::UpdateTile, this, ButtonID);

	//GridWidth should be derived from gameInstance, but that hasn't been implemented yet
	int GridHeight = 10;
	int GridWidth = 10;

	int ButtonSize = 30;
	// Initialize grid
	tiles = new TileButton ** [GridHeight];
	for (int i = 0; i < GridHeight; i++) {
		tiles[i] = new TileButton*[GridWidth];
	}
	// Draw the grid
	for (int i = 0; i < GridHeight; i++) {
		for (int j = 0; j < GridWidth; j++) {
			// Coordinate of new button
			wxPoint ButtonPos = wxPoint(i * ButtonSize, j * ButtonSize);
			// WxSize object of size, to pass to the button constructor
			wxSize _ButtonSize = wxSize(ButtonSize, ButtonSize);
			
			// Instantiate new TileButton object
			tiles[i][j] = new TileButton(this, ButtonPos, _ButtonSize, i, j);
		}
	}
	// Draw settings button


	// Make buttons interactable
	

	// If game is over -> game over screen or winning screen
}

// Called when button is pressed
void GameScreen::UpdateTile(wxCommandEvent& event) {
	// Change in backend
	TileButton *clickedButton = (TileButton*)event.GetEventObject();
	wxMessageBox("Clicked " + std::to_string(clickedButton->x) + " - " + std::to_string(clickedButton->y));

	// Changes internal state of the button
	// Changes are rendered by the Update() function of tile
	// (Maybe invalidate tile)
	
}

// Might need to override different function
void GameScreen::TileButton::Update()
{
	// Change bitmaps according to state 
	__super::Update();
	
}

// This is the constructor of the TileButton class. We want it to create a normal button,
// but we created a new class to add a few member variables to it. Therefore, we just want to call
// the constructor of the wxButton class when we construct this class.
GameScreen::TileButton::TileButton(wxWindow* parent, wxPoint pos, wxSize sz, int x, int y) :
	wxButton(parent, ButtonID, wxEmptyString, pos, sz)
{
	this->x = x;
	this->y = y;
}

