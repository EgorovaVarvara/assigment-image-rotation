#include "rotation.h"

struct image rotate(struct image* old, int64_t angle){
    struct image new = create_image(old->height, old->width);

    for (uint64_t x = 0; x < old->width; x++){
        for (uint64_t y = 0; y < old->height; y++){
            new.data[x * old->height + (old->height - y - 1)] = old->data[y * old->width + x];
        }
    }
    destroy_image(old);
    return new;
}
