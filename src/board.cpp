#include "board.h"
#include <iostream>

void renderBoard::initVariables() {
    this -> window = nullptr;
    this -> board = initBoard();
    this -> piece = initPiece();
    this -> mousePos = getMousePosition();
}

void renderBoard::initWindow() {
    this -> window = new sf::RenderWindow(sf::VideoMode({700, 700}), "Chessboard", sf::Style::Titlebar | sf::Style::Close);
}
/**
 * @return Vector containing different colored squares 
 * 
 * For each step, the loop assigns either a dark or light color on a square, and pushes it to vector containing 
 * all 64 chess squares. When one rank gets 8 squares assigned, it offsets & swaps the two colors, resulting 
 * in alternating chess board color scheme.
 */

std::vector<sf::RectangleShape> renderBoard::initBoard() {
    std::vector<sf::RectangleShape> board; // TODO looks funky, compare to initWindow
    float squareOffset {87.5};
    this -> square.setSize(sf::Vector2(87.5f, 87.5f));

    auto darkSquare = sf::Color{181, 136, 99};
    auto lightSquare = sf::Color{240, 217, 181};

    float rank {};
    float file {};

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
        
        // Offset rank when file is full & flip color scheme
        if (i % 8 == 0) {
            rank += squareOffset;
            file = 0;
            std::swap(darkSquare, lightSquare);
        }
    }

    return board;
}

// TODO NOT A PART OF THE BOARD
sf::RectangleShape renderBoard::initPiece() {

    sf::RectangleShape piece;
    piece.setFillColor(sf::Color::Green);
    piece.setSize(sf::Vector2(87.5f, 87.5f));
    
    return piece;
    
}

// Constructors & Destructor
renderBoard::renderBoard() {
    this -> initVariables();
    this -> initWindow();
    this -> initPiece();
}

renderBoard::~renderBoard() {
    delete this -> window;
}

const bool renderBoard::running() const {
    return this -> window -> isOpen();
}

// TODO tämä palauttaa jotenkin väärän arvon meille, sen takia se neliö häviää ruudulta
// Huomen fiksaus
sf::Vector2f renderBoard::getMousePosition() {
    sf::Vector2 iPosition = sf::Vector2i(sf::Mouse::getPosition());

    return static_cast<sf::Vector2f> (iPosition);
}


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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
       //     piece.setPosition(mousePos);
         //   sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
         std::cout << "Mouse position: " << sf::Mouse::getPosition(*this -> window).x << " " << sf::Mouse::getPosition(*this -> window).y << '\n';
        }
    }
}



void renderBoard::update() {
    this->pollEvents();

    // Test mouse position TODO POISTA KUNHAN SAADAAN KLIKSUTTELU TOIMICAKS
 //   std::cout << "Mouse position: " << sf::Mouse::getPosition(*this -> window).x << " " << sf::Mouse::getPosition(*this -> window).y << '\n';
}

void renderBoard::drawSquares() {
    for (int i {0}; i < board.size(); i++) {
        this -> window -> draw(board[i]);
    }
}

void renderBoard::drawPiece() {
    this -> window->draw(piece);

}


void renderBoard::render() {
    this -> window -> clear(sf::Color::Black);

    this -> drawSquares();

    this -> drawPiece();

    this -> window -> display();
}
