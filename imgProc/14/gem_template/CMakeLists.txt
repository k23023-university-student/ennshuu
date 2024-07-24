cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 11)
project(gem_template)
find_package(OpenCV 4.4.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
file(GLOB SOURCES *.cpp)
add_executable (gem_template ${SOURCES})
target_link_libraries (gem_template
PRIVATE ${OpenCV_LIBS}
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/gem1.jpg
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/gem-green.jpg
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})