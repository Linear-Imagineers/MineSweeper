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
	void populateGrid(int difficulty, bool solvable);
	// Method to update the grid, when a particular tile has been pressed
	bool updateGrid(int x, int y); 

	// Points to the array where will store the grid
	int** grid; 
};

