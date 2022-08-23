#include "MinesweeperGame.h"

MinesweeperGame::MinesweeperGame(int bombsAmount, bool solvable, int width, int height)
{
	gridHeight = height;
	gridWidth = width;
	
	// Dynamic array of arrays, looks complicated but makes it flexible
	grid = new int* [height];
	for (int i = 0; i < height; i++) {
		grid[i] = new int[width];
		for (int j = 0; j < width; j++) {
			grid[i][j] = {0};
		}
	}
	// -1 = bomb
	// 0-8 = number of bombs surrounding it
	// grid[y(height)][x(width)]

	openedGrid = new bool* [height];
	for (int i = 0; i < height; i++) {
		openedGrid[i] = new bool[width];
		for (int j = 0; j < width; j++) {
			openedGrid[i][j] = false;
		}
	}
	populateBombsGrid(bombsAmount, solvable);
}

// Competition
void MinesweeperGame::populateBombsGrid(int bombsAmount, bool solvable)
{
	// make an array of x and y coordinates for where the bombs go.
	bombs = new int* [bombsAmount];
	for (int i = 0; i < bombsAmount; i++) {
		bombs[i] = new int[2];
		bombs[i][0] = { i };
		bombs[i][1] = { 2 };
	}
	populateNumbersGrid();
	// add to argument first click location (which can't be a bomb when generating)
	
	// Calculate nearby numbers in populateNumbersGrid

	// make an array with coordinates of bombs: [[x1,y1],[x2,y2],...[xn,yn]]

}

// makes the numbers according to the bombs array given
void MinesweeperGame::populateNumbersGrid() {
	// make empty grid or fill the grid with 0's, which is done in the constructor.
	// go through array with coordinates of bombs
	// put -1 on bomb locations and increase numbers around it in the grid by one.

	for (int i = 0; i < bombsAmount; i++) {
		// Bombs is 2d array, i'th bomb at (bomb[i][1], bomb[i][0])
		int y = bombs[i][1];
		int x = bombs[i][0];

		grid[y][x] = -1;
		
		for (int dy = -1; dy < 2; dy++) {
			for (int dx = -1; dx < 2; dx++) {
				if (dy == dx == 0) continue; // Skip middle tile
				// Check whether adjacent tile is within grid
				if (grid[y+ dy][x + dx] != -1 && y + dy >= 0 && y + dy < gridHeight && x + dx >= 0 && x + dx < gridWidth) {
					// Add one to adjacent tile
					grid[y + dy][x + dx]++;
				}
			}
		}
		
	}
	gameState = GameState::active;
}


// Reveals to the frontend if the tile is a bomb or not, updates values in backend accordingly
bool MinesweeperGame::revealTile(int x, int y)
{
	if (gameState == GameState::active && !openedGrid[y][x] && x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
		if (grid[y][x] == -1) {
			gameState = GameState::lost;
			openedGrid[y][x] = true;
			return false;
		}
		else {
			openedGrid[y][x] = true;
			return true;
		}
	}
	else {
		// TODO make error messages, either just one or different messages depending on the error (grid not active, tile already opened, not within grid bounds)
		return false;
	}
}

// Return number so that the front end can display it if its open.
int MinesweeperGame::getTileNumber(int x, int y) {
	if (openedGrid[y][x] && x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
		return grid[y][x];
	}
	else {
		// TODO make error messages, either just one or different messages depending on the error (tile not open, tile not within grid bounds)
		return -10; // -10 is a temporary error number that it returns.
	}
}

