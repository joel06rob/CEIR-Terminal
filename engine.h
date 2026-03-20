#ifndef ENGINE_H
#define ENGINE_H

typedef struct {
    int rpm;
    float temp;
    float oil;
} EngineData;

void run_idle();
void run_cruise();
void run_stress();

#endif