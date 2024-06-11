cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 11)
project(alpha)
find_package(OpenCV 4.4.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
file(GLOB SOURCES *.cpp)
add_executable (alpha ${SOURCES})
target_link_libraries (alpha
PRIVATE ${OpenCV_LIBS}
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input1.jpg
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
     file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input2.jpg
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})