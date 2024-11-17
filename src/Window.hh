#ifndef WINDOW_HH__
#define WINDOW_HH__

#include "Point.hh"
#include "Widget.hh"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <string>
#include <vector>

namespace AUGL {

  /**
   * @class Window
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A basic window object that can have widgets and draw them
   */
  class Window : public Fl_Window {
  public:
    /**
     * @brief construct a window with the upper left point, the width, the height, and a title
     */
    Window(const Point& p, int width, int height, const std::string& title) : Fl_Window(p.x,p.y,width,height,title.c_str()) {}

    virtual ~Window(){}

    /**
     * @brief attach the Widget to this window
     */
    void attach(Widget& w){
      w.attach(this);
      m_widgets.push_back(&w);
    }

  protected:

    /**
     * @brief Draw all the widgets attached to this window
     */
    void draw() {
      for(auto &w : m_widgets) {
	w->draw();
      }
    }

  private:
    std::vector<Widget*> m_widgets; //! the list of widgets attached to this window
  };

  /**
   * @brief run the event loop
   */
  inline int run() { return Fl::run(); }
}

#endif /*  WINDOW_HH__ */
