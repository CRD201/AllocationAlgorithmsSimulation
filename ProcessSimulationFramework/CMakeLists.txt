link_directories(${CMAKE_SOURCE_DIR}/MemoryManagemantLib)

add_library(psf INTERFACE)
target_link_libraries(psf INTERFACE mmf)

# add_subdirectory(measurement)
# add_subdirectory(memory)
# add_subdirectory(process)
add_subdirectory(simulation)
