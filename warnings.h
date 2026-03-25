#ifndef WARNINGS_H
#define WARNINGS_H

#include <time.h>

typedef struct {
    time_t timestamp;
    char type[100];
    float value;
} Warnings;

void add_warning(char *warningmsg, float value);
void view_warnings();
void check_warnings();
void init_warnings();
void free_warnings();

#endif