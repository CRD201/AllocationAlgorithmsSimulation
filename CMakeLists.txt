cmake_minimum_required(VERSION 3.16)
project(aas VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})
link_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(MemoryManagemantLib)
add_subdirectory(ProcessSimulationFramework)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC mml)
target_link_libraries(${PROJECT_NAME} PUBLIC psf)