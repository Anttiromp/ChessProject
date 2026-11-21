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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            this -> board = setSquare(board);
        }

        }
    }
/**
 * Function sets a bit, by counting index for rows & columns on the board, and setting the correspoding bitIndex to 1
 * @returns bitset<64> Variable containing set bits in the board bitboard-representation
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


void gameController::update() {
    window.clear(sf::Color::Black);
    renderer.render();

    this -> pollEvents();


    window.display();

}