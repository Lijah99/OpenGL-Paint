/** ***************************************************************************
* @file
* @brief cpp file including functions for the selections.h, holds the function
* definitions
******************************************************************************/
#include "selections.h"

/** **************************************************************************
 * @brief Constructor for the selections class
 *
 * Creates a defaulted instance of selected tools
 ******************************************************************************/
Selections::Selections()
{
    for(int i = 0; i < 3; i++)
    {
        borderColor[i] = WHITE[i];  // Set default border to white, default fill red
        fillColor[i] = RED[i];
    }
}

/** **************************************************************************
 * @brief Sets the selected border color from the toolbox
 *
 * @param[in] col - the border color that has been selected
 ******************************************************************************/
void Selections::setBorderColor(float col[])
{
    for(int i = 0; i < 3; i++)
        borderColor[i] = col[i];
}

/** **************************************************************************
 * @brief Sets the selected fill color from the toolbox
 *
 * @param[in] col - the fill color that has been selected
 ******************************************************************************/
void Selections::setFillColor(float col[])
{
    for(int i = 0; i < 3; i++)
        fillColor[i] = col[i];
}

/** **************************************************************************
 * @brief Sets the selected tool/shape from the toolbox
 *
 * @param[in] tool - the tool/shape that has been selected
 ******************************************************************************/
void Selections::setTool(std::string tool)
{
    selectedTool = tool;
}

/** **************************************************************************
 * @brief Returns the selected border color on the toolbox
 ******************************************************************************/
float* Selections::getBorderColor()
{
    return borderColor;
}

/** **************************************************************************
 * @brief Returns the selected border color on the toolbox
 ******************************************************************************/
float* Selections::getFillColor()
{
    return fillColor;
}

/** **************************************************************************
 * @brief Returns the selected border color on the toolbox
 ******************************************************************************/
std::string Selections::getTool()
{
    return selectedTool;
}

/** **************************************************************************
 * @brief Returns the selected starting x location.
 ******************************************************************************/
int Selections::getStartX()
{
    return startX;
}

/** **************************************************************************
 * @brief Sets the the selected starting x location to be saved.
 * 
 * @param [in] x - selected starting x location to be saved.
 ******************************************************************************/
void Selections::setStartX(int x)
{
    startX = x;
}

/** **************************************************************************
 * @brief Returns the selected starting x location.
 ******************************************************************************/
int Selections::getStartY()
{
    return startY;
}

/** **************************************************************************
 * @brief Sets the the selected starting y location to be saved.
 * 
 * @param [in] y - selected starting y location to be saved.
 ******************************************************************************/
void Selections::setStartY(int y)
{
    startY = y;
}

/** **************************************************************************
 * @brief Returns the seleceted and saved ending x location, endX.
 ******************************************************************************/
int Selections::getEndX()
{
    return endX;
}

/** **************************************************************************
 * @brief Sets the seleceted and saved ending x location, endX.
 * 
 * @param[in] x - selected x end location to be saved.
 ******************************************************************************/
void Selections::setEndX(int x)
{
    endX = x;
}

/** **************************************************************************
 * @brief Returns the seleceted and saved ending y location, endY.
 ******************************************************************************/
int Selections::getEndY()
{
    return endY;
}

/** **************************************************************************
 * @brief Sets the seleceted and saved ending y location, endY.
 * 
 * @param[in] y - selected y end location to be saved.
 ******************************************************************************/
void Selections::setEndY(int y)
{
    endY = y;
}

/** **************************************************************************
 * @brief Returns the drag status of the mouse action and program
 ******************************************************************************/
bool Selections::getDragStatus()
{
    return dragOccurred;
}

/** **************************************************************************
 * @brief Sets the latest drag status
 * 
 * @param[in] set - updated drag status boolean value
 ******************************************************************************/
void Selections::setDragStatus(bool set)
{
    dragOccurred = set;
}

/** **************************************************************************
 * @brief Returns the latest left click status of the program
 ******************************************************************************/
bool Selections::getLeftClickStatus()
{
    return leftClickOccurred;
}

/** **************************************************************************
 * @brief Sets the latest left click status
 * 
 * @param[in] set - updated left click status status boolean value, leftClickOccurred
 ******************************************************************************/
void Selections::setLeftCLickStatus(bool set)
{
    leftClickOccurred = set;
}



/** **************************************************************************
 * @brief Brings the right-clicked shape to the front of the screen and selects it.
 * 
 * It accommodates for an empty paint area.
 *
 * @param[in,out] shapes - vector of saved shapes that have been drawn in the paint area
 * @param[in] xLoc - x location of the mouse right click
 * @param[in] yLoc - y location of the mouse right click
 ******************************************************************************/
void Selections::bringToFront(vector<Shape *> &shapes, int xLoc, int yLoc)
{
    int latest = -1;
    for(int i = 0; i < int(shapes.size()); i++)
    {
        if(shapes[i]->contains(xLoc,yLoc))
        {
            latest = i;
        }
        if(shapes.size() == 0)
        {
            setSelectedShape(shapes[0]);
        }
    }
    if(latest != -1)
    {
        shapes.push_back(shapes[latest]);
        shapes[latest]->draw();
        shapes.erase(shapes.begin() + latest);
        setSelectedShape(shapes[latest]);
        glFlush();
    }
}

/** **************************************************************************
 * @brief Sets the latest selected shape.
 * 
 * @param[in] select - the shape that is being selected and set for persistence
 ******************************************************************************/
void Selections::setSelectedShape(Shape * select)
{
    selectedShape = select;
}

/** **************************************************************************
 * @brief Returns the latest selected shape.
 ******************************************************************************/
Shape * Selections::getSelectedShape()
{
    return selectedShape;
}

/** **************************************************************************
 * @brief Moves the shape that has been both selected and dragged with the right mouse button.
 * 
 * It will redraw the shape after every mouse drag event based off where the shape
 * is being dragged.
 *
 * @param[in,out] shapes - vector of saved shapes that have been drawn in the paint area
 * @param[in] xLoc - x location of the mouse right click
 * @param[in] yLoc - y location of the mouse right click
 ******************************************************************************/
void Selections::moveShape(vector<Shape *> &shapes, int xLoc, int yLoc)
{
    int distanceXStart = startX;
    int distanceYStart = startY;

    shapes.back()->setXLoc(xLoc - distanceXStart);
    shapes.back()->setYLoc(yLoc - distanceYStart);
}