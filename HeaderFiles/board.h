#ifndef BOARD_H
#define BOARD_H

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
        std::vector<sf::RectangleShape> board; // TODO tämän koko tiedetään alusta alkaen, voidaan laittaa maksimikokoon 
        sf::Vector2i mousePos;

    // Private functions
        void initWindow();
        void initVariables();
        sf::RectangleShape initPiece(); // TODO MOVE TO OWN CLASS
        std::vector<sf::RectangleShape> initBoard();

    // Game objects
    sf::RectangleShape square;
    sf::RectangleShape piece;
    

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
    void drawSquares();
    void drawPiece(); // TODO NOT A PART OF BOARD
    sf::Vector2i getMousePosition();

};

#endif
