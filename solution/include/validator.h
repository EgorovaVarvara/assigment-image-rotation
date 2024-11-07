#ifndef VALIDATOR
#define VALIDATOR

#include <stdio.h>
#include <stdint.h>

enum status{
    OK = 0,
    ERROR_OPEN,
    ERROR_CLOSE,
    ERROR_ARGS
};

struct args{
    FILE* input;
    FILE* output;
    int16_t angle;
};

struct args read_args(char** args);

#endif
