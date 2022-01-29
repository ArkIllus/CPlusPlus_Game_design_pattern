//����������ɣ��е�MC���������ӵ�ζ����

#include "World.h"
#include "Terrain.h"
#include "Tree.h"
#include <iostream>
using namespace std;

int main()
{
	World world;
	world.generateTerrain();
	int cost = world.getTile(2, 3).getMoveCost();
	bool isWater = world.getTile(2, 3).isWater();
	cout << "[2,3] cost = " << cost << endl;
	cout << "[2,3] isWater = " << isWater << endl;

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			int cost = world.getTile(i, j).getMoveCost();
			cout << cost << " ";
		}
		cout << endl;
	}
	return 0;
}