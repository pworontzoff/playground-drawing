#include "drawing.h"

void _init_drawing(struct _drawing *draw, int width, int height) {
    draw->height=height;
    draw->width=width;
    draw->angle = 0;
    draw->current.x = width/2;
    draw->current.y = height/2;
    draw->color.bleue = 255;
    draw->color.green = 0;
    draw->color.red = 0;
}

void _change_color(struct _drawing * draw,unsigned char red, unsigned char green, unsigned char bleue) {
    draw->color.bleue = bleue;
    draw->color.green = green;
    draw->color.red = red;
}

void _display_drawing(struct _drawing draw, struct _coordinate_lst *lst) {

    struct _coordinate prec;
    FILE *fp;
    char buffer[500];

    fp = fopen("output.html","wt");

    prec = lst->coordinate;
    lst = lst->next;
    sprintf(buffer,"<svg height='%d' width='%d' style='border: 1px solid black'>\n",draw.height,draw.width);
    fputs(buffer,fp);
    while (lst!=NULL) {
        sprintf(buffer,"<line x1='%d' y1='%d' x2='%d' y2='%d' style='stroke:rgb(%d,%d,%d);stroke-width:2' />\n",prec.x,prec.y,lst->coordinate.x,lst->coordinate.y,lst->color.red,lst->color.green,lst->color.bleue);
        fputs(buffer,fp);
        prec = lst->coordinate;
        lst = lst->next;
    }
    fputs("</svg>",fp);
    fclose(fp);
    //system("cmd /c start output.html");
}

void _turn(struct _drawing *draw, int angle, int side) {
    draw->angle = draw->angle + side * (angle * PI / 180);
}

void _move(struct _drawing *draw,int x, int y) {
    draw->current.x=x;
    draw->current.y=y;
}

void _draw(struct _drawing *draw, struct _coordinate_lst **movement, int length) {
    struct _coordinate new_coord;

    //printf("x : %d - y : %d \n",draw->current.x,draw->current.y);

    new_coord.x = round(length * cos(draw->angle) + draw->current.x);
    new_coord.y = round(length * sin(draw->angle) + draw->current.y);

    if (*movement==NULL) {
        _push(movement,draw->current, draw->color);
    }

    draw->current = new_coord;
    _push(movement,new_coord,draw->color);
}

void _push(struct _coordinate_lst **lst, struct _coordinate coord, struct RGB color) {
    struct _coordinate_lst *new_c, *current, *prec;

    new_c = malloc(sizeof(struct _coordinate_lst));

    new_c->coordinate = coord;
    new_c->color = color;

    prec=NULL;
    current = *lst;

    while (current!=NULL) {
        prec=current;
        current = current->next;
    }

    new_c->next = NULL;
    if (prec==NULL)
        *lst = new_c;
    else
        prec->next = new_c;

}


void init_drawing(int width, int height) {
     _movements = NULL;
    _init_drawing(&_the_draw,width,height);
}

void display_drawing() {
    _display_drawing(_the_draw,_movements);
}

void change_color(unsigned char red, unsigned char green, unsigned char bleue) {
    _change_color(&_the_draw,red,green,bleue);
}

void turn(int angle, int side) {
    _turn(&_the_draw,angle,side);
}

void draw(int length) {
    _draw(&_the_draw,&_movements,length);
}

void move(int x, int y) {
    _move(&_the_draw,x,y);
}
