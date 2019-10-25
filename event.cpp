/** ***************************************************************************
* @file
* @brief Cpp file including functions for the event.cpp, holds all the functions which occurr and 
* change the program based off the actions by the user. Example: Clicks, Drags, Resize, Refresh Display
******************************************************************************/

#include "event.h"

/** **************************************************************************
 * @brief Default constructor for the abstract event class
 ******************************************************************************/
Event::Event () {}

/** **************************************************************************
 * @brief The pure virtual event action function
 *
 * It will be used to force every inherited class to make a version of the action function
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void Event::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected) {}

/** **************************************************************************
 * @brief Default destructor for the abstract shape class
 ******************************************************************************/
Event::~Event() {} // Base Deconstructor

/** **************************************************************************
 * @brief The display action
 *
 * This event should occur whenever anything is done with the display i.e. a refresh
 * 
 * It will clear the screen, redraw all the stored shapes, redraw the toolbox, and swap buffers
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void Display::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected)
{
   glClear(GL_COLOR_BUFFER_BIT);          // clear screen
   for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
      shapes[i]->draw();

   mainPalleteDraw(menuItems);            // redraw all the menu items
   glFlush();                     // swap the buffers 
}  

/** **************************************************************************
 * @brief Constructor
 *
 * This event should only happen once on initial startup. Clears the buffer/screen
 *
 * @param[in] c - columns (in pixels) of the window
 * @param[in] r - rows (in pixels) of the window
 ******************************************************************************/
Init::Init(int r, int c) : columns(c), rows(r) {}

/** **************************************************************************
 * @brief The program initialization action
 *
 * This event should only happen once on initial startup. Clears the buffer/screen
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void Init::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected)
{
   glClear(GL_COLOR_BUFFER_BIT); // clear screen on initialization
}

/** **************************************************************************
 * @brief Constructor
 *
 * Constructs the reshaping event when window resized
 *
 * @param[in] w - width of resized window
 * @param[in] h - height of resized window
 ******************************************************************************/
ReshapeEvent::ReshapeEvent(int w, int h) : width(w), height(h) {}

/** **************************************************************************
 * @brief The program screen reshape action
 *
 * This action will occur when the screen is resized
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void ReshapeEvent::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected) {}

/** **************************************************************************
 * @brief Constructor for the key press action
 *
 * @param[in] k - char value of key that was pressed
 * @param[in] x - x location where the key was pressed
 * @param[in] y - y location where the key was pressed
 ******************************************************************************/
KeyPress::KeyPress(unsigned char k, int x, int y) : key(k), xLoc(x), yLoc(y) {}

/** **************************************************************************
 * @brief The key press action
 *
 * This event checks for the key that was pressed.
 * If c:        Clear screen
 * If q or ESC: Exit program
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void KeyPress::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected)
{
   // close program if "ESC" or "q" pressed
   if (key == 17 || key == 113)
      glutLeaveMainLoop();
   // clear shapes if "c" pressed
   else if (key == 'c')
   {
      events.clear();
      shapes.clear();
      glClear(GL_COLOR_BUFFER_BIT);
      mainPalleteDraw(menuItems);
      glFlush();
      return;
   }
   // delete selected shape if "d" pressed
   else if (key == 'd')
   {
      if(shapes.size() != 0)
      {
         shapes.pop_back();
         glClear(GL_COLOR_BUFFER_BIT);
         mainPalleteDraw(menuItems);
         for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
            shapes[i]->draw();
         glFlush();
      }
   }
   // if any other key pressed, refresh
   else
   {
      glClear(GL_COLOR_BUFFER_BIT);
      mainPalleteDraw(menuItems);
      for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
         shapes[i]->draw();
      glFlush();
   }

}

/** **************************************************************************
 * @brief Constructor for the mouse click action
 *
 * @param[in] but - mouse button that was clicked
 * @param[in] stat - the state of the button i.e. down, up, etc.
 * @param[in] x - x location where the button was pressed
 * @param[in] y - y location where the button was pressed
 ******************************************************************************/
