#include "MinesweeperGame.h"

MinesweeperGame::MinesweeperGame(int difficulty, bool solvable, int width, int height)
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
	populateBombsGrid(difficulty, solvable);
}

// Competition
void MinesweeperGame::populateBombsGrid(int difficulty, bool solvable)
{
	// make an array of x and y coordinates for where the bombs go.
	bombsAmount = 2;
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

/*MinesweeperGame::MinesweeperGame()
{
	MinesweeperGame(1, false, 10, 10);
}*/


void MinesweeperGame::populateNumbersGrid() {
	// make empty grid or fill the grid with 0's, which is done in the constructor.
	// go through array with coordinates of bombs and call addBombToGrid
	// put -1 on bomb locations and increase numbers around it in the grid by one.

	for (int i = 0; i < bombsAmount; i++) {
		// Bombs is 2d array, i'th bomb at (bomb[i][1], bomb[i][0])
		int y = bombs[i][1];
		int x = bombs[i][0];

		grid[y][x] = -1;
		
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (i == j == 0) continue; // Skip middle tile
				// Check whether adjacent tile is within grid
				if (y + i >= 0 && y + i < gridHeight && x + j >= 0 && x + j < gridWidth) {
					// Add one to adjacent tile
					grid[y + i][x + j]++;
				}
			}
		}
		
	}
	/*
	if (grid[bombs[i][1] - 1][bombs[i][0] - 1] >= 0) {
			grid[bombs[i][1] - 1][bombs[i][0] - 1]++;
		}
		if (grid[bombs[i][1] - 1][bombs[i][0]] >= 0) {
			grid[bombs[i][1] - 1][bombs[i][0]]++;
		}
		if (grid[bombs[i][1] - 1][bombs[i][0] + 1] >= 0) {
			grid[bombs[i][1] - 1][bombs[i][0] + 1]++;
		}
		if (grid[bombs[i][1]][bombs[i][0] - 1] >= 0) {
			grid[bombs[i][1]][bombs[i][0] - 1]++;
		}
		if (grid[bombs[i][1]][bombs[i][0] + 1] >= 0) {
			grid[bombs[i][1]][bombs[i][0] + 1]++;
		}
		if (grid[bombs[i][1] + 1][bombs[i][0] - 1] >= 0) {
			grid[bombs[i][1] + 1][bombs[i][0] - 1]++;
		}
		if (grid[bombs[i][1] + 1][bombs[i][0]] >= 0) {
			grid[bombs[i][1] + 1][bombs[i][0]]++;
		}
		if (grid[bombs[i][1] + 1][bombs[i][0] + 1] >= 0) {
			grid[bombs[i][1] + 1][bombs[i][0] + 1]++;
		}*/
	gameState = GameState::active;
}

// What does a tile in this backend grid represent?
// Basicly implement this function as if the grid has been clicked on at x, y
bool MinesweeperGame::updateGrid(int x, int y)
{
	// Should it return false if game is not active? or return error?
	// check if right or left clicked
		// if right clicked toggle flag which is done in frontend.
		// if left clicked if there is a bomb or not
			// if there is a bomb gameover return false (keep track somewhere that its gameover)
			// if there is no bomb return true 
	if (gameState == GameState::active) {
		if (grid[y][x] == -1) {
			gameState = GameState::lost;
			return false;
		}
		else {
			return true;
		}
	}
	else {
		//error?
		return false;
	}
}

// Return number so that the front end can display it if its open.
int MinesweeperGame::getTileNumber(int x, int y) {
	return grid[y][x];
	// error if its a bomb?
}

