#include <stdlib.h>
#include "util.h"

const char* messages[] = {
        "OK",
        "Error during open file",
        "Error during close file",
        "Wrong amount of arguments",
        "Invalid file header",
        "Write error occurred"
};

struct args read_args(char** args){
    FILE* input = fopen(args[1], "rb");
    FILE* output = fopen(args[2], "wb");

    if (input == NULL || output == NULL){
        return (struct args){.status = ERROR_OPEN};
    }

    return (struct args) {
            .input = input,
            .output = output,
            .status = OK
    };
}

enum status print_status(enum status status){
    printf("%s\n", messages[status]);
    return status;
}

enum status close (FILE* file){
    if (fclose(file) != 1){
        return print_status(ERROR_CLOSE);
    }
    return print_status(OK);
}
