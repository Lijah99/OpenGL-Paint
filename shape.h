/** ***************************************************************************
* @file
* @brief Header file that holds all the shape classes used in the paint program
******************************************************************************/

#ifndef __SHAPE_H
#define __SHAPE_H

#include <string>
#include <iostream>
#include "graphics.h"


/****************************************************************************
 *                          BASE SHAPE CLASS
 * **************************************************************************/

/*!
 * @brief Base class for a specific shape
 */
class Shape 
{
protected:
    std::string name;     /*!< the name/tyep of the shape */
    int xLoc;             /*!< the x location of the shape */
    int yLoc;             /*!< the y location of the cursor */
    float fillColor[3];   /*!< the fill color of the shape */
    float borderColor[3]; /*!< the border color of the shape */
public:
    Shape();    // shape constructor
    ~Shape();   // shape destructor
    virtual bool contains(int x, int y) = 0;    // checks to see if point is contained in shape
    virtual void draw() = 0;                       // draws the shape
    void setFillColor(const float col[]);       // sets the fill color of the shape
    void setBorderColor(const float col[]);     // sets the border color of the shape
    int getXLoc();                              // returns the x location of the shape
    void setXLoc(int x);                        // sets the x location of the shape
    int getYLoc();                              // returns the y location of the shape
    void setYLoc(int y);                        // sets the y location of the shape
    std::string getName();                      // returns the name/type of the shape
};

/****************************************************************************
 *                          LINE CLASSES
 * **************************************************************************/
/*!
 * @brief Base class for a Line
 */
class Line : public Shape
{
protected:
    int height;   /*!< Height of the line from start to end*/
    int width;    /*!< Width of the line from start to end */
public:
    Line(int x, int y, int h, int w, const float bcol[], std::string nm = "Line"); // constructor for line
    bool contains(int x, int y);    // returns whether the point is on the line
    void draw();    // draws the line
};
/****************************************************************************
 *                          RECTANGLE CLASSES
 * **************************************************************************/
/*!
 * @brief Base class for a unfilled rectangle
 */
class Rectangle : public Shape
{
protected:
    int height; /*!< Height of the rectangle */
    int width;  /*!< Width of the rectangle */
public:
    /// rectangle constructor, sets all the properties
    Rectangle(int x, int y, int h, int w, const float bcol[], std::string nm = "Rectangle");
    Rectangle();
    bool contains(int x, int y);    // checks to see if the point is contained in shape
    void draw();                    // draws the rectangle
};

/*!
 * @brief Base class for a filled rectangle
 */
class FilledRectangle : public Rectangle
{
public:
    FilledRectangle(int x, int y, int h, int w, const float bcol[], const float fcol[], std::string nm = "FilledRectangle");
    void draw();
};

/*!
 * @brief Base class for a unfilled circle
 */
class Circle : public Shape
{
protected:
    int radius; /*!< the radius of the circle */
public:
    Circle(int x, int y, int r, const float bcol[], std::string nm = "Circle"); // circle constructor
    Circle();
    bool contains(int x, int y);    // checks to see if the point is contained in the circle
    void draw();                    // draws the circle
};

/*!
 * @brief Base class for a filled circle
 */
class FilledCircle : public Circle
{
public:
    FilledCircle(int x, int y, int r, const float bcol[], const float fcol[], std::string nm = "Circle"); // circle constructor
    void draw();    // draws the circle
};


/****************************************************************************
 *                          ELLIPSE CLASSES
 * **************************************************************************/
/*!
 * @brief Base class for a unfilled ellipse
 */
class Ellipse : public Shape
{
protected:
    int radiusX; /*!< the x axis radius of the ellipse */
    int radiusY; /*!< the y axis radius of the ellipse */
public:
    Ellipse(int x, int y, int xrad, int yrad, const float bcol[], std::string nm = "Ellipse");
    Ellipse(); // default constructor for the ellipse
    bool contains(int x, int y);    // returns whether the point is contained in the ellipse
    void draw();    // draws the ellipse
};

/*!
 * @brief Base class for a filled ellipse
 */
class FilledEllipse : public Ellipse
{
public:
    FilledEllipse(int x, int y, int xrad, int yrad, const float bcol[], const float fcol[], std::string nm = "Ellipse"); // constructor of ellipse
    void draw();    // draws the ellipse
};
#endif
