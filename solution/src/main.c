#include <stdio.h>
#include "validator.h"
#include "image.h"
#include "input-output.h"
#include "rotation.h"

int main( int argc, char** argv ) {


    struct args args = read_args(argv);

    if (!args.valid){
        return 0;
    }

    struct image old;
    read_from_bmp(args.input, &old);

    struct image new = rotate(&old, args.angle);

    write_to_bmp(args.output, &new);

    return 0;
}
