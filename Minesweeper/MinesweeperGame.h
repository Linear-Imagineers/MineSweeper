#pragma once
class MinesweeperGame
{
	//example
public:
	// Constructor, instantiates a game of certain difficulty.
	// Also specifies whether game should be beaten with logic
	MinesweeperGame(int difficulty, bool solvable, int width, int height);

	int gridWith, gridHeight;
private:
	// Method to populate the grid with bombs
	void populateBombsGrid(int difficulty, bool solvable);
	// Method to populate the grid with the numbers according to the bombs
	void populateNumbersGrid();
	// Method to update the grid, when a particular tile has been pressed
	bool updateGrid(int x, int y); 
	// Method to get the number of a tile to display, where -1 is a bomb and 0-8 are numbers to display.
	int getTileNumber(int x, int y);
	// Method to add a bomb to the grid which increases the numbers around it by one and sets its position to -1.
	void addBombToGrid(int x, int y);

	// Points to the array where will store the grid
	int** grid; 

	// Keeps track if the game is still running when true or if it is a game over when false
	int gameActive;

	// Keeps track of amount of bombs for this game instance
	int bombsAmount;
};

