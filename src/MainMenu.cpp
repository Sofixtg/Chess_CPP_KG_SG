#include "Text.hh"
#include "Attributes.hh"
#include "GUI.hh"
#include "Window.hh"

#include <iostream>

/**
 * Window class for the Main menu.
 * @author Kaleb Gebrehiwot and Sofonias Gebre
 */
class MainMenu : AUGL::Window{
    public:
        MainMenu(AUGL::Point& p, int w, int h, const std::string& title):
        Window(p,w,h,title),
        header({100,100},"Chess"),
        credit({100, 200}, "by Kaleb Gebrehiwot and Sofonias Gebre"),
        localMultiP({100,300}, 150, 75, AUGL::Text("Local Multiplayer"), [](Address_t, Address_t userData){ static_cast<MainMenu*>(userData)->PlayLocalMultiplayer();}),
        againstComp({300,300}, 150, 75, AUGL::Text("Computer"), [](Address_t, Address_t userData){ static_cast<MainMenu*>(userData)->PlayAgainstComputer();}){
            
            
            header.setTextStyle(KG::Text::TextStyle_t::HELVETICA_BOLD);
            header.setTextSize(42);
            header.setTextColor(AUGL::Color::BLACK);
            attach(header);
            
            credit.setTextStyle(KG::Text::TextStyle_t::HELVETICA_ITALIC);
            credit.setTextSize(24);
            credit.setTextColor(AUGL::Color::BLACK);
            attach(credit);

            attach(localMultiP);
            attach(againstComp);

        }

    private:
        KG::Text header;
        KG::Text credit;
        AUGL::Button localMultiP;
        AUGL::Button againstComp;

        void PlayLocalMultiplayer(){
            // Add funcitionality here
        }
        void PlayAgainstComputer(){
            // Add functionality here
        }
};