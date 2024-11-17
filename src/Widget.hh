#ifndef WIDGET_HH__
#define WIDGET_HH__

#include "Attributes.hh"
#include "Point.hh"
#include <FL/Fl_Widget.H>

/** typedef away void pointer */
typedef void* Address_t;

namespace AUGL {

  class Window; //!Forward declaration of the class Window

  /** typedef the function pointer for callback function signatures */
  typedef void (*Callback_t)(Address_t,Address_t);

  /**
   * @class Widget
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A Fl_Widget handle class. It is not a Fl_Widget!
   */
  class Widget : public FillStyle {
  public:
    /**
     * @brief Construct a widget with a point, width, height, label, and callback function
     */
    Widget(const Point& p, int width, int height, const Text& label, Callback_t callback) : m_point(p), m_width(width), m_height(height), m_label(label), m_callback(callback), m_widget(nullptr), m_owner(nullptr) {
    }

    /**
     * @brief Simple destructor
     */
    virtual ~Widget() {
      if(m_widget != nullptr)
	delete m_widget;
      m_widget = nullptr;
    }

    /**
     * @brief Pure virtual method that will attach this widget to a given window
     */
    virtual void attach(Window* w) = 0;

    /**
     * @brief Draw the widget with all of its attributes
     */
    virtual void draw() {
      m_widget->color(fillColor());
      m_widget->draw();
    }

    /**
     * @brief return the x coordinate of the upper left point of the widget
     */
    int x() const { return m_point.x; }

    /**
     * @brief return the y coordinate of the upper left point of the widget
     */
    int y() const { return m_point.y; }

    /**
     * @brief return the width of the widget
     */
    int w() const { return m_width; }

    /**
     * @brief return the height of the widget
     */
    int h() const { return m_height; }

    /**
     * @brief return the label of the widget, 
     *        a reference is returned so that users can update 
     *        the text attributes
     */
    Text& label() { return m_label; }

  protected:
    Point m_point; //!the (x,y) location of the widget
    int m_width; //!the width of the widget
    int m_height; //!the height of the widget
    Text m_label; //!the widget's label
    Callback_t m_callback; //!the widget's callback function
    Fl_Widget *m_widget; //!a pointer to the hidden Fl_Widget
    Window *m_owner; //!the window that owns the widget

  };

}

#endif /* WIDGET_HH__ */
