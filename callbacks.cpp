/** ***************************************************************************
* @file
* @brief Cpp file including functions for the callbacks.h, holds all the functions which are used
* as callback functions for the OpenGL event chain. Examples include keyboard callback, display callback,
* and mouse click callback
******************************************************************************/

#include "callbacks.h"

/** **************************************************************************
 * @brief returns the actual y location 
 *
 * This will take a y value and subtract it from Glut's value of the window
 * This is to transfer glut's y to our own representation
 * 
 * @param[in] y - Our y value/location to be modified according to glut's y location
 ******************************************************************************/
int actualY(int y)
{
   return glutGet(GLUT_WINDOW_HEIGHT) - y;
}

/** **************************************************************************
 * @brief KeyPress/Keyboard callback function
 *
 * @param[in] key - char value of key that was pressed
 * @param[in] x - x location where the key was pressed
 * @param[in] y - y location where the key was pressed
 ******************************************************************************/
void keyboard(unsigned char key, int x, int y)
{
      if (key == 27)
   {
      glutLeaveMainLoop();
      return;
   }
   utilityCentral(new KeyPress(key, x, actualY(y)));
}

/** **************************************************************************
 * @brief Mouse Click callback function
 *
 * @param[in] button - mouse button that was clicked
 * @param[in] state - the state of the button i.e. down, up, etc.
 * @param[in] x - x location where the button was pressed
 * @param[in] y - y location where the button was pressed
 ******************************************************************************/
void mouseClick(int button, int state, int x, int y)
{
   utilityCentral(new MouseClick(button, state, x, actualY(y)));
}

/** **************************************************************************
 * @brief Mouse drag callback function
 *
 * @param[in] x - x location where the mouse was dragged to
 * @param[in] y - y location where the mouse was dragged to
 ******************************************************************************/
void mouseDrag(int x, int y)
{
   utilityCentral(new MouseDrag(x, actualY(y)));
}

/** **************************************************************************
 * @brief Passive mouse move callback function
 *
 * @param[in] x - x location where the mouse is located
 * @param[in] y - y location where the mouse is located
 ******************************************************************************/
void mouseMove(int x, int y)
{
   utilityCentral(new MouseMove(x, actualY(y)));
}

/** **************************************************************************
 * @brief The display callback function
 *
 * This event should occur whenever anything is done with the display i.e. a refresh
 * 
 * It will clear the screen, redraw all the stored shapes, redraw the toolbox, and swap buffers
 ******************************************************************************/
void display()
{
   utilityCentral(new Display());
}

/** **************************************************************************
 * @brief Window reshape callback function
 *
 * @param[in] w - width of resized window
 * @param[in] h - height of resized window
 ******************************************************************************/
void reshape(const int w, const int h)
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    // project 3d world space into 2d
    gluOrtho2D(0.0, w, 0.0, h);
    // point the camera at the 2d projection
    glViewport(0,0,w,h);
    // dispatch the reshape event
    utilityCentral(new ReshapeEvent(w, h));
}

/** **************************************************************************
 * @brief Program close callback function 
 ******************************************************************************/
void onClose()
{
   utilityCentral(new CloseEvent());
}