#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>


/*
    TODO
*/

class renderGraphics{

    private:
    // Variables
    std::vector<sf::RectangleShape> board; // TODO tämän koko tiedetään alusta alkaen, voidaan laittaa maksimikokoon 
        
    

    // Private functions
        
        void initVariables();
        sf::RectangleShape initPiece(); // TODO MOVE TO OWN CLASS
        std::vector<sf::RectangleShape> initBoard();

    // Game objects
    sf::RectangleShape square;
    sf::RectangleShape piece;
    

    // Constructor & destructor
    public:
        renderGraphics();
        virtual ~renderGraphics();

    // Accessors
    
    // Functions
    
 //   void update();
    void render();
    void drawSquares();
    // TODO Might need to be on their on class?
    sf::RectangleShape getPiece();

};

#endif
