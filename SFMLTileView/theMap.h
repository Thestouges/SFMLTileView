#include <iostream>
#include <SFML\Graphics.hpp>

class theMap{
public:
	theMap();
	void initGrid();
	int getTileValue(int,int);
	int getGridSize();
private:
	int gridSize;
	int **grid;
};