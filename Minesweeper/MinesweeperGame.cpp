#include "MinesweeperGame.h"

MinesweeperGame::MinesweeperGame(int difficulty, bool solvable, int width, int height)
{
	// Dynamic array of arrays, looks complicated but makes it flexible
	grid = new int* [height];
	for (int i = 0; i < width; i++) {
		grid[i] = new int[width];
	}

}

// Competition
void MinesweeperGame::populateGrid(int difficulty, bool solvable)
{
	// Also calculate nearby
}

// What does a tile in this backend grid represent?
// Basicly implement this function as if the grid has been clicked on at x, y
bool MinesweeperGame::updateGrid(int x, int y)
{
	return false;
}
