#include <stdio.h>
#include <stdlib.h>
#include "drawing.h"

#define WIDTH 400
#define HEIGHT 400

int main() {
    init_drawing(WIDTH, HEIGHT, 0.5);
    
    

    display_drawing();
    return 0;
}
