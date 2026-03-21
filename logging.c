#include <stdio.h>
#include "logging.h"
#include "engine.h"

void log_data(FILE *file, int time, EngineData *data){

    fprintf(file, "%d,%d,%.2f,%.2f\n", time, data->rpm, data->temp, data->oil);
}
