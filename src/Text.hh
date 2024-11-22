/*
* @author Kaleb Gebrehiwot
* @date 11,01,2024
*/
#ifndef TEXT_HH__
#define TEXT_HH__

#include <FL/Fl.H>
#include "Window.hh"
#include "Shapes.hh"
#include <iostream>
#include <string>
namespace KG{
    class TextStyle{
      public: 
      enum TextStyle_t {
        HELVETICA=FL_HELVETICA,
        HELVETICA_BOLD=FL_HELVETICA_BOLD,
        HELVETICA_ITALIC=FL_HELVETICA_ITALIC,
        HELVETICA_BOLD_ITALIC=FL_HELVETICA_BOLD_ITALIC,
        COURIER=FL_COURIER,
        COURIER_BOLD=FL_COURIER_BOLD,
        COURIER_ITALIC=FL_COURIER_ITALIC,
        COURIER_BOLD_ITALIC=FL_COURIER_BOLD_ITALIC,
        TIMES=FL_TIMES,
        TIMES_BOLD=FL_TIMES_BOLD,
        TIMES_ITALIC=FL_TIMES_ITALIC,
        TIMES_BOLD_ITALIC=FL_TIMES_BOLD_ITALIC,
      };
      //getters and setters
      int getTextStyle() const { return textStyle; }
      int getTextSize() const {return textSize;}
      int getTextColor() const {return textColor;}
      void setTextStyle(TextStyle_t style) { textStyle = static_cast<int>(style); }
      void setTextSize(int size) { textSize = static_cast<int>(size); }
      void setTextColor(AUGL::Color color) { textColor = static_cast<int>(color); }

      private:
      // Text attributes
      int textStyle=HELVETICA; 
      int textSize=12; 
      int textColor; 
  };
  class Text : public TextStyle, public AUGL::Shape{
      public:
      Text(const AUGL::Point& p,const std::string& t) : position(p), text(t) {
        resize(p.x,p.y,getTextSize(),getTextSize());
      }

      void drawObject() { // Override for drawObject()
          fl_font(getTextStyle(), getTextSize()); 
          fl_color(getTextColor());
          fl_draw(text.c_str(), position.x, position.y); 
      }

      private:
      AUGL::Point position;
      std::string text;
  };
  class TextTestWindow : public AUGL::Window{
    public:
      TextTestWindow(AUGL::Point p, int w, int h, const std::string& title)
      : Window(p,w,h,title),
      t1({50,50}, "Hello World!"),
      t2({50,150}, "Hello World!"),
      t3({50,300}, "Hello World!"){
        //Format the text objects
        t1.setTextColor(AUGL::Color::CYAN);
        t1.setTextStyle(TextStyle::HELVETICA);
        t1.setTextSize(24);
        
        t2.setTextColor(AUGL::Color::MAGENTA);
        t2.setTextStyle(TextStyle::COURIER_BOLD);
        t2.setTextSize(32);
        
        t3.setTextColor(AUGL::Color::BLACK);
        t3.setTextStyle(TextStyle::TIMES_BOLD_ITALIC);
        t3.setTextSize(40);
      }
    private:
    Text t1,t2,t3;

  };
}

#endif
