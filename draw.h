/** ***************************************************************************
* @file
* @brief Header file that contains funciton delcarations for toolbox creation, and 
* tool type/color value saving
******************************************************************************/


#ifndef _DRAW_H_
#define _DRAW_H_

#include "menu.h"
#include "graphics.h"

void mainPalleteDraw(vector<MenuItem *> &menuItems);               // main function that draws the toolbox
void DrawPallette(int toolHeight);                                 // draws the frame for the toolbox
void DrawColors(int toolHeight, vector<MenuItem *> &menuItems);    // draws and sets the colors in the toolbox
void DrawTools(int toolHeight, vector<MenuItem *> &menuItems);     // draws and sets the tools in the toolbox
// draws rectangles for the menu colors and saves them
void drawMenuColor(int xStart, int xEnd, int yStart, int yEnd, const float color[],vector<MenuItem *> &menuItems);


#endif
