#include "renderGraphics.h"
#include "gameController.h"
#include <iostream>

void renderGraphics::initVariables() {
    this -> board = initBoard();
    this -> piece = initPiece();
}


/**
 * @return Vector containing different colored squares 
 * 
 * For each step, the loop assigns either a dark or light color on a square, and pushes it to vector containing 
 * all 64 chess squares. When one rank gets 8 squares assigned, it offsets & swaps the two colors, resulting 
 * in alternating chess board color scheme.
 */

std::vector<sf::RectangleShape> renderGraphics::initBoard() {
    std::vector<sf::RectangleShape> board; // TODO looks funky, compare to initWindow
    float squareOffset {87.5};
    this -> square.setSize(sf::Vector2(87.5f, 87.5f));

    auto darkSquare = sf::Color{181, 136, 99};
    auto lightSquare = sf::Color{240, 217, 181};

    float rank {};
    float file {};

    // Loop through all squares & altering color pattern
    for (int i {1}; i <= 64; i++) {
        this -> square.setPosition(sf::Vector2f(file, rank));
        if (i % 2 == 0) {
            this -> square.setFillColor(darkSquare);
            board.push_back(square);
            file += squareOffset;
        } else {
            this -> square.setFillColor(lightSquare);
            board.push_back(square);
            file += squareOffset;
        }
        
        // Offset rank when file is full & flip color scheme
        if (i % 8 == 0) {
            rank += squareOffset;
            file = 0;
            std::swap(darkSquare, lightSquare);
        }
    }

    return board;
}

// TODO NOT A PART OF THE BOARD
sf::RectangleShape renderGraphics::initPiece() {

    sf::RectangleShape piece;
    piece.setFillColor(sf::Color::Green);
    piece.setSize(sf::Vector2(87.5f, 87.5f));
    
    return piece;
    
}

// Constructors & Destructor
renderGraphics::renderGraphics() {
    this -> initVariables();
    this -> initPiece();
}

renderGraphics::~renderGraphics() {
}



/*
void renderBoard::drawSquares() {
    for (int i {0}; i < board.size(); i++) {
        this -> window -> draw(board[i]);
    }
}
*/

gameController game;

void renderGraphics::drawPiece() {
    game.getWindow().draw(piece);
 //   game.getWindow() ->draw(piece);

}



void renderGraphics::render() {
    game.getWindow().clear(sf::Color::Black);

//    this -> drawSquares();

//    this -> drawPiece();

 //   game.getWindow().display();
}
