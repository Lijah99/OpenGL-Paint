/** ***************************************************************************
 * @file
 *
 * @brief main program file to the paint program
 *
 * @mainpage Program 1 - Paint
 *
 * @section course_section Course Information
 *
 * @authors Elijah Flinders and Vytautas Soderholm
 *
 * @date October 1, 2019
 *
 * @par Professor:
 *         Paul Hinker
 *
 * @par Course:
 *         CSC 315
 *
 *
 * @section program_section Program Information
 *
 * @details This is a program that emulates a generic, windows/linux
 * based paint program.
 * 
 * There are 16 colors that can be chosen, both of which an be applied to either the 
 * fill or the border of a shape. Left clicking selects the color clicked to be the border color of 
 * the shape. Right clicking sets the fill color of the shape.
 * 
 * 
 * For shapes, either a rectangle, circle, ellipse, or line can be drawn. They can be selected by 
 * left clicking.
 * 
 * To draw, left clicking and dragging to a desired location will draw the sized shape.
 * 
 * These shapes can be selected with the right mouse button and dragged around. 
 * If a shape is selected, the d key will delete it from the paint area
 * 
 * If escape or q is pressed, the program will close immediately. 
 * If c is pressed, it will clear all objects from the paint area
 * 
 * Resizing the window does not affect the paint area other than expanding or 
 * shrinking it. The shapes there will persiste unless deleted.
 * 
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   ./paint
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug None
 *
 * @todo -Have code that doesn't look terrible... 
 *
 * <a href="https://gitlab.mcs.sdsmt.edu/7365329/csc315_fall2019_project1.git"
   target="_blank">The Gitlab Commit Log</a>
 *
 *
 *****************************************************************************/

#include "util.h"

/** **************************************************************************
 * @author Elijah & Vytaus
 *
 * @par Description:
 *      This Function starts the program and enters the OpenGL loop, making
 * the program funciton
 *
 * @param[in]      argc - a count of the command line arguments used to start
 *                        the program.
 * @param[in]     argv - a 2d character array of each argument.  Each token
 *                        occupies one line in the array.
 *
 * @returns 0 program ran succesfully.
 * @returns 1 The program ran into an error
 *
 *****************************************************************************/
int main(int argc, char** argv)
{
   initOpenGL(argc, argv, 640, 480);

   glutMainLoop();
   
   return 0;
}