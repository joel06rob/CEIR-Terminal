#include <stdio.h>
#include "cars.h"

Cars cars[10];
int car_count = 0;

void add_car(){
    if(car_count>=10){
        printf("Car list full");
        return;
    }

    printf("Enter Brand: ");
    fgets(cars[car_count].brand, sizeof(cars[car_count].brand), stdin);

    printf("Enter Colour: ");
    fgets(cars[car_count].colour, sizeof(cars[car_count].colour), stdin);

    printf("Enter Engine Size: ");
    scanf("%f", &cars[car_count].engine);
    
    car_count++;

    printf("Car added successfully!\n");
}

/*for(int i = 0; i < car_count; i++){
        printf("%s\n", cars[i].brand);
        printf("%s\n", cars[i].colour);
        printf("%f\n", cars[i].engine);
    }*/