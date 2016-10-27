#include "theMap.h"

theMap::theMap(){
	initGrid();
}

void theMap::initGrid(){
	gridSize = 20;
	grid = new int*[gridSize];
	for(int i = 0; i < gridSize; i++)
		grid[i] = new int[gridSize];

	for(int i = 0; i < gridSize; i++)
		for(int j = 0; j < gridSize; j++){
			grid[i][j] = std::rand() % 100;
		}
}

int theMap::getTileValue(int x, int y){
	return grid[x][y];
}

int theMap::getGridSize(){
	return gridSize;
}