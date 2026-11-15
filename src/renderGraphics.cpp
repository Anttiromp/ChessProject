#include "renderGraphics.h"
#include <iostream>

void renderBoard::initVariables() {
    this -> window = nullptr;
    this -> board = initBoard();
}

void renderBoard::initWindow() {
    // TODO videomode erilliseen muuttujaan tsekkaa dokumentaatio
    this -> window = new sf::RenderWindow(sf::VideoMode({700, 700}), "Chessboard", sf::Style::Titlebar | sf::Style::Close);
}

std::vector<sf::RectangleShape> renderBoard::initBoard() {
    std::vector<sf::RectangleShape> board;
    float squareOffset {87.5};
    this -> square.setSize(sf::Vector2(87.5f, 87.5f));

    float rank {};
    

    for (int i {1}; i <= 8; i++) {
        float file{};
        for (int j {1}; j <= 8; j++) {
            this -> square.setPosition(sf::Vector2f(file, rank));
            if (j % 2 == 0 && i % 2 != 0) {
                this -> square.setFillColor(sf::Color::Red);
                board.push_back(square);
                file += squareOffset;
                continue;
        }
        this -> square.setFillColor(sf::Color::Cyan);
        board.push_back(square);
        file += squareOffset;
        }
        rank += squareOffset;
    }

    return board;
}


// Constructor & Destructor
renderBoard::renderBoard() {
    this -> initVariables();
    this -> initBoard();
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
    std::cout << "Mouse position: " << sf::Mouse::getPosition(*this -> window).x << " " << sf::Mouse::getPosition(*this -> window).y << '\n';
}

void renderBoard::render() {
    this -> window -> clear(sf::Color::Black);

    for (int i {0}; i < board.size(); i++) {
        this -> window -> draw(board[i]);
      //  this -> window -> display(); // DEBUG
    }

    this -> window -> display();
}
