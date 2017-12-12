cmake_minimum_required(VERSION 3.8)
project(blib)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)

set(SOURCE_FILES example/example.cpp)

add_executable(blib ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})
