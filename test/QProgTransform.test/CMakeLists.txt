cmake_minimum_required(VERSION 3.1)
project(QProgTransform.test)
file(GLOB_RECURSE QProgTransformSrc ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(${PROJECT_NAME} ${QProgTransformSrc})
target_link_libraries(${PROJECT_NAME} ${LIB_QPANDA} ${LIB_GTEST})
