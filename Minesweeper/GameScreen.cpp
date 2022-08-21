#include "GameScreen.h"
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <wx/wx.h>

GameScreen::GameScreen(wxWindow* parent) :
	wxPanel(parent)
{
	// TODO backend initialization

	// TODO width and height should be derived from gameInstance, but that hasn't been implemented yet
	int gridHeight = 10;
	int gridWidth = 10;

	gameInstance = new MinesweeperGame(1, false, gridWidth, gridHeight);

	// TODO better solution for this (automatically set size to minimal fit), also probably disallow user resizing
	// Set appropriate window size
	parent->SetSize(gridWidth * wxTile::size + 17, gridHeight * wxTile::size + 40);

	// A wxGridSizer will allign all the tiles in a grid formation
	wxGridSizer* sizer = new wxGridSizer(gridHeight, gridWidth, wxSize(1, 1));

	// Initialize grid
	tiles = new wxTile ** [gridHeight];
	for (int y = 0; y < gridHeight; y++) {
		tiles[y] = new wxTile*[gridWidth];
	}

	// Draw the grid
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			// Instantiate new wxTile object
			tiles[y][x] = new wxTile(this, y, x);

			// Add wxTile object to the grid sizer
			// The order in which items are added to the sizer matters:
			//   (0,0), (0,1) then (0,2) etc
			sizer->Add(tiles[y][x]);
		}
	}

	// Add sizer to the wxPanel and make it fit all tiles
	this->SetSizerAndFit(sizer);

	// Bind the resize event
	// TODO figure out why this only works well after adding all tiles
	Bind(wxEVT_SIZE, &GameScreen::resize, this);

	// TODO Draw settings button
}

void GameScreen::resize(wxSizeEvent& event) {
	Refresh();
}

GameScreen::wxTile::wxTile(GameScreen* gameScreen, int x, int y) : 
	wxWindow(gameScreen, wxID_ANY)
{
	// Initialize variables
	this->gameScreen = gameScreen;
	this->x = x;
	this->y = y;
	this->state = State::closed;

	// Set minimum size of the tile
	SetMinSize(wxSize(size, size));
}

void GameScreen::wxTile::paintEvent(wxPaintEvent& evt)
{
	// Create wxPaintDC instance, required for painting
	wxPaintDC dc(this);

	// Get file name of bitmap resource associated with the current state
	std::string fileName;
	switch (this->state) {
		case flag:
			fileName = "flag.bmp";
			break;
		case bomb:
			fileName = "bomb.bmp";
			break;
		case closed:
			fileName = "closed.bmp";
			break;
		case open:
			fileName = "open.bmp";
			break;
	}

	// TODO load bitmaps much earlier, store in State enum if possible
	// Draw the bitmap
	dc.DrawBitmap(wxBitmap(wxT("" + fileName), wxBITMAP_TYPE_BMP), 0, 0);

	if (this->state == State::open) {
		int num = 3; // gameInstance->getTileNumber(this->x, this->y);
		dc.DrawText(std::to_string(num), wxPoint(5, 5));
	}
}

void GameScreen::wxTile::leftClick(wxMouseEvent& event)
{
	// Only closed tiles can be opened
	if (this->state != State::closed) {
		return;
	}

	// TODO contact backend and handle response appropriately

	this->state = State::open;

	// Update the displayed (bitmap) state
	this->Refresh();
}

void GameScreen::wxTile::rightClick(wxMouseEvent& event)
{
	if (this->state == State::closed) {
		// Flag a closed tile
		this->state = State::flag;
		this->gameScreen->currentFlags += 1;
	}
	else if (this->state == State::flag) {
		// Unflag a flagged tile
		this->state = State::closed;
		this->gameScreen->currentFlags -= 1;
	}
	else {
		return;
	}
	
	// Update the displayed (bitmap) state
	this->Refresh();
}

// Event table for wxTile, defines which methods are called for which events
wxBEGIN_EVENT_TABLE(GameScreen::wxTile, wxPanel)

	// Bind left and right click events
	EVT_LEFT_DOWN(wxTile::leftClick)
	EVT_RIGHT_DOWN(wxTile::rightClick)

	// Bind paint event
	EVT_PAINT(wxTile::paintEvent)

wxEND_EVENT_TABLE()