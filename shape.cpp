/** ***************************************************************************
* @file
* @brief Cpp file including functions for the shape.h, holds all the functions which access
* and alter the shapes classes' information
******************************************************************************/

#include "shape.h"

/** **************************************************************************
 * @brief Default constructor for the abstract shape class
 ******************************************************************************/
Shape::Shape() {}

/** **************************************************************************
 * @brief Default destructor for the absstract shape class
 ******************************************************************************/
Shape::~Shape() {}

/** **************************************************************************
 * @brief Sets the x location of the shape
 * @param[in] x - the x location of the shape
 ******************************************************************************/
void Shape::setXLoc(int x)
{
   xLoc = x;
}

/** **************************************************************************
 * @brief Sets the y location of the shape
 * @param[in] y - the y location of the shape
 ******************************************************************************/
void Shape::setYLoc(int y)
{
   yLoc = y;
}

/** **************************************************************************
 * @brief Returns the y location of the shape
 ******************************************************************************/
int Shape::getYLoc()
{
   return yLoc;
}

/** **************************************************************************
 * @brief Returns the x location of the shape
 ******************************************************************************/
int Shape::getXLoc()
{
   return xLoc;
}

/** **************************************************************************
 * @brief Returns the name of the shape
 ******************************************************************************/
std::string Shape::getName()
{
   return name;
}

/** **************************************************************************
 * @brief Sets the border color of the shape
 * @param[in] col - the color to be used to set the border color of the shape
 ******************************************************************************/
void Shape::setBorderColor(const float col[])
{
   for(int i = 0; i < 3; i++)
      borderColor[i] = col[i];
}

/** **************************************************************************
 * @brief Sets the fill color of the shape
 * @param[in] col - the color to be used to set the fill color of the shape
 ******************************************************************************/
void Shape::setFillColor(const float col[])
{
   for(int i = 0; i < 3; i++)
      fillColor[i] = col[i];
}

/** **************************************************************************
 * @brief Constructor for the line subclass
 *
 * Constructs a line given the parameters
 *
 * @param[in] x - the x location of the line
 * @param[in] y - the y location of the line
 * @param[in] h - the height of the line
 * @param[in] w - the width of the line
 * @param[in] bcol - the desired border color of the line
 * @param[in] nm - the name/type of the line
 ******************************************************************************/
Line::Line(int x, int y, int h, int w, const float bcol[], std::string nm)
{
   xLoc = x; yLoc = y; ; height = h; width = w; name = name;
   setBorderColor(bcol);
}

/** **************************************************************************
 * @brief Checks to see if the entered point is contained by the line
 *
 * @param[in] x   - the x-coordinate of the point
 * @param[in] y   - the y-coordinate of the point
 ******************************************************************************/
bool Line::contains(int x, int y)
{
   float slope = float(height) / float(width);
   
   for(int i = 1; i < 8; i++)
   {
      if(y + i == int((slope * (float(x) - float(xLoc))) + float(yLoc)))
         return true;
      if(y - i == int((slope * (float(x) - float(xLoc))) + float(yLoc)))
         return true;
   }

   return false;
}

/** **************************************************************************
 * @brief Draws the line
 ******************************************************************************/
void Line::draw()
{
   glColor3fv( borderColor );   
   glBegin(GL_LINES);
      glVertex2f(xLoc, yLoc);
      glVertex2f(xLoc + width, yLoc + height);          
   glEnd();
}


/** **************************************************************************
 * @brief Constructor for the rectangle subclass
 *
 * Constructs a rectangle given the parameters
 *
 * @param[in] x - the x location of the rectangle
 * @param[in] y - the y location of the rectangle
 * @param[in] h - the height of the rectangle
 * @param[in] w - the width of the rectangle
 * @param[in] bcol - the desired border color of the rectangle
 * @param[in] nm - the name/type of the rectangle
 ******************************************************************************/
Rectangle::Rectangle(int x, int y, int h, 
int w, const float bcol[], std::string nm) : height(h), width(w)
 {
   xLoc = x; yLoc = y; name = nm;
   setBorderColor(bcol);
 }

/** **************************************************************************
 * @brief Default constructor for the rectangle class
 ******************************************************************************/
Rectangle::Rectangle() {}

/** **************************************************************************
 * @brief Checks to see if the entered point is contained by the rectangle
 *
 * @param[in] x   - the x-coordinate of the point
 * @param[in] y   - the y-coordinate of the point
 ******************************************************************************/
bool Rectangle::contains(int x, int y)
{
   if(x > xLoc && x < xLoc + width && y < yLoc && y > yLoc + height) // top left
      return true;

   if(x < xLoc && x > xLoc + width && y > yLoc && y < yLoc + height) // bottom right
      return true;

   if(x > xLoc && x < xLoc + width && y > yLoc && y < yLoc + height) // bottom left
      return true;

   if(x < xLoc && x > xLoc + width && y < yLoc && y > yLoc + height) // top right
      return true;
      
   return false;
}

