cmake_minimum_required(VERSION 3.29.3)
project(vanilla)

include(FetchContent)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -Wall -Wextra -Wpedantic -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi")

set(CMAKE_C_STANDARD            17)
set(CMAKE_C_STANDARD_REQUIRED   YES)
set(CMAKE_C_EXTENSIONS          OFF)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4 # Use a specific, recent tag for stability
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    main.c
    src/vanilla.c
    src/vkcontext.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    vulkan
)

# target_link_libraries(${PROJECT_NAME} PRIVATE )