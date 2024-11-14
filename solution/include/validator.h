#ifndef VALIDATOR
#define VALIDATOR

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

enum status{
    OK = 0,
    ERROR_OPEN,
    ERROR_CLOSE,
    ERROR_ARGS
};

struct args{
    FILE* input;
    FILE* output;
    int64_t angle;
    bool valid;
};

struct args read_args(char** args);

#endif
