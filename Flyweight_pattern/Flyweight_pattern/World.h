#pragma once
#ifndef _World_H_
#define _World_H_

#include "Texture.h"
#include "Terrain.h"

#define WIDTH 10 //二维世界宽度
#define HEIGHT 10 //二维世界高度

class World
{
private:
	Terrain* tiles_[WIDTH][HEIGHT]; //指向地形对象的网格【指针】
private:
	//地形实例，直接存储在世界中，并在世界的构造函数中初始化
	Terrain grassTerrain_;
	Terrain hillTerrain_;
	Terrain riverTerrain_;
	//other stuff...
public:
	World(): grassTerrain_(1, false, GRASS_TEXTURE),
		hillTerrain_(3, false, HILL_TEXTURE),
		riverTerrain_(2,true,RIVER_TEXTURE){} //tiles_的初始化放在generateTerrain()里 //思考：但这是否有点不安全？
	void generateTerrain(); //生成随机地形
	const Terrain& getTile(int x, int y) const; //获取某一个位置的地形
												//重点是 这样一来，成功把world和地形解耦
};
#endif // !_World_H_