MouseClick::MouseClick(int but, int stat, int x, int y) : 
button(but), state(stat), xLoc(x), yLoc(y) {}
/** **************************************************************************
 * @brief The mouse click action
 *
 * This event happens after a mouse click and will determine what to do.
 * 
 * Left clicking on toolbox selects fill color and/or tool
 * Left clicking in paint area draws the selected shape with selected colors
 * Right clicking in toolbox selects border color
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void MouseClick::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected)
{
   int startX = selected.getStartX();        // set starting x loc
   int startY = selected.getStartY();        // set starting y loc
   int xSize = selected.getEndX() - startX;  // set end location to the end x minus the start x
   int ySize = selected.getEndY() - startY;  // set end location to the end Y minus the start Y

   /************************************************************************
    *                         MOUSE CLICK DOWN
    ************************************************************************/
   if (state == GLUT_DOWN)
   {
      // ************LEFT CLICK******************
      // Left Click to Slect tool and border/fill color
      if (button == GLUT_LEFT_BUTTON)
      {
         selected.setLeftCLickStatus(true);

         for (int i = 0; i < int(menuItems.size()); i++)
         {
            if(menuItems[i]->contains(xLoc,yLoc) && menuItems[i]->getType() == "color")  // If color was selected, set border
               selected.setBorderColor(menuItems[i]->getColor());

            if(menuItems[i]->contains(xLoc,yLoc) && menuItems[i]->getType() != "color")  // If tool was selected, set tool
            {
               selected.setTool(menuItems[i]->getType()); // set selected tool type
            }

            if(xLoc > 100)
            {
               selected.setStartX(xLoc); selected.setStartY(yLoc);
            }
               
         }
      }
      // ************RIGHT CLICK******************
      else if (button == GLUT_RIGHT_BUTTON)
      {
         // Right Click to save Fill Color if on toolbox
         if(xLoc < 100)
         {
            for (int i = 0; i < int(menuItems.size()); i++)
            {
               if(menuItems[i]->contains(xLoc,yLoc) && menuItems[i]->getType() == "color")
               {
                  selected.setFillColor(menuItems[i]->getColor());
               }    
            }
         }
         else           // if outside toolbox, bring shape to front if clicked
         {
            // if no shapes, return to prevent segfault
            if(shapes.size() == 0)
               return;
            selected.bringToFront(shapes, xLoc, yLoc);
            selected.setStartX(xLoc - selected.getSelectedShape()->getXLoc());
            selected.setStartY(yLoc - selected.getSelectedShape()->getYLoc());
         }
      }
    
   }

   /************************************************************************
    *                         MOUSE CLICK RELEASE
    ************************************************************************/
   if (state == GLUT_UP)
   {
      if(button == GLUT_LEFT_BUTTON)
      {
         if(startX != selected.getEndX() && startY != selected.getEndY() && selected.getDragStatus() == true)
         {

            if(selected.getTool() == "line")
            {
               // xSize = selected.getEndX();
               // ySize = selected.getEndY();
               Line line(startX, startY, ySize, xSize, selected.getBorderColor());
               shapes.push_back(new Line(startX, startY, ySize, xSize, selected.getBorderColor()));
               line.draw();
            }

            if(selected.getTool() == "unfilledSquare")
            {
               Rectangle box(startX, startY, ySize, xSize, selected.getBorderColor());
               shapes.push_back(new Rectangle(startX, startY, ySize, xSize, selected.getBorderColor()));
               box.draw();
            }
            if(selected.getTool() == "filledSquare")
            {
               FilledRectangle box(startX, startY, ySize, xSize, selected.getBorderColor(), selected.getFillColor());
               shapes.push_back(new FilledRectangle(startX, startY, ySize, xSize, selected.getBorderColor(), selected.getFillColor()));
               box.draw();
            }

            if(selected.getTool() == "unfilledCircle")
            {
               Circle circle(startX, startY, sqrt((pow(startX - xLoc,2) + pow(startY - yLoc,2))) ,selected.getBorderColor());
               shapes.push_back(new Circle(startX, startY, sqrt((pow(startX - xLoc,2) + pow(startY - yLoc,2))) ,selected.getBorderColor()));
               circle.draw();
            }
            if(selected.getTool() == "filledCircle")
            {
               FilledCircle filledCircle(startX, startY, sqrt((pow(startX - xLoc,2) + pow(startY - yLoc,2))),selected.getBorderColor(), selected.getFillColor());
               shapes.push_back(new FilledCircle(startX, startY, sqrt((pow(startX - xLoc,2) + pow(startY - yLoc,2))),selected.getBorderColor(), selected.getFillColor()));
               filledCircle.draw();
            }

            if(selected.getTool() == "unfilledEllipse")
            {
               Ellipse ellipse(selected.getEndX(), selected.getEndY(), xSize, ySize, selected.getBorderColor());
               shapes.push_back(new Ellipse(selected.getEndX(), selected.getEndY(), xSize, ySize, selected.getBorderColor()));
               ellipse.draw();
            }
            if(selected.getTool() == "filledEllipse")
            {
               FilledEllipse filledEllipse(selected.getEndX(), selected.getEndY(), xSize, ySize, selected.getBorderColor(), selected.getFillColor());
               shapes.push_back(new FilledEllipse(selected.getEndX(), selected.getEndY(), xSize, ySize, selected.getBorderColor(), selected.getFillColor()));
               filledEllipse.draw();
            }


            selected.setDragStatus(false);
            if(shapes.size() != 0)
               selected.setSelectedShape(shapes.back());

         }
         selected.setLeftCLickStatus(false);
      }
      else if(button == GLUT_RIGHT_BUTTON)
      {
         selected.setDragStatus(false);
      }
   }
   mainPalleteDraw(menuItems);
   glFlush();

}

