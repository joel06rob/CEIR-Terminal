#include <stdio.h>
#include <string.h>
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
    cars[car_count].brand[strcspn(cars[car_count].brand, "\n")] = '\0';

    printf("Enter Colour: ");
    fgets(cars[car_count].colour, sizeof(cars[car_count].colour), stdin);
    cars[car_count].colour[strcspn(cars[car_count].colour, "\n")] = '\0';

    printf("Enter Engine Size: ");
    scanf("%f", &cars[car_count].engine);
    getchar();
    
    car_count++;

    printf("Car added successfully!\n");
}

void view_cars(){
    for(int i = 0; i < car_count; i++){
        printf("%s, %s, %.1f\n", cars[i].brand, cars[i].colour, cars[i].engine);
    }
}
