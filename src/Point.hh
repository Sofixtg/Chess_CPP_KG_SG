#ifndef POINT_HH__
#define POINT_HH__

#include <iostream>

namespace AUGL {

  /**
   * @class Point
   * @author ngrau@augie.edu
   * @date Fall 2024
   * @brief A simple integer (x,y) coordinate
   */
  struct Point {
    int x; //!the x coordinate
    int y; //!the y coordinate
  };

  /**
   * @brief outputing a Point class
   */
  std::ostream& operator<<(std::ostream& os, const Point& p){
    return os<<"("<<p.x<<","<<p.y<<")";
  }

}

#endif /* POINT_HH__ */