/** **************************************************************************
 * @brief Draws either a unfilled rectangle
 * 
 * Otherwise, there will be a fill color in the drawn rectangle
 *
 ******************************************************************************/
void Rectangle::draw()
{
   // Border  
   glColor3fv( borderColor );   
   glBegin(GL_LINE_LOOP);
      glVertex2f(xLoc - 1, yLoc);
      glVertex2f(xLoc + width, yLoc);
      glVertex2f(xLoc + width, yLoc + height);
      glVertex2f(xLoc, yLoc + height);
      glVertex2f(xLoc - 1, yLoc);
      glVertex2f(xLoc, yLoc + height);
      glVertex2f(xLoc + width, yLoc + height);
      glVertex2f(xLoc + width, yLoc);           
   glEnd();
}


/** **************************************************************************
 * @brief Constructor for the filledrectangle subclass
 *
 * Constructs a rectangle given the parameters
 *
 * @param[in] x - the x location of the rectangle
 * @param[in] y - the y location of the rectangle
 * @param[in] h - the height of the rectangle
 * @param[in] w - the width of the rectangle
 * @param[in] fcol - the desired fill color of the rectangle
 * @param[in] bcol - the desired border color of the rectangle
 * @param[in] nm - the name/type of the rectangle
 ******************************************************************************/
FilledRectangle::FilledRectangle(int x, int y, int h, 
int w, const float bcol[], const float fcol[], std::string nm)
 {
   xLoc = x; yLoc = y; name = nm; height = h; width = w;
   setFillColor(fcol);
   setBorderColor(bcol);
 }

/** **************************************************************************
 * @brief Draws a filled rectangle
 ******************************************************************************/
 void FilledRectangle::draw()
{
   // Fill Draw
   glColor3fv( fillColor );   
      glBegin(GL_POLYGON);
      glVertex2f(xLoc, yLoc);
      glVertex2f(xLoc + width, yLoc);
      glVertex2f(xLoc + width, yLoc + height);
      glVertex2f(xLoc, yLoc + height);         
   glEnd();
   // Border  
   glColor3fv( borderColor );   
   glBegin(GL_LINE_LOOP);
      glVertex2f(xLoc - 1, yLoc);
      glVertex2f(xLoc + width, yLoc);
      glVertex2f(xLoc + width, yLoc + height);
      glVertex2f(xLoc, yLoc + height);
      glVertex2f(xLoc - 1, yLoc);
      glVertex2f(xLoc, yLoc + height);
      glVertex2f(xLoc + width, yLoc + height);
      glVertex2f(xLoc + width, yLoc);           
   glEnd();
}


// cirlcle

/** **************************************************************************
 * @brief Constructor for the circle subclass
 *
 * Constructs a circle given the parameters
 *
 * @param[in] x - the x location of the circle
 * @param[in] y - the y location of the circle
 * @param[in] r - the radius of the circle
 * @param[in] bcol - the desired border color of the circle
 * @param[in] nm - the name/type of the circle
 ******************************************************************************/
Circle::Circle(int x, int y, int r, const float bcol[], std::string nm)
{
   xLoc = x; yLoc = y; name = nm; radius = r;     // set variables
   setBorderColor(bcol);   // set border color
}

/** **************************************************************************
 * @brief Base constructor for the circle class
 ******************************************************************************/
Circle::Circle() {}

/** **************************************************************************
 * @brief Checks to see if the entered point is contained by the circle
 *
 * @param[in] x   - the x-coordinate of the point
 * @param[in] y   - the y-coordinate of the point
 ******************************************************************************/
bool Circle::contains(int x, int y)
{
   int xDist, yDist, sum;
   // determine the x and y components of a containment function
   xDist = pow(x - xLoc,2);
   yDist = pow(y - yLoc,2);
   // add them
   sum = xDist + yDist;
   // if they add to less than the radius squared, the point is within the circle
   if(sum < pow(radius, 2))
      return true;
   return false;
}

/** **************************************************************************
 * @brief Draws either an unfilled circle given it's dimensions
 ******************************************************************************/
void Circle::draw()
{
   float theta;
   glColor3fv(borderColor);
   glBegin(GL_LINE_LOOP);
      for(int i = 0; i < 360; i++)  // draw around 360 times for the circle
      {
         theta = i * 3.142 / 180;
         glVertex2f(xLoc + radius*cos(theta), yLoc + radius*sin(theta));
      }
   glEnd();
}

/** **************************************************************************
 * @brief Constructor for the Filled Circle subclass
 *
 * Constructs a circle given the parameters
 *
 * @param[in] x - the x location of the circle
 * @param[in] y - the y location of the circle
 * @param[in] r - the radius of the circle
 * @param[in] fcol - the desired fill color of the circle
 * @param[in] bcol - the desired border color of the circle
 * @param[in] nm - the name/type of the circle
 ******************************************************************************/
