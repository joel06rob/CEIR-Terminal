#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "warnings.h"

Warnings *warnings = NULL;
int WARNING_COUNT = 0;
int WARNING_CAP = 2;


//Could change to bool and exit the program in main if returns 1
void init_warnings(){
    warnings = malloc(sizeof(Warnings) * WARNING_CAP);
    if(warnings == NULL){
        printf("*ERROR* Memory Allocation Failed\n");
        return;
    }
}


void add_warning(char *warningmsg, float warningvalue){
    
    //Memory - Reallocate memory if the cap for warnings has already been hit.
    if(WARNING_COUNT >= WARNING_CAP){
        WARNING_CAP += 2;
        Warnings *temp = realloc(warnings, sizeof(Warnings) * WARNING_CAP);
        if(temp == NULL){
            printf("*ERROR* Memory Reallocation Failed\n");
            return;
        }
        warnings = temp;
    }

    //Add new warning
    warnings[WARNING_COUNT].timestamp = time(NULL);
    strcpy(warnings[WARNING_COUNT].type, warningmsg);
    warnings[WARNING_COUNT].value = warningvalue;

    WARNING_COUNT++;
}

void view_warnings(){
    for(int i = 0; i < WARNING_COUNT; i++){

        //Format the Epoch time using the tm struct from time.h
        struct tm *t = localtime(&warnings[i].timestamp);
        char buffer[32];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", t);

        printf("[%s] %s %.2f\n", buffer, warnings[i].type, warnings[i].value);
    }
}

void check_warnings(){
    if(WARNING_COUNT > 0){
        view_warnings();
    }
}

void free_warnings(){
    free(warnings);
}