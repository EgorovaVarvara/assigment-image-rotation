#include <stdlib.h>
#include "validator.h"


struct args read_args(char** args){
    FILE* input = fopen(args[1], "rb");
    FILE* output = fopen(args[2], "wb");

    char* p;
    long angle = strtol(args[3], &p, 10);

    if (angle < 0) angle = 360 + angle;
    if (angle != 0 && angle != 90 && angle != 180 && angle != 270) {
        return (struct args) { .valid = false };
    }

    return (struct args) {
            .input = input,
            .output = output,
            .angle = angle % 360,
            .valid = true
    };
}

