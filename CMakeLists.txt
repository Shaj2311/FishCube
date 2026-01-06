cmake_minimum_required(VERSION 3.16)
project(FishCube LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/Users/Haider Ali/source/SFML-3.0.2/lib/cmake/SFML")

find_package(SFML 3.0.2 REQUIRED COMPONENTS Graphics Window System)

add_executable(FishCube 
	src/main.cpp
	src/Game.cpp
	src/Side.cpp
)

target_include_directories(FishCube PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(FishCube PRIVATE
	SFML::Graphics
	SFML::Window
	SFML::System
)
