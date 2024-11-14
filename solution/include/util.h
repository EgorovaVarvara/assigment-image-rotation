#ifndef VALIDATOR
#define VALIDATOR

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

enum status{
    OK = 0,
    ERROR_OPEN,
    ERROR_CLOSE,
    ERROR_ARGS_COUNT,
    ERROR_HEADER,
    WRITE_ERROR
};

struct args{
    FILE* input;
    FILE* output;
    enum status status;
};

struct args read_args(char** args);
enum status print_status(enum status status);
enum status close(FILE* file);
#endif
