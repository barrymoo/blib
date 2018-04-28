cmake_minimum_required(VERSION 3.8)
project(blib CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(MPI REQUIRED)
find_package(Boost COMPONENTS mpi serialization REQUIRED)

set(EXAMPLES ${CMAKE_CURRENT_SOURCE_DIR}/examples)

set(DOCOPT_FILES ${EXAMPLES}/example_docopt.cpp)
add_executable(docopt ${DOCOPT_FILES})
target_include_directories(docopt PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(docopt PRIVATE DOCOPT_HEADER_ONLY=1)

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
target_link_libraries(types ${Boost_LIBRARIES})

set(RANGES_FILE ${EXAMPLES}/example_ranges.cpp)
add_executable(ranges ${RANGES_FILE})
target_include_directories(ranges PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/range-v3/include
)

set(STRING_FUNCS_FILES ${EXAMPLES}/example_strings.cpp)
add_executable(strings ${STRING_FUNCS_FILES})
target_include_directories(strings PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
