#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <string>

class GameOverWindow : public Fl_Window {
public:
    GameOverWindow(int w, int h, const char* title)
        : Fl_Window(w, h, title) {

        winner_box = new Fl_Box(100, 50, 300, 50, "Winner: ");
        move_summary_box = new Fl_Box(100, 120, 300, 100, "Move Summary: ");
        replay_button = new Fl_Button(100, 250, 100, 30, "Replay");
        quit_button = new Fl_Button(250, 250, 100, 30, "Quit");

        replay_button->callback([](Fl_Widget*, void* window) {
            // Implement Replay logic here
            static_cast<Fl_Window*>(window)->hide();
        });

        quit_button->callback([](Fl_Widget*, void* window) {
            static_cast<Fl_Window*>(window)->hide();
        });

        end();
    }

    void set_winner(const std::string& winner) {
        // Convert the string to const char* and set it as label
        winner_box->label(("Winner: " + winner).c_str());
        winner_box->redraw();  // Redraw the box to update the text
    }

    void set_move_summary(const std::string& summary) {
        // Convert the string to const char* and set it as label
        move_summary_box->label(("Move Summary: " + summary).c_str());
        move_summary_box->redraw();  // Redraw the box to update the text
    }

private:
    Fl_Box* winner_box;
    Fl_Box* move_summary_box;
    Fl_Button* replay_button;
    Fl_Button* quit_button;
};

int main() {
    GameOverWindow window(500, 350, "Game Over");
    window.set_winner("");
    window.set_move_summary("");
    window.show();
    return Fl::run();
}
