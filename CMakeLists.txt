cmake_minimum_required(VERSION 3.8)
project(blib)

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

set(TYPES_FILES ${EXAMPLES}/example_easylambda.cpp)
add_executable(lambda ${TYPES_FILES})
target_include_directories(lambda PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/easyLambda/include
    ${Boost_INCLUDE_DIRS}
)
target_link_libraries(lambda ${Boost_LIBRARIES})
