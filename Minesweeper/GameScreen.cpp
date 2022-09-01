#include "GameScreen.h"
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <wx/wx.h>
#include "MainWindow.h"

GameScreen::GameScreen(wxWindow* parent) :
	wxPanel(parent)
{
	int gridHeight = 10;
	int gridWidth = 10;

	// TODO improve backend initialization:
	//			get backend instance passed with argument
	//			get width and height from backend
	gameInstance = new MinesweeperGame(9, false, gridWidth, gridHeight);

	// TODO improve window sizing, preferably make it automatically adjust frame size based on this window.
	//			includes EVT_SIZE listener, Sizer stuff and SetSizerAndFit call
	// Set appropriate window size
	parent->SetSize(gridWidth * (Tile::size + 1) - 1 + 17, gridHeight * (Tile::size + 1) - 1 + 40);

	// A wxGridSizer will allign all the tiles in a grid formation
	wxGridSizer* sizer = new wxGridSizer(gridHeight, gridWidth, wxSize(1, 1));

	// Initialize grid
	tiles = new Tile ** [gridHeight];
	for (int y = 0; y < gridHeight; y++) {
		tiles[y] = new Tile*[gridWidth];
	}

	// Draw the grid
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			// Instantiate new wxTile object
			tiles[y][x] = new Tile(this, x, y);

			// Add wxTile object to the grid sizer
			// The order in which items are added to the sizer matters:
			//   (0,0), (0,1) then (0,2) etc
			sizer->Add(tiles[y][x]);
		}
	}

	// Add sizer to the wxPanel and make it fit all tiles
	this->SetSizerAndFit(sizer);

	// Bind the resize event
	Bind(wxEVT_SIZE, &GameScreen::resize, this);

	// TODO Draw settings button + rest of screen (pause, reset etc)
}

void GameScreen::resize(wxSizeEvent& event) {
	Refresh();
}

GameScreen::Tile::Tile(GameScreen* gameScreen, int x, int y) : 
	wxWindow(gameScreen, wxID_ANY)
{
	// Initialize variables
	this->tiles = gameScreen->tiles;
	this->gameScreen = gameScreen;
	this->gameInstance = gameScreen->gameInstance;
	this->x = x;
	this->y = y;
	this->state = State::closed;

	// Set minimum size of the tile
	SetMinSize(wxSize(size, size));
}

void GameScreen::Tile::paintEvent(wxPaintEvent& evt)
{
	// Create wxPaintDC instance, required for painting
	wxPaintDC dc(this);

	// TODO load bitmaps much earlier, store in State enum if possible

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

	// Draw the bitmap
	dc.DrawBitmap(wxBitmap(wxT("" + fileName), wxBITMAP_TYPE_BMP), 0, 0);

	if (this->state == State::open) {
		int num = gameInstance->getTileNumber(this->x, this->y);

		// TODO replace entire text drawing with custom (partially invisible) images of digits

		// Set font for displaying text
		wxFont font = wxFont().Bold();
		font.SetPointSize(16);
		dc.SetFont(font);

		// Convert number to decimal string
		std::string text = std::to_string(num);

		// Gets the display size of the text
		wxSize textSize = dc.GetTextExtent(text);

		// Draws the text at the center of the tile
		dc.DrawText(text, wxPoint((size - textSize.x) / 2, (size - textSize.y) / 2));
	}
}

void GameScreen::Tile::leftClick(wxMouseEvent& event)
{
	// Only closed tiles can be opened
	if (this->state != State::closed) {
		return;
	}

	bool gameStateChanged = this->gameInstance->revealTile(this->x, this->y);

	int tileNum = gameInstance->getTileNumber(this->x, this->y);
	// State::bomb if its a bomb
	if (tileNum == -1) {
		this->state = State::bomb;
	}
	// if tile has 0, reveal all tiles around this tile
	else if (tileNum == 0) {
		this->state = State::open;
		// additional refresh to show last tile clicked on before popup, TODO to be removed when popup is changed to different panel.
		this->Refresh();
		this->revealNeighbours(this->x, this->y); // recursive function
	}
	else {
		this->state = State::open;
	}
	// Update the displayed (bitmap) state
	this->Refresh();

	// If the game is not active anymore
	if (gameStateChanged) {
		gameEnd();
	}
}

void GameScreen::Tile::gameEnd() {
	// when gamestatechanged is active check which win condition
	MinesweeperGame::GameState gameState = gameInstance->getGameState();
	// Show a simple popup
	if (gameState == MinesweeperGame::GameState::won) {
		wxMessageBox("you did it");
	}
	else {
		wxMessageBox("no don't click those, they explode");
	}

	// reveal all tiles
	for (int x = 0; x < gameInstance->getGridWidth(); x++) {
		for (int y = 0; y < gameInstance->getGridHeight(); y++) {
			int num = gameInstance->getTileNumber(x, y);
			if (num == -1) {
				tiles[y][x]->state = State::bomb;
			}
			else {
				tiles[y][x]->state = State::open;
			}
			tiles[y][x]->Refresh();
		}
	}
}

void GameScreen::Tile::revealNeighbours(int startX, int startY) {
	// go through 8 surrounding tiles and itself
	for (int dx = -1; dx < 2; dx++) {
		for (int dy = -1; dy < 2; dy++) {
			int x = startX + dx;
			int y = startY + dy;
			// if it is out of range for the grid skip all of it
			if (gameInstance->isValidGridCoords(x, y)) {
				// if it is not closed ignore opening this tile.
				if (tiles[y][x]->state == State::closed) {
					// set the tile to open after revealing it from the backend and draw it with Refresh
					tiles[y][x]->state = State::open;
					tiles[y][x]->Refresh();

					if (this->gameInstance->revealTile(x, y)) {
						gameEnd();
						return;
					}

					// check if it is also a zero and recursively call revealNeighbours
					int num = this->gameInstance->getTileNumber(x, y);
					if (num == 0) {
						revealNeighbours(x, y);
					}
				}
			}
		}
	}
}

void GameScreen::Tile::rightClick(wxMouseEvent& event)
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
wxBEGIN_EVENT_TABLE(GameScreen::Tile, wxPanel)

	// Bind left and right click events
	EVT_LEFT_DOWN(Tile::leftClick)
	EVT_RIGHT_DOWN(Tile::rightClick)

	// Bind paint event
	EVT_PAINT(Tile::paintEvent)

wxEND_EVENT_TABLE()
