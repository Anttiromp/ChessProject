#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <SFML/Graphics.hpp>
#include "renderGraphics.h"

class gameController {

private:
// Variables
    sf::RenderWindow window;
    std::optional<sf::Event> event;
    renderGraphics renderer;
    

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

// Private functions 
    void initWindow();
    
    


public:
    // Variables


    // Functions
    gameController(/* args */);
    ~gameController();
    
    const bool running() const;

    void pollEvents();
    sf::Vector2f getMousePosition();
    void update();
    void printSquare();
};






#endif