/** ***************************************************************************
* @file
* @brief Header file that contains constants for the program, and includes the 
* OpenGL library
******************************************************************************/

#ifndef __GRAPHICS_H
#define __GRAPHICS_H
#include <GL/freeglut.h>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const float WHITE[3] = {1, 1, 1};           /*!<White color value */
const float BLACK[3] = {0, 0, 0};           /*!<Black color value */
const float RED[3] = {1.0, 0, 0};           /*!<Red color value */
const float DARKRED[3] = {0.5, 0.05, 0.05}; /*!<Dark Red color value */
const float ORANGE[3] = {1, 0.5, 0};        /*!<Orange color value */
const float DARKORANGE[3] = {0.8, 0.25, 0}; /*!<Dark Orange color value */
const float YELLOW[3] = {1, 0.8, 0};        /*!<Yellow color value */
const float DARKYELLOW[3] = {0.7, 0.65, 0}; /*!<Dark Yellow color value */
const float GREEN[3] = {0.05, 0.9, 0.05};   /*!<Green color value */
const float DARKGREEN[3] = {0.05, 0.4, 0.05};/*!<Dark Green color value */
const float BLUE[3] = {0.05, 0.05, 0.9};    /*!<Blue color value */
const float DARKBLUE[3] = {0, 0.05, 0.4};   /*!<Dark Blue color value */
const float PURPLE[3] = {0.9, 0, 1};        /*!<Purple color value */
const float DARKPURPLE[3] = {0.26, 0, 0.5}; /*!<Dark Purple color value */
const float GRAY[3] = {0.5, 0.5, 0.5};      /*!<Gray color value */
const float DARKGRAY[3] = {0.2, 0.2, 0.2};  /*!<Dark Gray color value */
const char TOOLBAR[20] = " Paint Tools ";   /*!<Tool character string */


#endif
