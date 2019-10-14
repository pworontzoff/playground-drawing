#ifndef DRAWING_H_INCLUDED
#define DRAWING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415
#define LEFT -1
#define RIGHT 1

struct RGB {
    unsigned char red;
    unsigned char green;
    unsigned char bleue;
};

struct _coordinate {
    int x;
    int y;
};

struct _coordinate_lst {
    struct _coordinate coordinate;
    int length; // 0 if next is null
    struct RGB color;
    struct _coordinate_lst *next;
};

struct _drawing {
    int height;
    int width;
    float angle;
    int nbLines;
    float anim_duration;
    struct RGB color;
    struct _coordinate current;
};

struct _drawing _the_draw;
struct _coordinate_lst *_movements;


void init_drawing(int, int, float);
void display_drawing();
void change_color(unsigned char, unsigned char, unsigned char);
void turn(int,int);
void draw(int);
void move(int, int);

void _init_drawing(struct _drawing *, int, int, float);
void _draw(struct _drawing *, struct _coordinate_lst **, int);
void _change_color(struct _drawing *,unsigned char, unsigned char, unsigned char);
void _push(struct _coordinate_lst **, struct _coordinate, int, struct RGB);
void _turn(struct _drawing *, int, int);
void _display_drawing(struct _drawing, struct _coordinate_lst *);
void _move(struct _drawing *,int, int);
int _getSizeOfLineFrom(struct _coordinate_lst *, int);

#endif // DRAWING_H_INCLUDED
