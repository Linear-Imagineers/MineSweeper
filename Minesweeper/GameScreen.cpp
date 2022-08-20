#include "GameScreen.h"
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <wx/wx.h>

GameScreen::GameScreen(wxWindow* parent) :
	wxPanel(parent)
{
	// TODO gridWidth should be derived from gameInstance, but that hasn't been implemented yet
	int gridHeight = 10;
	int gridWidth = 10;

	// TODO better solution for this, also probably disallow user resizing
	// Set appropriate window size
	parent->SetSize(gridWidth * wxTile::size + 17, gridHeight * wxTile::size + 40);

	// A wxGridSizer will allign all the tiles in a grid formation
	wxGridSizer* sizer = new wxGridSizer(gridHeight, gridWidth, wxSize(1, 1));

	// Initialize grid
	tiles = new wxTile ** [gridHeight];
	for (int i = 0; i < gridHeight; i++) {
		tiles[i] = new wxTile*[gridWidth];
	}

	// Draw the grid
	for (int y = 0; y < gridHeight; y++) {
		for (int x = 0; x < gridWidth; x++) {
			// Instantiate new wxTile object
			tiles[y][x] = new wxTile(this, y, x);
			// Add wxTile object to the sizer
			sizer->Add(tiles[y][x]);
		}
	}

	// Add sizer to the wxPanel and make it fit all tiles
	this->SetSizerAndFit(sizer);

	// TODO event table?
	Bind(wxEVT_SIZE, &GameScreen::resize, this);

	// Draw settings button
	

	// If game is over -> game over screen or winning screen
}

// Event handler for size events
void GameScreen::resize(wxSizeEvent& event) {
	Refresh();
}

GameScreen::wxTile::wxTile(wxWindow* parent, int x, int y)  : 
	wxWindow(parent, wxID_ANY)
{
	this->x = x;
	this->y = y;
	this->state = State::closed;

	this->paints = 0;

	SetMinSize(wxSize(size, size));
	SetSize(wxSize(size, size));
}

void GameScreen::wxTile::paintEvent(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void GameScreen::wxTile::render(wxDC& dc)
{
	this->paints += 1;
	std::string fileName;
	switch(this->state) {
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
	dc.DrawBitmap(wxBitmap(wxT("" + fileName), wxBITMAP_TYPE_BMP), 0, 0);
	//dc.SetBrush(*wxYELLOW_BRUSH);
	//dc.DrawText(std::to_string(this->paints), 8, 8);
}

void GameScreen::wxTile::leftClick(wxMouseEvent& event)
{
	if (this->state != State::closed) {
		return;
	}

	// TODO contact backend

	// TODO remove testing bomb
	if (this->x == 0 && this->y == 0) {
		this->state = State::bomb;
	}
	else {
		this->state = State::open;
	}

	this->Refresh();
}

void GameScreen::wxTile::rightClick(wxMouseEvent& event)
{
	if (this->state == State::closed) {
		this->state = State::flag;
	}
	else if (this->state == State::flag) {
		this->state = State::closed;
	}
	else {
		return;
	}
	
	this->Refresh();
}

// Event table for wx, defines which methods are called for which events
wxBEGIN_EVENT_TABLE(GameScreen::wxTile, wxPanel)

	EVT_LEFT_DOWN(wxTile::leftClick)
	EVT_RIGHT_DOWN(wxTile::rightClick)

	// catch paint events
	EVT_PAINT(wxTile::paintEvent)

wxEND_EVENT_TABLE()