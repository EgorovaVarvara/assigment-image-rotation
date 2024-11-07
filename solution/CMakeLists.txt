file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(image-transformer ${sources}
        include/image.h
        include/input-output.h
        include/bmp.h
        include/rotation.h
        include/validator.h)
target_include_directories(image-transformer PRIVATE src include)
