#ifndef RENDERGRAPHICS_H
#define RENDERGRAPHICS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <vector>


/*
    TODO
*/

class renderBoard {

    private:
    // Variables
        sf::RenderWindow* window;
        // TODO videoMode variable
        std::optional<sf::Event> event;
        std::vector<sf::RectangleShape> board;


    // Private functions
        void initWindow();
        void initVariables();
        std::vector<sf::RectangleShape> initBoard();

    // Game objects
    sf::RectangleShape square;


    // Constructor & destructor
    public:
        renderBoard();
        virtual ~renderBoard();

    // Accessors
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();

};

#endif