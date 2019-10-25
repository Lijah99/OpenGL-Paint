/** ***************************************************************************
* @file
* @brief Header file that contains the selected states of the program and can change them
******************************************************************************/

#ifndef __SELECTIONS_H
#define __SELECTIONS_H
#include <string>
#include <iostream>
#include "graphics.h"
#include "shape.h"

/*!
 * @brief Selections Class, holds/changes information about selection states of program
 */
class Selections
{
protected:
        float borderColor[3];   /*!< Selected border color from the toolbox */
        float fillColor[3];     /*!< Selected fill color from the toolbox */
        std::string selectedTool;       /*!< Selected tool type from the toolbox */
        int startX = 0;         /*!< Selected Starting x location */
        int startY = 0;         /*!< Selected Starting u location */
        int endX = 0;           /*!< Saved Ending x location */
        int endY = 0;           /*!< Saved Ending y location */
        bool dragOccurred = false;      /*!< describes whether a drag has occurred */
        bool leftClickOccurred = false; /*!< describes whether a left click has occurred */
        Shape *selectedShape;           /*!< pointer to a shape class */
public: 
        Selections();                           // constructor
        // ***Accessors & setters***
        void setBorderColor(float col[]);       // sets selected border color
        void setFillColor(float col[]);         // sets selected fill color
        void setTool(std::string tool);         // sets selected tool
        float* getBorderColor();                // returns selected border color
        float* getFillColor();                  // returns selected fill color
        std::string getTool();                  // returns selected tool

        int getStartX();                        // returns starting x location
        int getStartY();                        // returns starting y location
        int getEndX();                          // returns ending x location
        int getEndY();                          // returns ending y location
        void setStartX(int x);                  // sets the starting x location
        void setStartY(int y);                  // sets the starting y location
        void setEndX(int x);                    // sets the ending x location
        void setEndY(int y);                    // sets the ending y location

        bool getDragStatus();                   // returns the mouse's drag status
        void setDragStatus(bool set);           // stes the mouse's drag status

        bool getLeftClickStatus();              // returns the mouse's left click status
        void setLeftCLickStatus(bool set);      // sets the mouse's left click status

        Shape * getSelectedShape();             // returns the selected shape
        void setSelectedShape(Shape * select);  // sets the selected shape
        
        // ***Shape Manimpulators***
        void bringToFront(vector<Shape *> &shapes, int xLoc, int yLoc); // brings the selected shape to the end of a vector and front of program
        void moveShape(vector<Shape *> &shapes, int xLoc, int yLoc);    // moves the selected shape around based on a drag action
};

#endif