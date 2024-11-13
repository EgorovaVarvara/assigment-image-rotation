#ifndef INPUT_OUTPUT
#define INPUT_OUTPUT

#include "stdio.h"
#include "image.h"

enum read_status {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
};

enum write_status {
    WRITE_OK = 0,
    WRITE_ERROR
};

enum write_status write_to_bmp(FILE* in, struct image* img);



enum read_status read_from_bmp(FILE* out, struct image* img);

#endif
