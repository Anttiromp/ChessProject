#ifndef RENDERGRAPHICS_H
#define RENDERGRAPHICS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>


/*
    TODO
*/

class renderBoard {

    private:
    // Variables
        sf::RenderWindow* window;
        // TODO videoMode variable
        std::optional<sf::Event> event;


    // Private functions
        void initWindow();
        void initVariables();



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