/** ***************************************************************************
* @file
* @brief Cpp file including functions for the menu.cpp, holds all the functions which access
* and alter the MenuItem, Color, and Tool information
******************************************************************************/

#include "menu.h"
// Menu Item
MenuItem::MenuItem(){}

/** **************************************************************************
 * @brief Constructor for a menu item
 *
 * @param[in] xmin - the minimum x location of the menu item selection square
 * @param[in] xmax - the mmaximum x location of the menu item selection square
 * @param[in] ymin - the minimum y location of the menu item selection square
 * @param[in] ymax - the maximum y location of the menu item selection square
 * @param[in] ty - the type of menu item
 ******************************************************************************/
MenuItem::MenuItem(int xmin, int xmax, int ymin, int ymax, std::string ty)
: xMin(xmin), xMax(xmax), yMin(ymin), yMax(ymax), type(ty)
{}

/** **************************************************************************
 * @brief Determines if the point is located in the menu item
 *
 * @param[in] xLoc - the x location of the point 
 * @param[in] yLoc - the y location of the point
 ******************************************************************************/
bool MenuItem::contains(int xLoc, int yLoc)
{
    if (xLoc >= xMin && xLoc <= xMax && yLoc >= yMin && yLoc <= yMax)
    {
        return true;
    }
    return false;
}

/** **************************************************************************
 * @brief Sets the color value associated with the menu item
 ******************************************************************************/
void MenuItem::selectCol(float *col) {}

/** **************************************************************************
 * @brief Returns the color value of the menu item
 ******************************************************************************/
float *MenuItem::getColor() { return {0}; }

/** **************************************************************************
 * @brief sets the menu item's selected tool
 * 
 * @param [in] xloc - x location of the selected tool
 * @param [in] yloc - y location of the selected tool
 ******************************************************************************/
std::string MenuItem::selectTool(int xloc, int yloc) {return "";}

/** **************************************************************************
 * @brief Returns the type of the menu item
 ******************************************************************************/
std::string MenuItem::getType()
{
    return type;
}

// Color
/** **************************************************************************
 * @brief Constructor for a menu item
 *
 * @param[in] xmin - the minimum x location of the color item selection square
 * @param[in] xmax - the mmaximum x location of the color item selection square
 * @param[in] ymin - the minimum y location of the color item selection square
 * @param[in] ymax - the maximum y location of the color item selection square
 * @param[in] col - the color value of the color item
 ******************************************************************************/
Color::Color(int xmin, int xmax, int ymin, int ymax, const float col[])
{
    xMax = xmax; 
    xMin = xmin; 
    yMax = ymax; 
    yMin = ymin;
    type = "color";

    for(int i = 0; i < 3; i++)
        color[i] = col[i];
}

/** **************************************************************************
 * @brief Returns the color value of the color item
 ******************************************************************************/
float* Color::getColor()
{
    return color;
}

/** **************************************************************************
 * @brief Sets the provided color value to the color value of the color item
 * 
 * @param[in,out] selection - the color value being modified by the color of tool
 ******************************************************************************/
void Color::selectCol(float selection[])
{
    for(int i = 0; i < 3; i++)
        selection[i] = color[i];
}

// Tool
/** **************************************************************************
 * @brief Constructor for a tool item
 *
 * @param[in] xmin - the minimum x location of the tool item selection square
 * @param[in] xmax - the mmaximum x location of the tool item selection square
 * @param[in] ymin - the minimum y location of the tool item selection square
 * @param[in] ymax - the maximum y location of the tool item selection square
 * @param[in] ty - the type of tool
 ******************************************************************************/
Tool::Tool(int xmin, int xmax, int ymin, int ymax, std::string ty)
{
    xMax = xmax; 
    xMin = xmin; 
    yMax = ymax; 
    yMin = ymin;
    type = ty;
}
