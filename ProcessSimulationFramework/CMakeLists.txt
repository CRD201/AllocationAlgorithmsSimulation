add_library(psf STATIC)
target_link_libraries(psf PUBLIC mmf)

add_subdirectory(measurement)
add_subdirectory(memory)
add_subdirectory(process)
add_subdirectory(simulation)
