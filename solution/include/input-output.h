#ifndef INPUT_OUTPUT
#define INPUT_OUTPUT

#include "stdio.h"
#include "util.h"
#include "image.h"


enum status write_to_bmp(FILE* in, struct image* img);



enum status read_from_bmp(FILE* out, struct image* img);

#endif
