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
        printf("%ld\n", warnings[i].timestamp);
        printf("%s\n", warnings[i].type);
        printf("%.2f\n", warnings[i].value);
    }
}

void free_warnings(){
    free(warnings);
}