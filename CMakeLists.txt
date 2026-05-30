cmake_minimum_required(VERSION 3.20)

project(turnIntoGray
    VERSION 1.0.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
    src/main.c
)