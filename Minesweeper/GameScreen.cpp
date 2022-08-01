#include "GameScreen.h"

GameScreen::GameScreen(wxWindow* parent) :
	wxPanel(parent)
{
	// Draw the grid
	// Draw settings button
	wxButton* button = new wxButton(this);


	// Make buttons interactable
		// If game is over -> game over screen or winning screen
}

// Called when button is pressed
void GameScreen::UpdateTile(wxCommandEvent& event) {
	// Change in backend
	

	// Changes internal state of the button
	// Changes are rendered by the Update() function of tile
	// (Maybe invalidate tile)
	
}

// Might need to override different function
void GameScreen::tileButton::Update()
{
	// Change bitmaps according to state 
	__super::Update();
	
}
