#include <stdio.h>
#include <stdlib.h>
#include "drawing.h"

#define WIDTH 800
#define HEIGHT 600

int main() {
    init_drawing(WIDTH, HEIGHT, 0.5);
    
    

    display_drawing();
    return 0;
}
