#include <string>

#pragma once
class MinesweeperGame {
public:
	// Constructor, instantiates a game of certain amount of bombs.
	// Also specifies whether game should be beaten with logic
	MinesweeperGame(int bombsAmount, bool solvable, int width, int height);
	
	// Keeps track if the game is still running when true or if it is a game over when false
	enum GameState {
		// Grid hasn't been populated yet
		initializing,
		// Game is being played
		active,
		// Winner winner
		won,
		// Game over
		lost
	};
	
	// Method to update the grid, when a particular tile has been pressed
	//  Return value is true if and only if the game is over (game state is won or lost)
	bool revealTile(int x, int y);
	
	// Method to get the number of bombs around a tile, range 0 to 8
	int getTileNumber(int x, int y);

	// Gets the current game state
	GameState getGameState();

	// Gets the gridWidth
	int getGridWidth();

	// Gets the gridHeight
	int getGridHeight();

	// Check if the given coordinates are valid (within the grid)
	bool isValidGridCoords(int x, int y);

private:
	// The width and height of the game's grid
	int gridWidth, gridHeight;
	
	// The total amount of bombs on the grid
	int bombsAmount = 0;

	// Whether the grid is solvable without guessing
	bool solvable;

	// The current state of the game
	GameState gameState;

	// 2d array, get value with grid[y][x]
	// Value explanation:
	//   -1  = bomb
	//   0-8 = number of bombs surrounding it
	int** grid;

	// Points to the array where boolean value of open or closed is stored for each tile of the grid
	//  closedTilesCount should be kept in sync with this grid 
	//  (closedTilesCount should contain the amount of 'false' values in the 2d array at all times)
	bool** openedGrid;
	// Keeps track of the current amount of closed tiles, used for checking if all non-bomb tiles have been opened
	int closedTilesCount;

	/* Functions for populating the grid */

	// Populate the grid with bombs
	void populateBombsGrid(int x, int y);
	// Populate the grid with the numbers according to the bombs
	void populateNumbersGrid(int** bombs);

	/* Functions for validity checks and exceptions */

	// Throw an exception if the given coordinates are invalid (outside of the grid)
	void assertValidGridCoords(int x, int y);

	// Returns the given coordinates formatted as '(x, y)'
	// used in creating exception messages
	std::string formatCoords(int x, int y);
};
