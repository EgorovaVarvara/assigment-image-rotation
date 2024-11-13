#include "bmp.h"
#include "image.h"

struct bmp_header create_header(uint32_t padding, uint64_t width, uint64_t height){
    struct bmp_header header = {
            .bfType = 0x4D42,
            .biWidth = width,
            .biHeight = height,
            .biSizeImage = (padding + sizeof(struct pixel) * width)* height,
            .bOffBits = sizeof(struct bmp_header),
            .bfileSize = sizeof(struct bmp_header) + (padding + sizeof(struct pixel) * width) * height,
            .bfReserved = 0,
            .biSize = 40,
            .biPlanes = 1,
            .biBitCount = 24,
            .biCompression = 0,
            .biXPelsPerMeter = 2400,
            .biYPelsPerMeter = 2400,
            .biClrUsed = 0,
            .biClrImportant = 0
    };
    return header;
}
