#ifndef POINT_HH__
#define POINT_HH__

#include <iostream>

namespace AUGL {

  /**
   * @class Point
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A simple structure representing a 2D point with x and y coordinates.
   *
   * This structure is used to represent points in a 2D coordinate system.
   * It includes basic member variables for storing the x and y coordinates
   * and an overloaded stream insertion operator for easy output.
   */
  struct Point {
    int x; //! The x coordinate
    int y; //! The y coordinate

    /**
     * @brief Default constructor that initializes the point to (0,0).
     */
    Point() : x(0), y(0) {}

    /**
     * @brief Parameterized constructor to initialize the point with given coordinates.
     * @param x_val The x coordinate.
     * @param y_val The y coordinate.
     */
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    /**
     * @brief Translate the point by given delta values.
     * @param dx The change in the x coordinate.
     * @param dy The change in the y coordinate.
     */
    void translate(int dx, int dy) {
      x += dx;
      y += dy;
    }

    /**
     * @brief Calculate the distance from another point.
     * @param other The other point to calculate the distance to.
     * @return The distance between this point and the other point.
     */
    double distanceTo(const Point& other) const {
      int dx = x - other.x;
      int dy = y - other.y;
      return std::sqrt(dx * dx + dy * dy);
    }
  };

  /**
   * @brief Outputting a Point object to an ostream.
   * 
   * Overloads the `<<` operator to output the point in the format (x, y).
   * @param os The output stream to write to.
   * @param p The Point object to output.
   * @return The output stream with the point information.
   */
  std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << "," << p.y << ")";
  }

}

#endif /* POINT_HH__ */
