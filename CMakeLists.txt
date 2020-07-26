cmake_minimum_required(VERSION 3.12)

project(opencv_cook_book)

set(OpenCV_DIR "D:\\Program Files\\opencv\\build")
find_package( OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})

set(IMAGE_DIR ${CMAKE_SOURCE_DIR}/src/images)

add_subdirectory(src/ch01)

add_executable(hello src/hello_world.cc)