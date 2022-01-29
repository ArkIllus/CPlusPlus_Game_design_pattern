#pragma once
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

class Texture
{
	int kind;
public:
	Texture(): kind(0){}
	Texture(int x): kind(x){}
};

// global var
extern Texture GRASS_TEXTURE;
extern Texture HILL_TEXTURE;
extern Texture RIVER_TEXTURE;

#endif // !_TEXTURE_H_