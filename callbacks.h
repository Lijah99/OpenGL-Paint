/** ***************************************************************************
* @file
* @brief Header file that contains callback function declarations to be used by 
* the glut utility/main loop
******************************************************************************/

#ifndef __CALLBACKS_H
#define __CALLBACKS_H

#include "event.h"
#include "util.h"

using namespace std;

void keyboard(unsigned char key, int x, int y);         // Keyboard callback function
void display();                                         // Display event callback function
void mouseClick(int button, int state, int x, int y);   // Mouse Click callback function
void mouseDrag(int x, int y);                           // Mouse Drag callback funciton
void mouseMove(int x, int y);                           // Mouse Move callback function
void reshape(const int w, const int h);                 // Window reshape callback function
void onClose();                                         // Program close callback function

#endif