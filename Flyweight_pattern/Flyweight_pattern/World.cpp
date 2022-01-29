#include "World.h"
#include <random>
#include <time.h>
using namespace std;

void World::generateTerrain()
{
	srand(time(0)); //设置rand()产生随机数时的随机数种子
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			// Sprinkle some hills
			//if (random(10) == 0) {
			if (rand() % 10 == 0) {
				tiles_[i][j] = &hillTerrain_;
			}
			// Fill the ground with grass
			else {
				tiles_[i][j] = &grassTerrain_;
			}
		}
	}

	// Lay a river
	//int x = random(WIDTH);
	int x = rand() % WIDTH;
	for (int y = 0; y < HEIGHT; y++)
	{
		tiles_[x][y] = &riverTerrain_;
	}
}

const Terrain& World::getTile(int x, int y) const
{
	return *tiles_[x][y];
}
