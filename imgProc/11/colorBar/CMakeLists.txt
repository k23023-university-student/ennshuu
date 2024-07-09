cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 11)
project(colorBar4student)
find_package(OpenCV 4.4.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
file(GLOB SOURCES *.cpp)
add_executable (colorBar4student ${SOURCES})
target_link_libraries (colorBar4student
PRIVATE ${OpenCV_LIBS}
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
