#include "MinesweeperGame.h"

MinesweeperGame::MinesweeperGame(int difficulty, bool solvable, int width, int height)
{
	// Dynamic array of arrays, looks complicated but makes it flexible
	grid = new int* [height];
	for (int i = 0; i < width; i++) {
		grid[i] = new int[width];
	}
	// -1 = bomb
	// 0-8 = number of bombs surrounding it
	// grid[y(height)][x(width)]

}

// Competition
void MinesweeperGame::populateBombsGrid(int difficulty, bool solvable)
{
	// add to argument first click location (which can't be a bomb when generating)
	
	// Calculate nearby numbers in populateNumbersGrid

	// make an array with coordinates of bombs: [[x1,y1],[x2,y2],...[xn,yn]]

	bombsAmount = 0;
}

void MinesweeperGame::populateNumbersGrid() {
	// make empty grid or fill the grid with 0's
	// go through array with coordinates of bombs and call addBombToGrid
	// put -1 on bomb locations and increase numbers around it in the grid by one.
}

// What does a tile in this backend grid represent?
// Basicly implement this function as if the grid has been clicked on at x, y
bool MinesweeperGame::updateGrid(int x, int y)
{
	// Should it return false if game is not active?
	// check if right or left clicked
		// if right clicked toggle flag which is done in frontend.
		// if left clicked if there is a bomb or not
			// if there is a bomb gameover return false (keep track somewhere that its gameover)
			// if there is no bomb return true 
	if (grid[y][x] == -1) {
		gameState = GameState::lost;
		return false;
	}
	else {
		return true;
	}
}

// Return number so that the front end can display it if its open.
int MinesweeperGame::getTileNumber(int x, int y) {
	return grid[y][x];
	// error if its a bomb?
}

