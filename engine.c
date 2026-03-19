#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "engine.h"

void run_idle(){
    printf("\nSTARTING IDLE TEST...\n");

    for(int i = 0; i < 10; i++){
        printf("%d\n", random_RPM(700,800));
    }
    

    //Get random values (But more stable)
    //After Test: User input [Y] or [N] Do they want a report. 
    //After Input: Open Report [Y] or [N] (Python)
}

void run_stress(){

    //Get highly random values
}

int random_RPM(int min, int max){
    return min + rand() % (max + 1 - min);
}