/** ***************************************************************************
* @file
* @brief Cpp file including functions for the draw.h, holds all functions which create the 
* toolbox window, it's colors, and tools. It them saves them all
******************************************************************************/

#include "draw.h"

/**
 * @brief The main toolbox/pallete draw function
 * 
 * It will take in a vector of menu items, then populate that vector after
 * 
 * 1 Drawing the pallette framework
 * 2 Drawing the color items and adding them to the menu items
 * 3 Drawing the tool items and adding them to the menu items
 * 
 * If the program window shrinks to below its initial size, the toolbox will not scale down anymore
 * This is preferable to unlimited scaling to small sizes
 * 
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 */
void mainPalleteDraw(vector<MenuItem *> &menuItems)
{  
   // clear menu items
   menuItems.clear();

   // set minimum window height and width for scaling
   int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
   int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
   if (windowHeight < 480)
      windowHeight = 480;
   if (windowWidth < 640)
      windowWidth = 640;
   int toolHeight = windowHeight / 13;

   // draw toolbox, colors, and tools
   DrawPallette(toolHeight);
   DrawColors(toolHeight, menuItems);
   DrawTools(toolHeight, menuItems);
}

/** **************************************************************************
 * @brief Draws the framework for the toolbox/pallette
 *
 * @param[in] toolHeight - The height of the menu/tool items in the toolbox
 ******************************************************************************/
void DrawPallette(int toolHeight)
{
   // Background
   glColor3fv(WHITE);
   glBegin(GL_POLYGON);
      glVertex2f(0, 0);
      glVertex2f(101, 0);
      glVertex2f(101, 12 * toolHeight);
      glVertex2f(0, 12 * toolHeight);
   glEnd();

   //Text at top
   int length = strlen(TOOLBAR);
   glRasterPos2f(0, 12 * toolHeight);
   for (int i = 0; i < length; i++)
   glutBitmapCharacter (GLUT_BITMAP_8_BY_13, TOOLBAR[i]);

   //Half Divider
   glColor3fv(BLACK);
   glBegin(GL_LINES);
      glVertex2f(50, 0);
      glVertex2f(50, 12 * toolHeight);
   glEnd();

   //Tool Brackets
   float dividerHeight = 8 *toolHeight;
   for (int i = 0; i < 4; i++)
   {
      glBegin(GL_LINES);
         glVertex2f(0, dividerHeight);
         glVertex2f(101, dividerHeight);
      glEnd();
      dividerHeight += toolHeight;
   }
}

/**
 * @brief Draws and saves the color items in the toolbox
 *
 * @param[in] toolHeight - The height of the menu/tool items in the toolbox
 * @param[in,out] menuItems - The vector of menuItems where all the color items will be saved
 */
void DrawColors(int toolHeight, vector<MenuItem *> &menuItems)
{
   // LEFT COLORS
   drawMenuColor(1,49,0,toolHeight,WHITE,menuItems);
   drawMenuColor(1,49,toolHeight,2*toolHeight,RED,menuItems);
   drawMenuColor(1,49,2*toolHeight,3*toolHeight,ORANGE,menuItems);
   drawMenuColor(1,49,3*toolHeight,4*toolHeight,YELLOW,menuItems);
   drawMenuColor(1,49,4*toolHeight,5*toolHeight,GREEN,menuItems);
   drawMenuColor(1,49,5*toolHeight,6*toolHeight,BLUE,menuItems);
   drawMenuColor(1,49,6*toolHeight,7*toolHeight,PURPLE,menuItems);
   drawMenuColor(1,49,7*toolHeight,8*toolHeight,GRAY,menuItems);
   // RIGHT COLORS
   drawMenuColor(50,100,0,toolHeight,BLACK,menuItems);
   drawMenuColor(50,100,toolHeight,2*toolHeight,DARKRED,menuItems);
   drawMenuColor(50,100,2*toolHeight,3*toolHeight,DARKORANGE,menuItems);
   drawMenuColor(50,100,3*toolHeight,4*toolHeight,DARKYELLOW,menuItems);
   drawMenuColor(50,100,4*toolHeight,5*toolHeight,DARKGREEN,menuItems);
   drawMenuColor(50,100,5*toolHeight,6*toolHeight,DARKBLUE,menuItems);
   drawMenuColor(50,100,6*toolHeight,7*toolHeight,DARKPURPLE,menuItems);
   drawMenuColor(50,100,7*toolHeight,8*toolHeight,DARKGRAY,menuItems);
}

/**
 * @brief Draws a rectangle for the menu colors based off information passed and saves them as a MenuItem
 * 
 * @param xStart  - starting x location of the color box
 * @param xEnd    - ending x location of the color box 
 * @param yStart  - starting y location of the color box
 * @param yEnd    - ending y location of the color box
 * @param color   - color value of the drawn color box
 * @param menuItems  - vector containing saved menu items and their locations/properties 
 */
