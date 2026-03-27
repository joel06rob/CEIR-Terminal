#ifndef CARS_H
#define CARS_H

typedef struct {
    char brand[100];
    char colour[100];
    float engine;
} Cars;

void add_car();
void view_cars();

#endif