# CMakeList.txt : CMake project for console_test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.2)

project(Console_Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        console_test.cpp
		console_test.h
		)

add_executable(Console_Test ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network)

# TODO: Add tests and install targets if needed.
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Console_Test ${SFML_LIBRARIES})
endif()
