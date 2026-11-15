#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>


/*
    TODO
*/

class renderGraphics {

    private:
    // Variables
        sf::RenderWindow* window;
        // TODO videoMode variable
        std::optional<sf::Event> event;
        std::vector<sf::RectangleShape> board; // TODO tämän koko tiedetään alusta alkaen, voidaan laittaa maksimikokoon 


    // Private functions
        void initWindow();
        void initVariables();
        std::vector<sf::RectangleShape> initBoard();

    // Game objects
    sf::RectangleShape square;


    // Constructor & destructor
    public:
        renderGraphics();
        virtual ~renderGraphics();

    // Accessors
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();
    void renderBoard();

};

#endif