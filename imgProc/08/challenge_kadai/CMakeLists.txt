cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 11)
project(08_02_challenge_k23023)
find_package(OpenCV 4.4.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
file(GLOB SOURCES *.cpp)
add_executable (08_02_challenge_k23023 ${SOURCES})
target_link_libraries (08_02_challenge_k23023
PRIVATE ${OpenCV_LIBS}
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/three_objects.jpg
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})