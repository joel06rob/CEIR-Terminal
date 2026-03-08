#include <stdio.h>
#include <string.h>
#include "menu.h"

void sayHelloTest();
void exit_program();
void help_commands();

//Setup commands
Command commands[] = {
    {"idle", sayHelloTest},
    {"stress", sayHelloTest},
    {"rpm", sayHelloTest},
    {"temp", sayHelloTest},
    {"help", help_commands},
    {"exit", exit_program}
}; 
int NUMOF_COMMANDS = sizeof(commands) / sizeof(commands[0]);

void menu(){

    //NOTE: Discovered Buffer Overflow here. But using fgets prevents it automatically.
    char input[100];

    printf("================CEIR TERMINAL================");
    printf("\nPlease enter a command below.");

    do{
        printf("\n>");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1]= '\0';
    
        
        //Loop through commands, checking for users executed command.
        for(int i = 0; i < NUMOF_COMMANDS; i++ ){
            if(strcmp(input, commands[i].command)==0){
                commands[i].handler();
            }
        }
    }while(strcmp(input, "exit")!=0);
    

    

}

void sayHelloTest(){
    printf("Hello, this function was called successfully");
}

void exit_program(){
    printf("\nThankyou for using CEIR Terminal!");
    printf("\nEXITING...");
}

void help_commands(){
    printf("\nHere is a full list of commands:");
    for(int i = 0; i < NUMOF_COMMANDS; i++){
        printf("\n%s", commands[i].command);
    }

}