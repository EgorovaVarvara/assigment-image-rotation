#include "rotation.h"

struct image rotate(struct image* old, int64_t angle){
    struct image new = create_image(old->height, old->width);

    for (uint64_t x = 0; x < old->width; x++){
        for (uint64_t y = 0; y < old->height; y++){
            new.data[y*(old->height - x) + y] = old->data[y*old->height + x];
        }
    }
    destroy_image(old);
    return new;
}
