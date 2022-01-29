#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <string>
using namespace std;

class Character {
    string name;
public:
    Character(): name("player") {}
    void jump();
    void fireGun();
};

#endif