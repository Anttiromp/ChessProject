#include "renderGraphics.h"

void renderBoard::initVariables()
{
    this->window = nullptr;
}

void renderBoard::initWindow()
{
    // TODO videomode erilliseen muuttujaan tsekkaa dokumentaatio
    this->window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Chessboard", sf::Style::Titlebar | sf::Style::Close);
}

// Constructor & Destructor
renderBoard::renderBoard()
{
    this->initVariables();
    this->initWindow();
}

renderBoard::~renderBoard()
{
    delete this->window;
}

const bool renderBoard::running() const
{
    return this->window->isOpen();
}

/*
    while (const std::optional event = window->pollEvent())
*/

// Functions
void renderBoard::pollEvents()
{
    // Event polling
    while (const std::optional event = window->pollEvent() )
    {
        if (event->is<sf::Event::Closed>())
        {
            window->close();
            break;
        }
    }
}

void renderBoard::update()
{
    this->pollEvents();
}

void renderBoard::render()
{
    this->window->clear(sf::Color::Black);

    this->window->display();
}
