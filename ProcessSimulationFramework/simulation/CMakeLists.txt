set(SIMULATION_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SIMULATION_SRC 
    ${SIMULATION_DIR}/MainComponent.cpp)

target_sources(psf PUBLIC ${SIMULATION_SRC})

# add_subdirectory(utils)
