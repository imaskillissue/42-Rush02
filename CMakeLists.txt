cmake_minimum_required(VERSION 3.00)
project(rush02 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER cc)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/run)

include_directories(.)

add_executable(rush02 main.c
        map.c
        map.h
        parser.c
        split.c
        string_utils.h
        string_utils.c math.c math.h print_utils.c print_utils.h)
