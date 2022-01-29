#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

#include <iostream>

// int BUTTON_X = 0;
// int BUTTON_Y = 1;
// int BUTTON_A = 2;
// int BUTTON_B = 3;
char BUTTON_X = 'x';
char BUTTON_Y = 'y';
//char BUTTON_A = 'a';
//char BUTTON_B = 'b';
char BUTTON_W = 'w';
char BUTTON_A = 'a';
char BUTTON_S = 's';
char BUTTON_D = 'd';

char getButton() {
    char ch;
    cout << "waiting for input ..." << endl;
    cin >> ch;
    return ch;
}

bool isPressed(char button, char ch) {
    //char ch;
    //cout << "waiting for input ..." << endl; 
    //cin >> ch;
    return ch == button;
}

#endif // ! _INPUT_H_