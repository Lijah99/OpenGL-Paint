/** ***************************************************************************
* @file
* @brief Header file that contains class declarations for Event abstract base class and 
* all others
******************************************************************************/

#ifndef _EVENT_H_
#define _EVENT_H_

#include <iostream>
#include <GL/freeglut.h>
#include <sstream>
#include <vector>
#include <string>

#include "menu.h"
#include "shape.h"
#include "draw.h"
#include "selections.h"


using namespace std;

/*!
 * @brief Abstract Base Event class, calls a virtual action and has a default constructor for program events
 */
class Event
{
    public:
        Event();    // Default constructor for program event
        virtual void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected) = 0; // does action with event, pure virtual function
        virtual ~Event();
};

/*!
 * @brief Initialization Event Class
 */
class Init : public Event
{
    int columns; /*!< the columns of pixels to be initialized */
    int rows;   /*!< the rows of pixels to be initialized */
    public: 
        Init(int c, int r);
        void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected);
};

/*!
 * @brief Display Event Class
 */
class Display : public Event
{
    public:
        void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected); // refreshes the program's display
};

/*!
 * @brief Window Resize Event Class
 */
class ReshapeEvent : public Event
{
   int width;   /*!< the resize width in pixels */
   int height;  /*!< the resize height in pixels */
public:
   ReshapeEvent(int w, int h);
   void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected);
};

/*!
 * @brief Keyboard Key Press Event Class
 */
class KeyPress : public Event
{
    unsigned char key;  /*!< The key pressed */
    int xLoc;           /*!< the x location of the key */
    int yLoc;           /*!< the y location of the key */
public:
    KeyPress(unsigned char k, int x, int y); // constructor
    void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected);  // key action
};

/*!
 * @brief Mouse Click Event Class
 */
class MouseClick : public Event
{
    int button; /*!< the mouse button that was clicked */
    int state; /*!< the button state of the click */
    int xLoc; /*!< the x location of the click */
    int yLoc; /*!< the y location of the click */
public:
   MouseClick( int but, int stat, int x, int y); // constructor for mouse
   void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected);
};

/*!
 * @brief Mouse Drag Event Class
 */
class MouseDrag : public Event
{
    int xLoc;   /*!< the x location of the drag */
    int yLoc;   /*!< the x location of the drag */
public:
    MouseDrag(int x, int y);
    void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected);
};

/*!
 * @brief Mouse Move Event Class
 */
class MouseMove : public Event
{
    int xLoc;   /*!< the x location of the cursor */
    int yLoc;   /*!< the x location of the cursor */
public:
    MouseMove(int x, int y);
    void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected);
};

/*!
 * @brief Program Close Event Class
 */
class CloseEvent : public Event
{
public:
    CloseEvent();   // Close event constructor
    void action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected);
};
#endif