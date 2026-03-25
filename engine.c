#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "engine.h"
#include "logging.h"
#include "warnings.h"

static int random_Data(int min, int max);
static void print_data(int time, EngineData *data);

void run_idle(){
    printf("\nSTARTING IDLE TEST...\n");

    //Configure logging + printing for data
    EngineData data;
    FILE *file = fopen("idle_log.csv", "w");
    if(file == NULL){
        printf("*ERROR* when opening idle_file.csv");

    }
    fprintf(file, "%s", "TIME,RPM,TEMP,OIL\n");
    printf("TIME   RPM   TEMP   OIL\n------------------------\n");


    for(int i = 0; i < 10; i++){
        data.rpm = random_Data(700,800);
        data.temp = random_Data(75, 90);
        data.oil = random_Data(30, 40);

        print_data(i, &data);
        log_data(file, i, &data);
    }

    fclose(file);
    


}

void run_cruise(){
    //Run on a typical rate between 2500 - 3500
    printf("\nSTARTING CRUISE TEST...\n");

    //Configure logging + printing for data
    EngineData data;
    FILE *file = fopen("cruise_log.csv", "w");
    if(file == NULL){
        printf("*ERROR* when opening cruise_file.csv");
        
    }
    fprintf(file, "%s", "TIME,RPM,TEMP,OIL\n");
    printf("TIME   RPM   TEMP   OIL\n------------------------\n");

    for(int i = 0; i < 10; i++){
        data.rpm = random_Data(2500,3500);
        data.temp = random_Data(80, 105);
        data.oil = random_Data(30, 40);

        print_data(i, &data);
        log_data(file, i, &data);
    }

    fclose(file);

}

void run_stress(){
    //Get highly random values - Use previous value and add more to it (Ascending RPM)
    printf("\nSTARTING CRUISE TEST...\n");

    //Configure logging + printing for data
    EngineData data;
    FILE *file = fopen("stress_log.csv", "w");
    if(file == NULL){
        printf("*ERROR* when opening stress_file.csv");
        
    }
    fprintf(file, "%s", "TIME,RPM,TEMP,OIL\n");
    printf("TIME   RPM   TEMP   OIL\n------------------------\n");

    int previous_RPM = 2700;
    int previous_Temp = 85;

    for(int i = 0; i < 10; i++){
        int temp_RPM = random_Data(previous_RPM, 5500);
        int temp_Temp = random_Data(previous_Temp, 110);
        previous_RPM = temp_RPM;
        previous_Temp = temp_Temp;
        data.rpm = temp_RPM;
        data.temp = temp_Temp;
        data.oil = random_Data(30,40);

        print_data(i, &data);
        log_data(file, i, &data);

        //Warnings
        if(data.temp > 105){
            add_warning("*WARNING* Temperature Overheating", data.temp);
        }
    }

    fclose(file);
    check_warnings();
}


static int random_Data(int min, int max){
    return min + rand() % (max + 1 - min);
}

static void print_data(int time, EngineData *data){
    printf("%d   %d   %f   %f\n", time, data->rpm, data->temp, data->oil);
}
