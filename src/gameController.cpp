#include "gameController.h"
#include "renderGraphics.h"



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

renderGraphics graphics;

void gameController::update() {
    this -> window -> clear(sf::Color::Black);

    this -> pollEvents();
    this -> getMousePosition();


    this -> window -> display();

}