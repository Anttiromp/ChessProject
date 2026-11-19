#include "renderGraphics.h"
#include "gameController.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    // Initialize
    renderGraphics graphics;
    gameController game;


    // Game loop
    while (game.running() ) {
        // Update
        game.update();

        // Render
        graphics.render();

    }

    return 0;
}