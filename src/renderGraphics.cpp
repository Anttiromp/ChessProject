#include "renderGraphics.h"
#include <iostream>

void renderBoard::initVariables() {
    this -> window = nullptr;
}

void renderBoard::initWindow() {
    // TODO videomode erilliseen muuttujaan tsekkaa dokumentaatio
    this -> window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Chessboard", sf::Style::Titlebar | sf::Style::Close);
}

void renderBoard::initObjects() {
    this -> object.setSize(sf::Vector2(100.f, 100.f));
    this -> object.setFillColor(sf::Color::Cyan);

}


// Constructor & Destructor
renderBoard::renderBoard() {
    this -> initVariables();
    this -> initObjects();
    this -> initWindow();
}

renderBoard::~renderBoard() {
    delete this -> window;
}

const bool renderBoard::running() const {
    return this -> window -> isOpen();
}

/*
    while (const std::optional event = window->pollEvent())
*/

// Functions
void renderBoard::pollEvents() {
    // Event polling
    while (const std::optional event = window -> pollEvent() )
    {
        if (event -> is <sf::Event::Closed>())
        {
            window -> close();
            break;
        }
    }
}

void renderBoard::update() {
    this->pollEvents();

    // Test mouse position
    std::cout << "Mouse position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << '\n';
}

void renderBoard::render() {
    this -> window -> clear(sf::Color::Black);

    this -> window -> draw(this -> object);

    this -> window -> display();
}
