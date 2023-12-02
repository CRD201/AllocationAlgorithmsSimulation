set(ALGORITHMS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(ALGORITHMS_SRC 
    ${ALGORITHMS_DIR}/BestFit.cpp
    ${ALGORITHMS_DIR}/FirstFit.cpp
    ${ALGORITHMS_DIR}/NextFit.cpp
    ${ALGORITHMS_DIR}/WorstFit.cpp)

target_sources(mml PUBLIC ${ALGORITHMS_SRC})
