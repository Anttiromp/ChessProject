#include "renderGraphics.h"

void renderBoard::initVariables() {
    this -> window = nullptr;
}

void renderBoard::initWindow() {
    // TODO videomode erilliseen muuttujaan tsekkaa dokumentaatio
    this -> window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Chessboard", sf::Style::Titlebar | sf::Style::Close);

}


// Constructor & Destructor
renderBoard:: renderBoard() {
    this -> initVariables();
    this -> initWindow();


}

renderBoard::~renderBoard() {
    delete this->window;

}

const bool renderBoard::running() const{
    return this -> window -> isOpen();
}

// Functions
void renderBoard::pollEvents() {

    // Event polling

    
}

void renderBoard::update() {
    this -> pollEvents();

}

void renderBoard::render() {

}

