#ifndef ATTRIBUTES_HH__
#define ATTRIBUTES_HH__

#include <FL/Fl.H>
#include <FL/Enumerations.H>
#include <FL/fl_draw.H>
#include <string>

namespace AUGL {

  /**
   * @class Color
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @ brief Wrapper class for enumerated FLTK color types
   */
  class Color {
  public:

    /**
     * @enum Color_t
     * @brief Enumeration instead of pure FLTK (integer) 
     * representation of a color
     */
    enum Color_t {
      BLACK = FL_BLACK,
      BLUE = FL_BLUE,
      CYAN = FL_CYAN,
      DARK_BLUE = FL_DARK_BLUE,
      DARK_CYAN = FL_DARK_CYAN,
      DARK_GREEN = FL_DARK_GREEN,
      DARK_MAGENTA = FL_DARK_MAGENTA,
      DARK_RED = FL_DARK_RED,
      DARK_YELLOW = FL_DARK_YELLOW,
      GREEN = FL_GREEN,
      MAGENTA = FL_MAGENTA,
      RED = FL_RED,
      WHITE = FL_WHITE,
      YELLOW = FL_YELLOW,
      GRAY0 = FL_GRAY0,
      DARK3 = FL_DARK3,
      DARK2 = FL_DARK2,
      DARK1 = FL_DARK1,
      LIGHT1 = FL_LIGHT1,
      LIGHT2 = FL_LIGHT2,
      LIGHT3 = FL_LIGHT3,
      BACKGROUND_COLOR = FL_BACKGROUND_COLOR
    };

    /**
     * @brief Constructor with a enumerated color
     */
    Color(Color_t color) : m_color(Fl_Color(color)) {}

    /**
     * @brief overload casting operator to turn our color
     * into FLTK's integer values
     */
    operator int() const {
      return m_color;
    }

    /**
     * @brief Returns true if a color is the background color
     */
    bool isBackgroundColor() const {
      return m_color == FL_BACKGROUND_COLOR;
    }

  private:
    Fl_Color m_color; //!the integer FLTK color value
  };

  /**
   * @class LineStyle
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief Wrapper class for the styling of lines in FLTK
   */
  class LineStyle {
  public:

    /**
     * @enum LineStyle_t
     * @brief Wrapper enum to give named constants to FLTKs bit sets
     */
    enum LineStyle_t {
      SOLID = FL_SOLID,
      DASH = FL_DASH,
      DOT = FL_DOT,
      DASHDOT = FL_DASHDOT,
      DASHDOTDOT = FL_DASHDOTDOT
    };

    /** Get the integerized line style */
    int lineStyle() const { return m_linestyle; }

    /** Get the line width */
    int lineWidth() const { return m_linewidth; }

    /** Get the line color as a Color type */
    Color lineColor() const { return m_linecolor; }

    /** Set the line style with a given LineStyle_t enum */
    void setLineStyle(LineStyle_t style) { m_linestyle = static_cast<int>(style); }

    /** Set the line width */
    void setLineWidth(int width) { m_linewidth = width; }

    /** Set the line color with the Color type */
    void setLineColor(Color c) { m_linecolor = c; }

  private:
    int m_linestyle = FL_SOLID; //!the value of the FLTK enum
    int m_linewidth = 1; //!the width of the line in pixels
    Color m_linecolor = Color::BLACK; //!the line color 
  };

  /**
   * @class FillStyle
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief Small wrapper class for filling
   */
  class FillStyle {
  public:
    /** Check if a object should be filled */
    bool isFilled() const { return !m_fillcolor.isBackgroundColor(); }

    /** Get the fill color by the Color object */
    Color fillColor() const { return m_fillcolor; }

    /** Set the fill color by the Color object */
    void setFillColor(Color c) { m_fillcolor = c; }

  private:
    Color m_fillcolor = Color::BACKGROUND_COLOR; //!the fill color 
  };

  /**
   * @class Text
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A general text class
   */
  class Text {
  public:

    /**
     * @enum TextStyle_t
     * @brief Wrapper enum to give named constants to FLTKs font bit sets
     */
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

    /**
     * @brief construct text simply with the string of text and default style
     */
    Text(const std::string& text) : m_text(text) {}

    /**
     * @brief Set the text style for the text
     */
    void setTextStyle(TextStyle_t style) { m_font = static_cast<int>(style); }

    /**
     * @brief Set the point size for the text
     */
    void setTextSize(int size) { m_fontsize = size; }

    /**
     * @brief Set the text color
     */
    void setTextColor(Color color) { m_fontcolor = static_cast<int>(color); }

    /**
     * @brief Return the integer number for the text style
     */
    int textstyle() const { return m_font; }

    /**
     * @brief Return the integer point size for the text
     */
    int textsize() const { return m_fontsize; }

    /**
     * @brief Return the integer font color
     */
    int textcolor() const { return m_fontcolor; }

    /**
     * @brief Return the text as a char*
     */
    const char* c_str() const { return m_text.c_str(); }

  private:
    Fl_Font m_font = FL_TIMES; //!the FLTK integer constant representing the font style
    int m_fontsize = 12; //!the size of the font int points
    Fl_Color m_fontcolor = FL_BLACK; //!the FLTK integer constant representing the color
    std::string m_text;
  };

}

#endif
