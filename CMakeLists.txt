cmake_minimum_required(VERSION 3.0)
project (learnCV)
find_package(OpenCV REQUIRED)
add_executable(learnCV learnCV)
include_directories(${OPENCV_INCLUDES})
target_link_libraries(learnCV ${OpenCV_LIBS})