FilledCircle::FilledCircle(int x, int y, int r, const float bcol[], const float fcol[], std::string nm)
{
   xLoc = x; yLoc = y; name = nm; radius = r;
   setBorderColor(bcol);
   setFillColor(fcol);
}

/** **************************************************************************
 * @brief Draws a filled circle given it's dimensions and colors
 ******************************************************************************/
void FilledCircle::draw()
{
   float theta;
   glColor3fv(fillColor); 
   glBegin(GL_POLYGON);
      for(int i = 0; i < 360; i++)
      {
         theta = i * 3.142 / 180;
         glVertex2f(xLoc + radius*cos(theta), yLoc + radius*sin(theta));
      }
   glEnd();

   glColor3fv(borderColor);
      glBegin(GL_LINE_LOOP);
      for(int i = 0; i < 360; i++)
      {
         theta = i * 3.142 / 180;
         glVertex2f(xLoc + radius*cos(theta), yLoc + radius*sin(theta));
      }
      glEnd();
}


/** **************************************************************************
 * @brief Constructor for the ellipse subclass
 *
 * Constructs a ellipse given the parameters
 *
 * @param[in] x - the x location of the ellipse
 * @param[in] y - the y location of the ellipse
 * @param[in] xrad - the x-axis radius of the ellipse
 * @param[in] yrad - the y-axis radius of the ellipse
 * @param[in] bcol - the desired border color of the ellipse
 * @param[in] nm - the name/type of the ellipse
 ******************************************************************************/
Ellipse::Ellipse(int x, int y, int xrad, int yrad, const float bcol[], std::string nm)
{
   xLoc = x; yLoc = y; radiusX = xrad; radiusY = yrad; name = nm;
   setBorderColor(bcol);
}

/** **************************************************************************
 * @brief Default constructor for the ellipse class
 ******************************************************************************/
Ellipse::Ellipse() {}

/** **************************************************************************
 * @brief Checks to see if the entered point is contained by the ellipse
 *
 * @param[in] x   - the x-coordinate of the point
 * @param[in] y   - the y-coordinate of the point
 ******************************************************************************/
bool Ellipse::contains(int x, int y)
{
   float xDist, yDist, sum;        // initialize variables
   xDist = float((x - xLoc)) / float(radiusX);  // calculate x distance component
   yDist = float((y - yLoc)) / float(radiusY);  // calculate y distance compenent
   xDist = pow(xDist,2);  // square and y components
   yDist = pow(yDist,2);  

   sum = xDist + yDist;   // add the components, if sum less than 1, point is within ellipse

   if(sum <= 1)
      return true;

   return false;
}

/** **************************************************************************
 * @brief Draws either a filled or unfilled ellipse
 * 
 * If fill color contains a -1, there will be no fill
 * Otherwise, there will be a fill color in the drawn ellipse
 *
 ******************************************************************************/
void Ellipse::draw()
{
   float theta;
   glColor3fv(borderColor); // border
   glBegin(GL_LINE_LOOP);
	for(int i=0; i < 360; i++)
	{
		theta = i * 3.142 / 180;
		glVertex2f(xLoc + cos(theta)*radiusX,yLoc + sin(theta)*radiusY);
	} 
	glEnd();
}


/** **************************************************************************
 * @brief Constructor for the filled ellipse subclass
 *
 * Constructs a ellipse given the parameters
 *
 * @param[in] x - the x location of the ellipse
 * @param[in] y - the y location of the ellipse
 * @param[in] xrad - the x-axis radius of the ellipse
 * @param[in] yrad - the y-axis radius of the ellipse
 * @param[in] fcol - the desired fill color of the ellipse
 * @param[in] bcol - the desired border color of the ellipse
 * @param[in] nm - the name/type of the ellipse
 ******************************************************************************/
FilledEllipse::FilledEllipse(int x, int y, int xrad, int yrad, const float bcol[], const float fcol[], std::string nm)
{
   xLoc = x; yLoc = y; radiusX = xrad; radiusY = yrad; name = nm;
   setBorderColor(bcol);
   setFillColor(fcol);
}

/** **************************************************************************
 * @brief Draws a filled ellipse
 ******************************************************************************/
void FilledEllipse::draw()
{
   float theta;
   glColor3fv(fillColor); 
   glBegin(GL_POLYGON);
   for(int i = 0; i < 360; i++)
   {
      theta = i * 3.142 / 180;
      glVertex2f(xLoc + cos(theta)*radiusX,yLoc + sin(theta)*radiusY);
   }
   glEnd();
   glColor3fv(borderColor); // border
   glBegin(GL_LINE_LOOP);
	for(int i=0; i < 360; i++)
	{
		theta = i * 3.142 / 180;
		glVertex2f(xLoc + cos(theta)*radiusX,yLoc + sin(theta)*radiusY);
	} 
	glEnd();
}