cmake_minimum_required(VERSION 3.19.2)

set(CMAKE_C_STANDARD 23)

# Static runtime on windows
set(CMAKE_MSVC_RUNTIME_LIBRARY Multithreaded$<$<CONFIG:Debug>:Debug>)
set(CMAKE_MSVC_RUNTIME_LIBRARY Multithreaded$<$<CONFIG:Release>:Release>)

if (MSVC)
  add_compile_options(/arch:AVX2) # Make sure SIMD works on Windows
endif()

project(type-cpp)
# Define MY_SOURCES to be list of all source files needed
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(${CMAKE_PROJECT_NAME} ${MY_SOURCES})

# Link ncurses
find_package(Curses REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CURSES_LIBRARIES})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIR})
