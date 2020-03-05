cmake_minimum_required(VERSION 3.0)

project(Demo1)

set(CMAKE_CXX_FLAGS
    "-g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -pthread"
        )

# add_compile_options(-pthread)

add_executable(Demo main.cc)
