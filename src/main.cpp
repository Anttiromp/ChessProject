#include "renderGraphics.h"
#include "gameController.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    // Initialize
    gameController game;


    // Game loop
    while (game.running() ) {
        // Update
        game.update();

    }

    return 0;
}