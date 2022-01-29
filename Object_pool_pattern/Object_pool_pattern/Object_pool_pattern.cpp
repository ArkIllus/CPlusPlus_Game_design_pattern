#include <iostream>
#include <Windows.h>
#include "ParticlePool.h"

int main()
{
    ParticlePool particlePool;
	// try to create 50 particles
	for (int i = 0; i < 50; i++)
	{
		particlePool.create(1, 2, 3, 4, 5);
	}
	
	// 10s
	for (int i = 0; i < 10; i++)
	{
		particlePool.animate();
		std::cout << i << "second, particle animating" << std::endl;
		Sleep(1000);
	}

	std::cout << "end" << std::endl;
}
