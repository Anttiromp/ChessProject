#include "gameController.h"
#include "renderGraphics.h"


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

void gameController::getMousePosition() {
 //   this -> mousePosWindow = sf::Mouse::getPosition(*this -> window);
  //  this -> mousePosView = this -> window -> mapPixelToCoords(this -> mousePosWindow);
}


// Functions
void gameController::pollEvents() {
    // Event polling
    while (const std::optional event = window.pollEvent() ) {
        if (event -> is <sf::Event::Closed>()) {
            window.close();
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
    window.clear(sf::Color::Black);
    renderer.render();

    this -> pollEvents();


    window.display();

}