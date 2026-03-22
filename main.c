#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "warnings.h"

int main(){

    srand(time(NULL));
    init_warnings();
    
    menu();

    free_warnings();
    return 0;
}