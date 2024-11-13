#include <stdlib.h>
#include "validator.h"

struct args read_args(char** args){
    FILE* input = fopen(args[1], "rb");
    FILE* output = fopen(args[2], "wb");

    char* p;
    long converted = strtol(args[3], &p, 10);

    int16_t angle = -((int16_t) converted);
    if (angle < 0) angle = 360 + angle;
    if (angle != 0 && angle != 90 && angle != 180 && angle != 270) {
        return (struct input_data) { .status_code =  ERR_BAD_ANGLE };
    }

    return (struct args) {
            .input = input,
            .output = output,
            .angle = angle % 360,
    };
}

