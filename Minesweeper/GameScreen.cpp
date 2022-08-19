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

	gameInstance = new MinesweeperGame(1, false, GridWidth, GridHeight);
	// Set appropriate window size
	parent->SetSize(GridWidth * ButtonSize + 17, GridHeight * ButtonSize + 40);

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
	

	// If game is over -> game over screen or winning screen
}

// Called when button is pressed
void GameScreen::UpdateTile(wxCommandEvent& event) {
	// Gets the object that triggered the event, and casts it to a button.
	TileButton* ClickedTile = (TileButton*)event.GetEventObject();

	// In case rightclicked on button (check it with event object?)
	/*if (when right clicked) {
		if (ClickedTile->CurrentState == TileButton::flag) {
			//ClickedTile->CurrentState = TileButton::closed;
			currentFlags--;
			//for now you can't unflag until we find a way to detect right mouse clicks.

		}
		else if (ClickedTile->CurrentState == TileButton::closed) {
			ClickedTile->CurrentState = TileButton::flag;
			currentFlags++;
		}
	//}*/
	 
		if (gameInstance->updateGrid(ClickedTile->x, ClickedTile->y)) {
			ClickedTile->CurrentState = TileButton::open;
		}
		else {
			ClickedTile->CurrentState = TileButton::flag; //flag should be bomb but bomb doesn't display anything atm
		}
	// keep track of amount of flags so you can display [bombs - flags = bombs left]
	// updateGrid in MineSweeperGame 

	// Changes internal state of the button
	
	// Changes are rendered by the Update() function of tile
	// (Maybe invalidate tile) 
	// button can be turned off if its open so you can't click it again?
	ClickedTile->Update();
}

// Might need to override different function
void GameScreen::TileButton::Update()
{
	// Switch statement, to change bitmap according to state of tile
	switch (CurrentState) {
		case closed: {
			this->SetLabel(".");
			break;
		}
		case open: {
			this->SetLabel("1");
			break;
		}
		case flag: {
			wxBitmap b = wxBitmap(wxT("flag.bmp"), wxBITMAP_TYPE_BMP);
			this->SetBitmap(b);
			this->SetLabel("");
		}
	}
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

	// Set current tile state
	this->CurrentState = closed;
	Update();
}

