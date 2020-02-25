cmake_minimum_required(VERSION 3.13.4)

project(pong)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/sdl2-cmake-modules")
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES 
		src/*.cpp 
	)

message("${SOURCES}")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

include_directories(
    ${SDL2_INCLUDE_DIRS} 
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIR}
    ${SDL2_MIXER_INCLUDE_DIR}
    )

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    ${SDL2_LIBRARIES} 
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARY}
    ${SDL2_MIXER_LIBRARY}
    )
