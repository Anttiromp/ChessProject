#include "gameController.h"
#include "renderGraphics.h"
#include <iostream>


const bool gameController::running() const {
    return window.isOpen();

}

gameController::gameController() 
    : window(sf::RenderWindow(sf::VideoMode({700, 700}), "Chessboard", sf::Style::Titlebar | sf::Style::Close)),
    renderer(window) {

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

void gameController::printSquare() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        std::cout << "Mouse position: " << getMousePosition().x << " " <<  getMousePosition().y << '\n';
    }
}


void gameController::update() {
    window.clear(sf::Color::Black);
    renderer.render();

    this -> pollEvents();


    window.display();

}