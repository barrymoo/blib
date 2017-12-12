cmake_minimum_required(VERSION 3.8)
project(blib)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)

set(EXAMPLES ${CMAKE_CURRENT_SOURCE_DIR}/examples)

set(DOCOPT_FILES ${EXAMPLES}/example_docopt.cpp)
add_executable(docopt ${DOCOPT_FILES})
target_include_directories(docopt PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(docopt PRIVATE DOCOPT_HEADER_ONLY=1)

set(ESTD_FILES ${EXAMPLES}/example_estd.cpp)
add_executable(estd ${ESTD_FILES})
target_include_directories(estd PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(FILES_FILES ${EXAMPLES}/example_files.cpp)
add_executable(files ${FILES_FILES})
target_include_directories(files PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(TYPES_FILES ${EXAMPLES}/example_types.cpp)
add_executable(types ${TYPES_FILES})
target_include_directories(types PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
)
