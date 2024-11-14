#include "bmp.h"
#include "input-output.h"

uint32_t count_padding(struct image* img){
    uint32_t row_size = img->width * sizeof(struct pixel);
    return (4 - (row_size % 4)) % 4;
}

enum status read_from_bmp(FILE* input, struct image* img){
    struct bmp_header header;
    size_t hdr = fread(&header, sizeof(struct bmp_header), 1, input);
    if (hdr != 1) return ERROR_HEADER;

    *img = create_image(header.biWidth, header.biHeight);
    uint32_t padding = count_padding(img);

    for (uint32_t i = 0; i < header.biHeight; i++){
        fread(&(img->data[i * header.biWidth]), sizeof(struct pixel), header.biWidth, input);
        fseek(input, (long) padding, SEEK_CUR);
    }

    return OK;
}


enum status write_to_bmp(FILE* output, struct image* img){
    struct bmp_header header = create_header(count_padding(img), img->width, img->height);
    if (fwrite(&header, sizeof(struct bmp_header), 1, output) != 1) return WRITE_ERROR;

    for (uint32_t i = 0; i < img->height; i++){
        if (fwrite(&(img->data[img->width * i]), sizeof(struct pixel), img->width, output) != img->width) return WRITE_ERROR;
        fseek(output, (long) count_padding(img), SEEK_CUR);
    }

    return OK;
}
