/** ***************************************************************************
* @file
* @brief Header file that holds the MenuItem abstract class and it's inherited 
*         successor classes
******************************************************************************/

#ifndef __MENU_H
#define __MENU_H

#include <string>
#include <iostream>

/*!
 * @brief MenuItem class, abstract class that holds location and values for menu item
 */
class MenuItem
{
    protected:
        int xMin;           /*!< the minimum x position of the menu item box */
        int xMax;           /*!< the maximum x position of the menu item box */
        int yMin;           /*!< the minimum y position of the menu item box */
        int yMax;           /*!< the maximum y position of the menu item box */
        std::string type;   /*!< the type/name of menu item */
    public:
        MenuItem(); // Base Constructor for MenuItem
        MenuItem(int xmin, int xmax, int ymin, int ymax, std::string ty);   // Primary constructor for MenuItem

        bool contains(int xLoc, int yLoc);                  // checks to see if the menu item contains the provided point

        virtual void selectCol(float *color);               // sets the selected color
        virtual float* getColor();                          // returns the selected color
        virtual std::string selectTool(int xloc, int yloc); // selects the tool

        std::string getType();                              // returns the type of menu item
};

/*!
 * @brief Color class, inherited from MenuItem, holds a chooseable color value
 */
class Color : public MenuItem 
{    
    protected:
        float color[3];   /*!< The color value tied to the color MenuItem */                                                  // the color value of the color item
    public:        
        Color(int xmin, int xmax, int ymin, int ymax, const float col[]);   // constructs a color item
        float* getColor();                                                  // returns the color value
        void selectCol(float selection[]);                                  // selects the color value
};

/*!
 * @brief Tool Class, inherited form MenuItem, holds a tool type
 */
class Tool : public MenuItem
{
    public:
        Tool (int xmin, int xmax, int ymin, int ymax, std::string ty);      // constructs a tool item
};
#endif