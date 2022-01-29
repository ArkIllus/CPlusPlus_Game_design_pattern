#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#include "Mesh.h"
#include "Texture.h"
#include "Color.h"
#include <vector>
using namespace std;

typedef vector<float> Vector;

class TreeModel
{
private:
	Mesh mesh_;
	Texture bark_;
	Texture leaves_;
};

class Tree
{
private:
	TreeModel* model_;

	Vector position;
	double height_;
	double thickness_;
	Color barkTint_;
	Color leafTint_;
};

#endif // !_TREE_H_
