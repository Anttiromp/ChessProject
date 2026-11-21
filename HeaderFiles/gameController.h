#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "renderGraphics.h"
#include <bitset>

class gameController {

private:
// Variables
    sf::RenderWindow window;
    std::optional<sf::Event> event;
    renderGraphics renderer;
    std::bitset <64> board;
    float squareSize {};

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

// Private functions 
    void initWindow();
    void initVariables();
    
    


public:
    // Variables
    


    // Functions
    gameController(/* args */);
    ~gameController();
    
    const bool running() const;

    void pollEvents();
    sf::Vector2f getMousePosition();
    void update();
    std::bitset<64> setSquare(std::bitset<64>);
};






#endif