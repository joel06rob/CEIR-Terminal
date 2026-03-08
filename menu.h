#ifndef MENU_H
#define MENU_H

void menu();

//Struct for commands
//  > Each command has a function
typedef struct{
    char *command;
    void (*handler)();
}Command;

#endif