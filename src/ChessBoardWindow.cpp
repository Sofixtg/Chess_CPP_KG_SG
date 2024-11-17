#include "Window.hh"
#include "GUI.hh"
#include <iostream>
/**
 * @author Kaleb Gebrehiwot and Sofonias Gebre
 * @brief This class inherits from the AUGL::Window class and represents the chess board.
 * @date 11/14/2024
 */
class ChessBoardWindow : AUGL::Window{
    public:
        ChessBoardWindow(AUGL::Point& p, int w, int h,const std::string& title):
        Window(p,w,h,title){
            for(int i = 0; i < 8; i ++){
                for(int j = 0; j < 8; j++){
                    //positions[i][j] = new AUGL::Button()
                    // ** initialize Buttons to represent positions.
                }
            }
        }
    private:
        AUGL::Button positions[8][8];
        

};
/**
 * @brief Class to represent a chess board position.
 */
class Position{

};