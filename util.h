/** ***************************************************************************
* @file
* @brief Header file that contains the functions which initiate OpenGL loop
* and the function that saves the static information for the program
******************************************************************************/

#ifndef __UTIL_H
#define __UTIL_H
#include <GL/freeglut.h>
#include <cstring>
#include <vector>
#include "event.h"
#include "callbacks.h"


using namespace std;

void initOpenGL(int argc, char **argv, int wCols, int wRows);   // central OpenGL function
void utilityCentral(Event * event);     // Utility function which holds state of program
#endif
