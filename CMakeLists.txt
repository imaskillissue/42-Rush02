cmake_minimum_required(VERSION 3.26)
project(rush02 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER cc)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

include_directories(.)

add_executable(rush02 main.c
        map.c
        map.h
        parser.c
        string_utilities.c
        string_utilities.h)
