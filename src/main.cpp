#include "graphics.h"
#include <iostream>

int main() {

    // Initialize
    renderGraphics renderGraphics;

    // Game loop
    while (renderGraphics.running() ) {
        // Update
        renderGraphics.update();

        // Render
        renderGraphics.render();

    }

    return 0;
}