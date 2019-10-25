/** ***************************************************************************
* @file
* @brief cpp file including functions for the util.h, holds the opengl main
* function and the utility central function to be used in callbacks
******************************************************************************/


#include "util.h"


/** **************************************************************************
 * @brief Main event dispatch function
 *
 * Any events to which the application has subscribed will be routed through
 * this function. It will help with saving the state of the program
 *
 * @param[in] event - Pointer to an Event object.
 ******************************************************************************/
void utilityCentral(Event * event)
{
   static vector<Event *> events;      // static vector of events
   static vector<MenuItem *> menuItems;   // static vector of menu items
   static vector<Shape *> shapes;         // static vector of shapes
   static Selections selected;            // static selection instance
   event->action(events, menuItems, shapes, selected);   // the pointed event
}

/** ***************************************************************************
 * @brief   Initialize glut callback functions, set the display mode, create a window
 *
 * @return  none
 *****************************************************************************/
void initOpenGL(int argc, char **argv, int wCols, int wRows)
{
 glutInit(&argc, argv);

// Choose the display mode for the window.  GLUT_DOUBLE means double buffering
// GLUT_SINGLE is single buffering.  GLUT_RGBA is 24-bit color with 8-bit alpha

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

   glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);

// Set window size and position
   glutInitWindowSize(wCols, wRows);

   glutInitWindowPosition(100, 100);

   glutCreateWindow(argv[0]);

// Subscribe to GLUT events

   glutDisplayFunc(display);

   glutKeyboardFunc(keyboard);

   glutMouseFunc(mouseClick);

   glutMotionFunc(mouseDrag);

   glutReshapeFunc(reshape);

   glutPassiveMotionFunc(mouseMove);

   //glutTimerFunc(1000, ticktock, 1000);

   glutCloseFunc(onClose);

// This is the color which will be used to clear the display / back plane
// when glClear() is called
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

// Use the InitEvent object to perform startup operations for the application
   utilityCentral(new Init(wCols, wRows));
}