/** **************************************************************************
 * @brief Constructor for the mouse drag action
 *
 * @param[in] x - x location where the mouse was dragged to
 * @param[in] y - y location where the mouse was dragged to
 ******************************************************************************/
MouseDrag::MouseDrag(int x, int y) : xLoc(x), yLoc(y) {}
/** **************************************************************************
 * @brief The mouse drag action
 *
 * This event will occur when the mouse is clicked and dragged across the screen
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void MouseDrag::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected) 
{
   int startX = selected.getStartX();        // set starting x location
   int startY = selected.getStartY();        // set starting y location
   int xSize = selected.getEndX() - startX;  // set dragged x location
   int ySize = selected.getEndY() - startY;  // set dragged y location

   /************************************************************************
    *                         LEFT CLICK DRAG
    ************************************************************************/
   if(xLoc > 100 && selected.getLeftClickStatus() == true)   // If pallette not clicked, then draw a shape on screen if 
      {
         selected.setDragStatus(true);

         selected.setEndX(xLoc); selected.setEndY(yLoc);
         
         // If tool is line, prevent distance subtraction to draw
         if(selected.getTool() == "line")
         {
            // xSize = selected.getEndX();
            // ySize = selected.getEndY();
            Line line(startX, startY, ySize, xSize, selected.getBorderColor());

            glClear(GL_COLOR_BUFFER_BIT);

            for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
                  shapes[i]->draw();

            line.draw();
            mainPalleteDraw(menuItems);
            glFlush();   
         }

         // UNFILLED RECTANGLE
         if(selected.getTool() == "unfilledSquare")
         {
            Rectangle box(startX, startY, ySize, xSize, selected.getBorderColor());

            glClear(GL_COLOR_BUFFER_BIT);

            for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
                  shapes[i]->draw();

            box.draw();
            mainPalleteDraw(menuItems);
            glFlush();   
         }
         // FILLED RECTANGLE
         else if(selected.getTool() == "filledSquare")
         {
            FilledRectangle box(startX, startY, ySize, xSize, selected.getBorderColor(), selected.getFillColor());

            glClear(GL_COLOR_BUFFER_BIT);
            
            for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
                  shapes[i]->draw();

            box.draw();
            mainPalleteDraw(menuItems);
            glFlush();   
         }
         // UNFILLED CIRCLE
         else if(selected.getTool() == "unfilledCircle")
         {
            Circle circle(startX, startY, sqrt((pow(startX - xLoc,2) + pow(startY - yLoc,2))) ,selected.getBorderColor());

            glClear(GL_COLOR_BUFFER_BIT);
            
            for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
                  shapes[i]->draw();

            circle.draw();
            mainPalleteDraw(menuItems);
            glFlush();   
         }
         // FILLED CIRCLE
         else if(selected.getTool() == "filledCircle")
         {
            FilledCircle filledCircle(startX, startY, sqrt((pow(startX - xLoc,2) + pow(startY - yLoc,2))),selected.getBorderColor(), selected.getFillColor());

            glClear(GL_COLOR_BUFFER_BIT);
            
            for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
                  shapes[i]->draw();

            filledCircle.draw();
            mainPalleteDraw(menuItems);
            glFlush();   
         }
         // UNFILLED ELLIPSE
         else if(selected.getTool() == "unfilledEllipse")
         {
            Ellipse ellipse(xLoc, yLoc, xSize, ySize, selected.getBorderColor());

            glClear(GL_COLOR_BUFFER_BIT);

            for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
                  shapes[i]->draw();

            ellipse.draw();
            mainPalleteDraw(menuItems);

            glFlush();   
         }
         // FILLED ELLIPSE
         else if(selected.getTool() == "filledEllipse")
         {
            FilledEllipse filledEllipse(xLoc, yLoc, xSize, ySize, selected.getBorderColor(), selected.getFillColor());

            glClear(GL_COLOR_BUFFER_BIT);
            
            for(int i = 0; i < int(shapes.size()); i++)  // redraw all the shapes
                  shapes[i]->draw();

            filledEllipse.draw();
            mainPalleteDraw(menuItems);


            glFlush();   
         }
         // *** If no tools were selected, just return ***
         else
         {
            return;
         }
         
         

      }



   /************************************************************************
   *                         RIGHT CLICK DRAG
   ************************************************************************/
      else if(xLoc > 100 && selected.getLeftClickStatus() == false && shapes.size() != 0)
      {         
         if(shapes.size() != 0)  // if no shapes, just return
         {
            if(selected.getDragStatus() == false)  // if first drag call, bring dragged shape to front
            {
               selected.bringToFront(shapes, xLoc, yLoc);
               selected.setStartX(xLoc - selected.getSelectedShape()->getXLoc());
               selected.setStartY(yLoc - selected.getSelectedShape()->getYLoc());
               if(selected.getSelectedShape()->contains(xLoc, yLoc))
               {
                  selected.setDragStatus(true);
               }
            }
         }
         // move the shape and redraw
         if(selected.getLeftClickStatus() == false)
         {
            selected.moveShape(shapes, xLoc, yLoc);
            glClear(GL_COLOR_BUFFER_BIT);

            // redraw all the shapes
            for(int i = 0; i < int(shapes.size()); i++)  
               shapes[i]->draw();
            
            shapes.back()->draw();
            mainPalleteDraw(menuItems);
            glFlush();
         }
                  
      }


}

