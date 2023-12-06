link_directories(${CMAKE_SOURCE_DIR}/MemoryManagemantLib)

add_library(psf STATIC)
target_link_libraries(psf PUBLIC mml)

add_subdirectory(measurement)
add_subdirectory(process)
