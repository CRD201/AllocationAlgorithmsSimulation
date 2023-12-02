cmake_minimum_required(VERSION 3.16)
project(alocation_algos VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(alocation_algos main.cpp)

add_subdirectory(MemoryManagemantLib)
add_subdirectory(ProcessSimulationFramework)

target_link_libraries(alocation_algos PUBLIC mml)
target_link_libraries(alocation_algos PUBLIC psf)