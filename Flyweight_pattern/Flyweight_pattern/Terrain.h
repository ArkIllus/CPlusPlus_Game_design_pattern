#pragma once
#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include "Texture.h"

//地形
class Terrain
{
public:
	Terrain(int moveCost, bool isWater, Texture texture):
		moveCost_(moveCost), isWater_(isWater), texture_(texture) {}

	int getMoveCost() const { return moveCost_; }
	bool isWater() const { return isWater_; }
	const Texture& getTexture() const { return texture_; }
private:
	int moveCost_;
	bool isWater_;
	Texture texture_;
};

#endif // !_TERRAIN_H_
