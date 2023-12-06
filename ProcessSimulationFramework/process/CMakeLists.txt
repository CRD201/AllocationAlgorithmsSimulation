set(PROCESS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROCESS_SRC 
    ${PROCESS_DIR}/ProcessStorage.cpp
    ${PROCESS_DIR}/ProcessFactory.cpp)

target_sources(psf PUBLIC ${PROCESS_SRC})
