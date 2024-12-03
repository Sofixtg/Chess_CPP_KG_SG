#ifndef GAMEOVERWINDOW_HH__
#define GAMEOVERWINDOW_HH__

#include "Window.hh"
#include "GUI.hh"
#include "Shapes.hh"
#include <string>

/**
 * @brief This class inherits from the AUGL::Window class and displays the result of the chess game when it's over.
 * @author Kaleb Gebrehiwot and Sofonias Gebre
 * @date 11/14/2024
 */
class GameOverWindow : public AUGL::Window {
public:
    /**
     * @brief Constructs the GameOverWindow.
     * @param p The position of the window on the screen.
     * @param result The result of the game (win/lose/draw).
     */
    GameOverWindow(AUGL::Point p, const std::string& result)
        : Window(p, 400, 200, "Game Over") {
        // Create and style the result text
        resultText = new AUGL::Text({100, 80}, result);
        resultText->setFontSize(24);
        resultText->setFontColor(AUGL::Color::BLACK);
        attach(*resultText);
        
        // Button for closing the window
        closeButton = new AUGL::Button({150, 130}, 100, 40, "Close");
        closeButton->setCallback([]() { exit(0); });
        attach(*closeButton);
    }

    /**
     * @brief Handles events for the window.
     * @param event The event type (e.g., button press).
     * @return An integer indicating the result of the event handling.
     */
    int handle(int event) override {
        if (event == FL_PUSH) {
            int clickX = Fl::event_x();
            int clickY = Fl::event_y();
            if (closeButton->inside(clickX, clickY)) {
                exit(0); // Close the application
            }
        }
        return Window::handle(event);
    }

private:
    AUGL::Text* resultText;   ///< The text that displays the result (e.g., "Checkmate! White wins")
    AUGL::Button* closeButton;///< Button to close the window

};

#endif // GAMEOVERWINDOW_HH__
