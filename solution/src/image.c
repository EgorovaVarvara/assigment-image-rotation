#include <malloc.h>
#include "image.h"

struct image create_image(uint64_t width, uint64_t height){
    struct image newimg;
    newimg.width = width;
    newimg.height = height;
    newimg.data = malloc(sizeof(struct pixel) * width * height);
    return newimg;
}

void destroy_image(struct image* img){
    free(img->data);
    img->height = 0;
    img->width = 0;
}
