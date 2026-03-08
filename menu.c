#include <stdio.h>
#include <string.h>
#include "menu.h"

void sayHelloTest();

void menu(){

    //Setup commands
    Command commands[] = {
        {"idle", sayHelloTest},
        {"stress", sayHelloTest},
        {"rpm", sayHelloTest},
        {"temp", sayHelloTest},
        {"help", sayHelloTest},
        {"exit", sayHelloTest}
    }; 

    int NUMOF_COMMANDS = sizeof(commands) / sizeof(commands[0]);
    //NOTE: Discovered Buffer Overflow here. But using fgets prevents it automatically.
    char input[100];

    printf("================CEIR TERMINAL================");
    printf("\nPlease enter a command below.");
    printf("\n>");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1]= '\0';
    
    //Loop through commands, checking for users executed command.
    for(int i = 0; i < NUMOF_COMMANDS; i++ ){
        if(strcmp(input, commands[i].command)==0){
            printf("Command Matched");
            commands[i].handler();
        }
    }
    

}

void sayHelloTest(){
    printf("Hello, this function was called successfully");
}