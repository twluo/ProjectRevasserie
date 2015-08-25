// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectRevasserie.h"
#include "hexBoard.h"

TArray<AboardTile*> AhexBoard::getNeighbors(int32 x, int32 y) {

	TArray<AboardTile*> neighbors;
	if (y % 2 == 0) {
		if (inBounds(x-1, y-1))
			neighbors.Add(getTile(x - 1, y - 1));
		if (inBounds(x, y - 1))
			neighbors.Add(getTile(x, y - 1));
		if (inBounds(x - 1, y))
			neighbors.Add(getTile(x - 1, y));
		if (inBounds(x + 1, y))
			neighbors.Add(getTile(x + 1, y));
		if (inBounds(x - 1, y + 1))
			neighbors.Add(getTile(x - 1, y + 1));
		if (inBounds(x, y + 1))
			neighbors.Add(getTile(x, y + 1));
	}
	else if (y % 2 == 1) {
		if (inBounds(x, y - 1))
			neighbors.Add(getTile(x, y - 1));
		if (inBounds(x + 1, y - 1))
			neighbors.Add(getTile(x + 1, y - 1));
		if (inBounds(x - 1, y))
			neighbors.Add(getTile(x - 1, y));
		if (inBounds(x + 1, y))
			neighbors.Add(getTile(x + 1, y));
		if (inBounds(x, y + 1))
			neighbors.Add(getTile(x, y + 1));
		if (inBounds(x + 1, y + 1))
			neighbors.Add(getTile(x + 1, y + 1));
	}
	return neighbors;
}


