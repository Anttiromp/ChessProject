#include "board.h"
#include <iostream>

int main() {

    // Initialize
    renderBoard board;

    // Game loop
    while (board.running() ) {
        // Update
        board.update();

        // Render
        board.render();

    }

    return 0;
}