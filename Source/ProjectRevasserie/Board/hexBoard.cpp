// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectRevasserie.h"
#include "hexBoard.h"

TArray<AboardTile*> AhexBoard::getNeighbors(int32 x, int32 y) {

	TArray<AboardTile*> neighbors;
	//Odd Row
	if (y % 2 == 0) {
		//Top Left
		if (inBounds(x-1, y-1))
			neighbors.Add(getTile(x - 1, y - 1));
		//Top Right
		if (inBounds(x, y - 1))
			neighbors.Add(getTile(x, y - 1));
		//Left
		if (inBounds(x - 1, y))
			neighbors.Add(getTile(x - 1, y));
		//Right
		if (inBounds(x + 1, y))
			neighbors.Add(getTile(x + 1, y));
		//Bottom Left
		if (inBounds(x - 1, y + 1))
			neighbors.Add(getTile(x - 1, y + 1));
		//Bottom Right
		if (inBounds(x, y + 1))
			neighbors.Add(getTile(x, y + 1));
	}
	//Even Row
	else if (y % 2 == 1) {
		//Top Left
		if (inBounds(x, y - 1))
			neighbors.Add(getTile(x, y - 1));
		//Top Right
		if (inBounds(x + 1, y - 1))
			neighbors.Add(getTile(x + 1, y - 1));
		//Left
		if (inBounds(x - 1, y))
			neighbors.Add(getTile(x - 1, y));
		//Right
		if (inBounds(x + 1, y))
			neighbors.Add(getTile(x + 1, y));
		//Bottom Left
		if (inBounds(x, y + 1))
			neighbors.Add(getTile(x, y + 1));
		//Bottom Right
		if (inBounds(x + 1, y + 1))
			neighbors.Add(getTile(x + 1, y + 1));
	}
	return neighbors;
}


TArray<AboardTile*> AhexBoard::getTilesInRange(int32 x, int32 y, int32 range) {
	//make a pair <Tile, dist so far>
	//if dist so far + cost is less than range then add to queue
	//do BFS

	//Queue to implement the BFS
	TQueue<TPair<AboardTile*, int32>> Queue;
	//Solution Array
	TArray<AboardTile*> tilesInRange;
	AboardTile* tempTile = this->getTile(x, y);
	int32 cost = 0;
	Queue.Enqueue(TPair<AboardTile*, int32>(TPairInitializer<AboardTile*, int32>(tempTile,cost)));
	while(!Queue.IsEmpty()) {
		TPair<AboardTile*, int32> tempPair;
		Queue.Dequeue(tempPair);
		tempTile = tempPair.Key;
		cost = tempPair.Value;
		tilesInRange.AddUnique(tempTile);
		TArray<AboardTile*> neighbors = getNeighbors(tempTile->X, tempTile->Y);
		for (int i = 0; i < neighbors.Num(); i++) {
			AboardTile* tempNeighborTile = neighbors[i];
			int32 NeighborCost = cost + tempNeighborTile->MovementCost;
			if (!tilesInRange.Contains(tempNeighborTile) && cost < range) {
				Queue.Enqueue(TPair<AboardTile*, int32>(TPairInitializer<AboardTile*, int32>(tempNeighborTile, NeighborCost)));
			}
		}
	}
	return tilesInRange;
}

