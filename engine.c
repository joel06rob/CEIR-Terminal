#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "engine.h"

void run_idle(){
    printf("\nSTARTING IDLE TEST...\n");

    for(int i = 0; i < 10; i++){
        printf("%d\n", random_RPM(700,800));
    }
    
    //TODO: Include an array to store results + On report generation write results into a log file.

    //Get random values (But more stable)
    //After Test: User input [Y] or [N] Do they want a report. 
    //After Input: Open Report [Y] or [N] (Python)
}

void run_cruise(){
    //Run on a typical rate between 2500 - 3000
    printf("\nSTARTING CRUISE TEST...\n");

    for(int i = 0; i < 10; i++){
        printf("%d\n", random_RPM(2500,3000));
    }
}

void run_stress(){
    //Get highly random values - Use previous value and add more to it (Ascending RPM)
    int previous_RPM = 2700;

    for(int i = 0; i < 10; i++){
        int temp_RPM = random_RPM(previous_RPM, 5500);
        printf("%d\n", temp_RPM);
        previous_RPM = temp_RPM;
    }
}

int random_RPM(int min, int max){
    return min + rand() % (max + 1 - min);
}