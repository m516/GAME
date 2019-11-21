# CMakeList.txt : CMake project for console_test, include source and define
# project specific logic here.

# Please note that this is a terrible example of how to properly create and store
# CMake files and that it's only specific to this test setup

cmake_minimum_required (VERSION 3.6)




project(Console_Test)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        console_test.cpp
		console_test.h
		)


#Add files
get_filename_component(TEST_ROOT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(SRC_MAIN_DIR ${TEST_ROOT_DIR} DIRECTORY)
set(SRC_GAME_DIR "${SRC_MAIN_DIR}/src")
include_directories(${SRC_GAME_DIR})




#SFML
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network)
#Websocketpp
find_package(websocketpp REQUIRED)

#This is kind of sketchy and shouldn't be used for anything outside of this class
#(It works because CI installs and rebuilds on every commit)
#See http://stackoverflow.com/questions/32411963/ddg#32412044
#See https://cmake.org/cmake/help/v3.14/command/file.html?highlight=file#filesystem
file(GLOB_RECURSE GAME_SOURCE_FILES
    "${SRC_GAME_DIR}/*.h"
    "${SRC_GAME_DIR}/*.cpp"
)


add_executable(Console_Test ${SOURCE_FILES} ${GAME_SOURCE_FILES})


# TODO: Add tests and install targets if needed.
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Console_Test ${SFML_LIBRARIES})
endif()

#Websocketpp
# Link include directories, libraries, defines etc.
target_link_libraries(Console_Test PUBLIC websocketpp::websocketpp)