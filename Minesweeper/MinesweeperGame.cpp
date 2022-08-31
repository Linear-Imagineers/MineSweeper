#include "MinesweeperGame.h"
#include <exception>
#include <stdexcept>
#include <string>

MinesweeperGame::MinesweeperGame(int bombsAmount, bool solvable, int width, int height)
{
	this->bombsAmount = bombsAmount;
	this->gridHeight = height;
	this->gridWidth = width;
	this->solvable = solvable;

	gameState = GameState::initializing;
	closedTilesCount = gridHeight * gridWidth;
	
	// Dynamic array of arrays, looks complicated but makes it flexible
	grid = new int* [height];
	openedGrid = new bool* [height];

	// Fill grid and openedGrid 2D arrays with default values
	for (int y = 0; y < height; y++) {
		grid[y] = new int[width];
		openedGrid[y] = new bool[width];

		for (int x = 0; x < width; x++) {
			grid[y][x] = 0;
			openedGrid[y][x] = false;
		}
	}
}

/* Functions for populating the grid */

// Competition
void MinesweeperGame::populateBombsGrid(int x, int y)
{
	// TODO proper populating
	// Make an array with coordinates of bombs: [[x1,y1],[x2,y2],...[xn,yn]]
	int** bombs = new int* [bombsAmount];
	for (int i = 0; i < bombsAmount; i++) {
		bombs[i] = new int[bombsAmount];
		// Example bombs are at (i, 2), the third row
		bombs[i][0] = i;
		bombs[i][1] = 2;
	}

	populateNumbersGrid(bombs);

	// The game is on
	gameState = GameState::active;
}

// makes the numbers according to the bombs array given
void MinesweeperGame::populateNumbersGrid(int** bombs) {
	// make empty grid or fill the grid with 0's, which is done in the constructor.
	// go through array with coordinates of bombs
	// put -1 on bomb locations and increase numbers around it in the grid by one.

	for (int i = 0; i < bombsAmount; i++) {
		// Bombs is 2d array, i'th bomb at (bomb[i][0], bomb[i][1])
		int bombX = bombs[i][0];
		int bombY = bombs[i][1];

		// Put the bomb on the grid
		grid[bombY][bombX] = -1;
		
		// Loop over a 3x3 grid surrounding the bomb tile
		for (int dy = -1; dy < 2; dy++) {
			for (int dx = -1; dx < 2; dx++) {
				int x = bombX + dx;
				int y = bombY + dy;

				// Check whether adjacent tile is within grid and not a bomb
				if (isValidGridCoords(x, y) && grid[y][x] != -1) {
					// Increment its surrounding bomb count
					grid[y][x]++;
				}
			}
		}
	}
}

// Reveals to the frontend if the tile is a bomb or not, updates values in backend accordingly
bool MinesweeperGame::revealTile(int x, int y)
{
	// If the grid isn't populated yet, ...
	if (gameState == GameState::initializing) {
		// ... populate the grid, now knowing the initially revealed tile
		// This will set the gameState to active
		populateBombsGrid(x, y);
	}

	// Only allow tile revealing in an active game
	if (gameState != GameState::active) {
		throw std::logic_error("Attempt to reveal tile in non-active game state " + std::to_string(gameState));
	}

	// Make sure the provided grid coordinates are valid
	assertValidGridCoords(x, y);

	// Throw an exception if this tile is already opened
	if (openedGrid[y][x]) {
		throw std::logic_error("Attempt to reveal already-reveaveled tile at " + formatCoords(x, y));
	}

	// Open tile and decrement the closed tiles counter
	openedGrid[y][x] = true;
	closedTilesCount--;

	// Check if the tile is a bomb
	if (grid[y][x] == -1) {
		gameState = GameState::lost;
		
		return true;
	}
	// Check if all remaining tiles are bombs, if so, the game is won
	else if (closedTilesCount == bombsAmount) {
		gameState = GameState::won;
		return true;
	} 
	else {
		return false;
	}
}

// Return number so that the front end can display it if its open.
int MinesweeperGame::getTileNumber(int x, int y) {
	assertValidGridCoords(x, y);

	// Disallow getting tile number before the grid is populated
	if (gameState == GameState::initializing) {
		throw std::logic_error("Attempt to get tile number at " + formatCoords(x, y) + " while game is initiating");
	}

	// Disallowing getting tile number in an active game
	//  but allow it when the game is over (won or lost)
	//  for example if the frontend wants to display the grid post-game.
	if (gameState == GameState::active && !openedGrid[y][x]) {
		throw std::logic_error("Attempt to get tile number of closed tile at " + formatCoords(x, y));
	}

	return grid[y][x];
}

MinesweeperGame::GameState MinesweeperGame::getGameState() {
	return gameState;
}

/* Functions for validity checks and exceptions */

bool MinesweeperGame::isValidGridCoords(int x, int y)
{
	return x >= 0 && x < gridWidth&& y >= 0 && y < gridHeight;
}

void MinesweeperGame::assertValidGridCoords(int x, int y)
{
	if (!isValidGridCoords(x, y)) {
		throw std::invalid_argument("Invalid grid coordinates: " + formatCoords(x, y));
	}
}

std::string MinesweeperGame::formatCoords(int x, int y) {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
