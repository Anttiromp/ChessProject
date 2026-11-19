#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <SFML/Graphics.hpp>

class gameController {

private:
// Variables
    sf::RenderWindow* window {nullptr};
    std::optional<sf::Event> event;

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

// Private functions 
    void initWindow();
    
    


public:
    gameController(/* args */);
    ~gameController();

    const bool running() const;
    sf::RenderWindow& getWindow();

    void pollEvents();
    void getMousePosition();
    void update();
   // void movePiece();
};






#endif