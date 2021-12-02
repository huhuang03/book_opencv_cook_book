cmake_minimum_required(VERSION 3.12)


if (NOT DEFINED ENV{VCPKG_ROOT})
    message(Please set the vcpkg_root env)
else()
    if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    endif()
endif()

project(opencv_cook_book)

set(OpenCV_DIR "D:\\Program Files\\opencv\\build")
find_package( OpenCV REQUIRED )

# any better idea that import an lib?
set(OpenCV_ex_DIR "D:\\Program Files (x86)\\opencv_ex")
find_package( OpenCV_ex REQUIRED )


function(SINGLE_EXE PROC_NAME)
    add_executable(${PROC_NAME} "${PROC_NAME}.cc")
    target_link_libraries(${PROC_NAME} ${OpenCV_LIBS})
endfunction()

include_directories(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_ex_INCLUDE_DIRS})
include_directories(${OpenCV_ex_INCLUDE_DIRS})

set(IMAGE_DIR ${CMAKE_SOURCE_DIR}/src/images)

add_subdirectory(src/ch01)
add_subdirectory(src/ch02)
add_subdirectory(src/ch03)
add_subdirectory(src/ch04)