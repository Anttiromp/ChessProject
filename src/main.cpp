#include "renderGraphics.h"
#include <iostream>

int main() {

    // Initialize
    renderBoard renderBoard;

    // Game loop
    while (renderBoard.running() ) {
        // Update
        renderBoard.update();

        // Render
        renderBoard.render();

    }

    return 0;
}