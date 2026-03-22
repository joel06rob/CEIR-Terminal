#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "engine.h"
#include "cars.h"

void sayHelloTest();
void exit_program();
void help_commands();
void test_python();

//Setup commands
static Command commands[] = {
    {"idle", run_idle},
    {"cruise", run_cruise},
    {"stress", run_stress},
    {"addcar", add_car},
    {"test", test_python},
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

void test_python(){
    int result = system("python3 plot.py");

    if(result != 0){
        printf("failed to run python script");
    }
}