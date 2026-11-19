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
    std::vector<sf::RectangleShape> board;
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

sf::RectangleShape renderGraphics::initPiece() {

    sf::RectangleShape piece;
    piece.setFillColor(sf::Color::Green);
    piece.setSize(sf::Vector2(87.5f, 87.5f));
    
    return piece;
    
}

renderGraphics::renderGraphics(sf::RenderWindow& window)
    : window(window) {
        this -> initVariables();
}


renderGraphics::~renderGraphics() {
}


void renderGraphics::drawSquares() {
    for (int i {0}; i < board.size(); i++) {
        window.draw(board[i]);
    }
}



void renderGraphics::render() {

   this -> drawSquares();

//    this -> drawPiece();

}
