#include "gameController.h"
#include "renderGraphics.h"
#include <iostream>

void gameController::initVariables() {
    this -> squareSize = {87.5};
    this -> board = {};
}

const bool gameController::running() const {
    return window.isOpen();

}

gameController::gameController() 
    : window(sf::RenderWindow(sf::VideoMode({700, 700}), "Chessboard", sf::Style::Titlebar | sf::Style::Close)),
    renderer(window) {
        gameController::initVariables();

    }

gameController::~gameController() {
    window.close();
}

sf::Vector2f gameController::getMousePosition() {
    this -> mousePosWindow = sf::Mouse::getPosition(window);
    this -> mousePosView = this -> window.mapPixelToCoords(this -> mousePosWindow);
    return mousePosView;
}


// Functions
void gameController::pollEvents() {
    // Event polling
    while (const std::optional event = window.pollEvent() ) {
        if (event -> is <sf::Event::Closed>()) {
            window.close();
            break;
        }

        printSquare();
        }
    }
/**
 * Function sets a bit, 0.5f value is added to always get neares full integer when clicked in order to index bit
 * To get correct index in the bitboard, row is * 8 (board is 8x8) and result is then 
 * TODO replace magic numbers with descriptive variables
 * 
 * TODO check if within window bounds
 */

std::bitset<64> gameController::setSquare(std::bitset<64> bitBoard) {
    int file = (getMousePosition().x/squareSize);
    int row = (getMousePosition().y/squareSize);
    int bitIndex = (row * 8) + file;
    std::cout << "Clicked file: " << file << " row: " << row << '\n'; // TODO not needeed when done
    bitBoard.set(bitIndex);
    std::cout << "Bitboard after set: " << bitBoard << '\n';

    return bitBoard;
}


void gameController::printSquare() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        this -> setSquare(board);
        std::cout << "Bitboard: " << board << '\n'; // TODO can be deleted at the end
        
        
    }
}


void gameController::update() {
    window.clear(sf::Color::Black);
    renderer.render();

    this -> pollEvents();


    window.display();

}