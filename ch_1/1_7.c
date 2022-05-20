#include <stdio.h>
#include <stdlib.h>

struct Color {
        char r;
        char g;
        char b;
};

struct Pixel {
        size_t x;
        size_t y;
        struct Color *rgb;
};

struct Grid {
        size_t length;
        size_t width;
        struct Pixel ***screen;
};

struct Color *make_color(char r, char g, char b) 
{
        struct Color *new_color = malloc(sizeof(struct Color));
        if (!new_color)
                exit(1);
        new_color->r = r;
        new_color->g = g;
        new_color->b = b;
        return new_color;
}

struct Pixel *make_pixel(size_t x, size_t y, char r, char g, char b) 
{
        struct Pixel *new_pixel = malloc(sizeof(struct Pixel));
        if (!new_pixel)
                exit(2);
        struct Color *new_color  = make_color(r, g, b);
        new_pixel->rgb = new_color;
        return new_pixel;
}

struct Grid *make_grid(size_t l, size_t w) 
{
        struct Grid *new_grid = malloc(sizeof(struct Grid));
        if (!new_grid)
                exit(1);
        new_grid->length = l;
        new_grid->width = w;
        new_grid->screen = malloc(sizeof(struct Pixel ***) * (l * w));
        if(!new_grid->screen)
                exit(1);
        return new_grid;
}

void display_pixel(struct Pixel *p)
{
        printf("%d", p->rgb->g);
}


int main() {
        size_t length = 2;
        size_t width = 2;
        struct Grid *grid = make_grid(length, width);
        ***grid->screen[0][0] = ***make_pixel(0, 0, 1, 2, 3);
//        for (int i = 0; i < length; i++) {
//                for (int j = 0; j < width; j++) {
//                        grid->screen[i][j] = *make_pixel(i, j, 1, 2, 3);
//                }
//        }

        return 0;
}
