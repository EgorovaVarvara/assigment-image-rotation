#include <stdio.h>
#include "util.h"
#include "image.h"
#include "input-output.h"
#include "rotation.h"
#include "util.h"

int main( int argc, char** argv ) {
    if (argc < 2) return print_status(ERROR_ARGS_COUNT);

    struct args args = read_args(argv);

    if (args.status != OK) return print_status(args.status);


    struct image old;
    enum status read_status = read_from_bmp(args.input, &old);
    if (read_status != OK) return print_status(read_status);

    struct image new = rotate(&old);

    enum status write_status = write_to_bmp(args.output, &new);
    if (write_status != OK) return print_status(write_status);

    destroy_image(&new);
    return 0;
}
