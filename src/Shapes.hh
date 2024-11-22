#ifndef SHAPES_H__
#define SHAPES_H__

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include "Attributes.hh"
#include "Point.hh"
#include "GUI.hh"
#include <iostream>

namespace AUGL {

  class Window;

  /**
   * @class Shape
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A generic geometrical shape that interfaces to 
   * the FLTK widget object
   */
  class Shape : public Widget, public LineStyle {
  public:
    /**
     * @brief Override the Widget::draw() method
     * 
     * Draws the shape with the current attributes. 
     * The FLTK color state is not permanently changed. 
     * There is no good way to restore the line style. 
     * So it is changed to 1 pt solid.
     */
    void draw() {
      //first call the base class draw()
      Widget::draw();

      //ensure proper clearing of the box widget
      m_widget->draw();

      //grab the current color
      //because we are going to restore it
      //after we (potentially) change the color
      //to draw the line
      Fl_Color currentColor = fl_color();

      //now work the magic for the specific shape
      drawObject();

      //change back to the old color
      fl_color(currentColor);
      //return to default style
      fl_line_style(FL_SOLID,1);
    }

    /**
     * @brief attach this widget to the window
     */
    void attach(Window* window){
      m_owner = window;
      m_widget->resize(x(),y(),w(),h());
    }

    /**
     * @brief Move the object by dX horizontally and dY vertically
     */
    virtual void move(int dX, int dY) {
      m_point.x += dX;
      m_point.y += dY;
    }

  protected:
    /**
     * @brief Default constructor
     */
    Shape() : Widget({0,0},0,0,{""},nullptr), LineStyle() {
      //everyone gets a box widget
      m_widget = new Fl_Box(0,0,0,0,"");
      m_widget->box(FL_NO_BOX);
    }

    /**
     * @brief specific function to be overriden by
     * child class to draw
     */
    virtual void drawObject() = 0;
  };

  /**
   * @class Line
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A line segment that can be drawn
   */
  class Line : public Shape {
  public:

    /**
     * @brief Useful constructor from two Points
     */
    Line (const Point& p1, const Point& p2) : Shape(), m_point1(p1), m_point2(p2) {
      if(m_point1.x < m_point2.x){
	m_point = m_point1;
	m_width = m_point2.x - m_point1.x;
      } else {
	m_point = m_point2;
	m_width = m_point2.x - m_point1.x;
      }
      m_height = std::abs(m_point2.y-m_point1.y);
    }

    /**
     * @brief Override the Shape::drawObject() method
     * 
     * Draws the line with the current attributes. 
     */
    void drawObject(){
      //change the line style
      fl_line_style(lineStyle(),lineWidth());
      //change the color
      fl_color(lineColor());
      //draw the line
      fl_line(m_point1.x,m_point1.y,m_point2.x,m_point2.y);
    }

  private:
    Point m_point1;
    Point m_point2;
  };

  /**
   * @class Rectangle
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A rectangle that can be drawn and filled
   */
  class Rectangle : public Shape {
  public:
    /**
     * @brief Construct a rectangle from two points
     *
     * The first point is (xmin,ymin) point and the
     * second is the (xmax,xmin)
     */
    Rectangle(const Point& upperLeft, const Point& lowerRight) : Shape() {
      m_point = upperLeft;
      m_width = lowerRight.x - upperLeft.x;
      m_height = lowerRight.y - upperLeft.y;
    }

    /**
     * @brief Override the Shape::drawObject() method
     * 
     * Draws the rectangle with the current attributes. 
     */
    void drawObject(){
      //draw a filled rectangle if requested
      if(isFilled()){
	fl_color(fillColor());
	fl_rectf(x(),y(),w(),h());
      }
      //draw the line (which will be over the filled area
      fl_line_style(lineStyle(),lineWidth());
      fl_color(lineColor());
      fl_rect(x(),y(),w(),h());
    }

  };

  /**
   * @class Square
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A square that can be drawn and filled
   */
  class Square : public Rectangle {
  public:
    Square(const Point& p, int sideLength) : Rectangle(p,{p.x+sideLength,p.y+sideLength}) {}
  };

  /**
   * @class Circle
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A circle that can be drawn and filled
   */
  class Circle : public Shape {
  public:
    /**
     * @brief Construct a circle from a center point and a radius
     */
    Circle(const Point& p, int r) : Shape() {
      //get the coordinates of the bounding box
      int x = p.x - r;
      int y = p.y - r;
      m_point = {x,y};
      m_width = 2*r;
      m_height = 2*r;
    }

    /**
     * @brief Override the Shape::drawObject() method
     * 
     * Draws the circle with the current attributes. 
     */
    void drawObject(){
      //draw a filled circle if requested
      if(isFilled()){
	fl_color(fillColor());
	fl_pie(x(),y(),w(),h(),0,360);
      }
      //draw the line (which will be over the filled area)
      fl_line_style(lineStyle(),lineWidth());
      fl_color(lineColor());
      fl_arc(x(),y(),w(),h(),0,360);
    }

  private:
    Point m_center;
    int m_radius;

  };
}

#endif /*  SHAPES_H__ */
