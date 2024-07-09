cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 11)
project(changeColor4student)
find_package(OpenCV 4.4.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
file(GLOB SOURCES *.cpp)
add_executable (changeColor4student ${SOURCES})
target_link_libraries (changeColor4student
PRIVATE ${OpenCV_LIBS}
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/fruit_image.jpg
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
