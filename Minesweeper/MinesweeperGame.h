#pragma once
class MinesweeperGame
{
	//example
public:
	// Constructor, instantiates a game of certain amount of bombs.
	// Also specifies whether game should be beaten with logic
	MinesweeperGame(int bombsAmount, bool solvable, int width, int height);
	//MinesweeperGame();
	// Method to update the grid, when a particular tile has been pressed
	bool revealTile(int x, int y);
	// Method to get the number of a tile to display, where -1 is a bomb and 0-8 are numbers to display.
	int getTileNumber(int x, int y);

private:
	int gridWidth, gridHeight;
	// Method to populate the grid with bombs
	void populateBombsGrid(int bombsAmount, bool solvable);
	// Method to populate the grid with the numbers according to the bombs
	void populateNumbersGrid();


	// Points to the array where will store the grid
	int** grid;
	// Points to the array where boolean value of open or closed is stored for each tile of the grid
	bool** openedGrid;
	// Keeps track if the game is still running when true or if it is a game over when false
	enum GameState {
		// states can still be changed
		initializing = 0,
		active = 1,
		won = 2,
		lost = 3
	};
	// keeps track of the gameState.
	GameState gameState = initializing;
	// Keeps track of amount of bombs for this game instance
	int bombsAmount = 0;
	int** bombs;
};
