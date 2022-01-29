#include "Spawner.h"
#include "Monster.h"
#include "Ghost.h"
#include "Slime.h"
#include <iostream>
using namespace std;

int main()
{
	// 书上的也太少了???
	// 还可以改进：在Spawner里加一个哈希表，而不是只有一个Monster* prototype_;

	// ===============非泛型 幽灵===============
	//Ghost* ghostPrototype = new Ghost(15, 3); //???
	Monster* ghostPrototypeA = new Ghost(15, 3);
	Spawner* ghostSpawner = new Spawner(ghostPrototypeA);

	Monster* ghostList[20];
	//Ghost* ghostList[20]; //???
	for (int i = 0; i < 10; i++)
	{
		ghostList[i] = ghostSpawner->spawnMonster();
		//E0513 不能将 "Monster *" 类型的值分配到 "Ghost *" 类型的实体
		//【解决办法】1.static_cast 2.dynamic_cast
	}

	// ===============泛型 幽灵===============
	Monster* ghostPrototypeB = new Ghost(10, 2);
	SpawnerFor<Ghost>* ghostSpawnerFor = new SpawnerFor<Ghost>(ghostPrototypeB);
	for (int i = 10; i < 20; i++)
	{
		ghostList[i] = ghostSpawnerFor->spawnMonster();
		//E0513 不能将 "Monster *" 类型的值分配到 "Ghost *" 类型的实体
		//【解决办法】1.static_cast 2.dynamic_cast
	}
	for (int i = 0; i < 20; i++)
	{
		ghostList[i]->print();
	}

	// ===============泛型 史莱姆（并使用static_cast、dynamic_cast<Slime*>进行下行转换）===============
	//Monster* slimeList[5];
	Slime* slimeList[5];
	Monster* slimePrototypeA = new Slime(8, 1);
	SpawnerFor<Slime>* slimeSpawnerFor = new SpawnerFor<Slime>(slimePrototypeA);
	for (int i = 0; i < 5; i++)
	{
		//slimeList[i] = slimeSpawnerFor->spawnMonster();
		//E0513 不能将 "Monster *" 类型的值分配到 "Ghost *" 类型的实体
		//【解决办法】1.static_cast 2.dynamic_cast
		slimeList[i] = dynamic_cast<Slime*>(slimeSpawnerFor->spawnMonster());
	}
	for (int i = 0; i < 5; i++)
	{
		slimeList[i]->print();
	}

	cout << "end" << endl;
}