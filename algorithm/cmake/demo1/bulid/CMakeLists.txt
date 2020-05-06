cmake_minimum_required(VERSION 3.0)

project(Demo1)
# 显示详细信息
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS
    "-g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -pthread"
        )
    # CMAKE_INSTALL_PREFIX()


# add_compile_options(-pthread)

add_executable(Demo main.cc)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
