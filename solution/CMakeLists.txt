file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(image-transformer ${sources}
        include/input-output.h
        include/bmp.h
        include/rotation.h
        include/validator.h
        src/input_output.c
        src/image.c
        src/bmp.c
        src/validator.c
        src/rotation.c
        include/image.h)
target_include_directories(image-transformer PRIVATE src include)