/** **************************************************************************
 * @brief Constructor for the passive mouse move action
 *
 * @param[in] x - x location where the mouse is located
 * @param[in] y - y location where the mouse is located
 ******************************************************************************/
MouseMove::MouseMove(int x, int y) : xLoc(x), yLoc(y) {}
/** **************************************************************************
 * @brief The mouse move action
 *
 * This event keeps track of the location of the mouse when passive
 * It displays the location of the mouse (Either toolbox or paint area) in the top of window
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void MouseMove::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected)
{
   // if located on toolbox set area to tool box, otherwise, set area to paint area
   stringstream ss;
   if(xLoc < 100)
      ss << "SDSM&T Paint: Toolbox";
   else
      ss << "SDSM&T Paint: Paint Area";

   glutSetWindowTitle(ss.str().c_str());
}

/** **************************************************************************
 * @brief Constructor for the program close event action
 ******************************************************************************/
CloseEvent::CloseEvent() {}
/** **************************************************************************
 * @brief The program close action
 *
 * This event occurs at the closing of the paint program, it does nothing
 *
 * @param[in,out] events - A vector storing various program events to be saved and called
 * @param[in,out] menuItems - A vector storing all menuitems (colors and tools) for selection
 * @param[in,out] selected - A class which holds all selected values for persistence (color fills/tool type)
 * @param[in,out] shapes - A vector of storing shapes and their properties in the paint area
 ******************************************************************************/
void CloseEvent::action(vector<Event *> &events, vector<MenuItem *> &menuItems, vector<Shape *> &shapes, Selections &selected)
{
}
