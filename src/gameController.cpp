#include "gameController.h"

/*
Game / Controller

Responsibilities:
- Run the main game loop.
- Forward relevant player input to the board.
- Tell the renderer when to draw the current game state.
- Manage the overall game lifecycle.


TODO
2. Testiks yks neliö tähän ikkunaan, pastaa raahaustoiminto
3. graphics.cpp siihen malliin et saadaan lauta pöydälle
4. Board.cpp:stä ei tarvi viel toistaseks välittää

*/

void gameController::initWindow() {
    this -> window = new sf::RenderWindow(sf::VideoMode({700, 700}), "Chessboard", sf::Style::Titlebar | sf::Style::Close);
}

const bool gameController::running() const {
    return this -> window -> isOpen();
}

gameController::gameController() {
    this -> initWindow();
}

gameController::~gameController() {
    delete this -> window;
}

void gameController::getMousePosition() {
    this -> mousePosWindow = sf::Mouse::getPosition(*this -> window);
    this -> mousePosView = this -> window -> mapPixelToCoords(this -> mousePosWindow);
}


// Functions
void gameController::pollEvents() {
    // Event polling
    while (const std::optional event = window -> pollEvent() ) {
        if (event -> is <sf::Event::Closed>()) {
            window -> close();
            break;
        }

        }
    }

/*
void gameController::movePiece() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        this -> piece.setPosition(mousePosView);
    }
}
    */


void gameController::update() {
    this->pollEvents();
    this -> getMousePosition();

}