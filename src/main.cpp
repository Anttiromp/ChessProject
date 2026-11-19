#include "board.h"
#include "gameController.h"
#include <iostream>

int main() {

    // Initialize
    renderBoard board;
    gameController game;

    // Game loop
    while (game.running() ) {
        // Update
        game.update();

        // Render
        board.render();

    }

    return 0;
}