void drawMenuColor(int xStart, int xEnd, int yStart, int yEnd, const float color[],vector<MenuItem *> &menuItems)
{
   glColor3fv(color);
   glBegin(GL_POLYGON);
      glVertex2f(xStart, yStart);
      glVertex2f(xEnd, yStart);
      glVertex2f(xEnd, yEnd);
      glVertex2f(xStart, yEnd);
   glEnd();
   menuItems.push_back(new Color(xStart,xEnd,yStart,yEnd,color));
}

/** **************************************************************************
 * @brief Draws and saves the tools in the toolbox
 *
 * @param[in] toolHeight - The height of the menu/tool items in the toolbox
 * @param[in,out] menuItems - The vector of menuItems where all the tool/shape items will be saved
 ******************************************************************************/
void DrawTools(int toolHeight, vector<MenuItem *> &menuItems)
{
      glColor3fv( BLACK );       // Unfilled Square
   glBegin(GL_LINE_LOOP);
      glVertex2f(5, 8 * toolHeight + 4);
      glVertex2f(45, 8 * toolHeight + 4);
      glVertex2f(45, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(5, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(5, 8 * toolHeight + 4);
      glVertex2f(5, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(45, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(45, 8 * toolHeight + 4);           
   glEnd();
   menuItems.push_back(new Tool(0,49,8 * toolHeight,9 * toolHeight,"unfilledSquare"));

      glColor3fv(GRAY);             // Filled Square
   glBegin(GL_POLYGON);
      glVertex2f(55, 8 * toolHeight + 4);
      glVertex2f(95, 8 * toolHeight + 4);
      glVertex2f(95, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(55, 8 * toolHeight + (toolHeight / 1.15));
   glEnd();

      glColor3fv( RED );   
   glBegin(GL_LINE_LOOP);
      glVertex2f(55, 8 * toolHeight + 4);
      glVertex2f(95, 8 * toolHeight + 4);
      glVertex2f(95, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(55, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(55, 8 * toolHeight + 4);
      glVertex2f(55, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(95, 8 * toolHeight + (toolHeight / 1.15));
      glVertex2f(95, 8 * toolHeight + 4);           
   glEnd();
   menuItems.push_back(new Tool(50,100,8 * toolHeight,9 * toolHeight,"filledSquare"));

   float theta;                
      glColor3fv(BLACK);      // Unfilled Circle
   glBegin(GL_LINE_LOOP);
   for(int i = 0; i < 360; i++)
   {
      theta = i * 3.142 / 180;
      glVertex2f(25 + 15*cos(theta), (9 * toolHeight + (toolHeight / 2)) + 15*sin(theta));
   }
   glEnd();
   menuItems.push_back(new Tool(0,49,9 * toolHeight,10 * toolHeight,"unfilledCircle"));

      glColor3fv(GRAY); // Filled Circle
   glBegin(GL_POLYGON);
   for(int i = 0; i < 360; i++)
   {
      theta = i * 3.142 / 180;
      glVertex2f(75 + 15*cos(theta), (9 * toolHeight + (toolHeight / 2)) + 15*sin(theta));
   }
   glEnd();
      glColor3fv(RED);
   glBegin(GL_LINE_LOOP);
   for(int i = 0; i < 360; i++)
   {
      theta = i * 3.142 / 180;
      glVertex2f(75 + 15*cos(theta), (9 * toolHeight + (toolHeight / 2)) + 15*sin(theta));
   }
   glEnd();
   menuItems.push_back(new Tool(50,100,9 * toolHeight,10 * toolHeight,"filledCircle"));
              
      glColor3fv(BLACK);      // Unfilled Ellipse
   glBegin(GL_LINE_LOOP);
   for(int i = 0; i < 360; i++)
   {
      theta = i * 3.142 / 180;
      glVertex2f(25 + 22*cos(theta), (10 * toolHeight + (toolHeight / 2)) + 15*sin(theta));
   }
   glEnd();
   menuItems.push_back(new Tool(0,49,10 * toolHeight,11 * toolHeight,"unfilledEllipse"));

      glColor3fv(GRAY); // Filled Ellipse
   glBegin(GL_POLYGON);
   for(int i = 0; i < 360; i++)
   {
      theta = i * 3.142 / 180;
      glVertex2f(75 + 22*cos(theta), (10 * toolHeight + (toolHeight / 2)) + 15*sin(theta));
   }
   glEnd();
      glColor3fv(RED);
   glBegin(GL_LINE_LOOP);
   for(int i = 0; i < 360; i++)
   {
      theta = i * 3.142 / 180;
      glVertex2f(75 + 22*cos(theta), (10* toolHeight + (toolHeight / 2)) + 15*sin(theta));
   }
   glEnd();
   menuItems.push_back(new Tool(50,100,10 * toolHeight,11 * toolHeight,"filledEllipse"));

      glColor3fv(BLACK);   // Line
   glBegin(GL_LINE_LOOP);
      glVertex2f(3, 12 * toolHeight - 3);
      glVertex2f( 47, 11 * toolHeight + 3);          
   glEnd();
   menuItems.push_back(new Tool(0,50,11 * toolHeight,12 * toolHeight,"line"));
}
