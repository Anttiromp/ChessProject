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
    auto darkSquare = sf::Color{181, 136, 99};
    auto lightSquare = sf::Color{240, 217, 181};

    float rank {};
    float file{};

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
        

        // Offset rank when file is full
        if (i % 8 == 0) {
            rank += squareOffset;
            file = 0;
        }
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
        this -> window -> display(); // DEBUG
    }

    this -> window -> display();
}
