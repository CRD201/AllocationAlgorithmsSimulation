#pragma once

#include "ProcessSimulationFramework/process/ProcessManager.hpp"
#include "ProcessSimulationFramework/measurement/MeasurementHandler.hpp"
#include "ProcessSimulationFramework/memory/Memory.hpp"

#include "Concepts.hpp"

namespace PSF::simulation
{
    template <
        AllocationAlgotithm Algorithm,
        MemoryManagemantStructure MMStructure,
        unsigned MEMORY_SIZE,
        unsigned NUMBER_OF_ITERATION>
    class MainComponent
    {
    public:
        MainComponent()
            : mmStructure{},
              algorithm{mmStructure},
              processManager{algorithm, mmStructure, measurementHandler, memory}
        {
        }

        void run()
        {
            for (unsigned i{0}; i < NUMBER_OF_ITERATION; ++i)
            {
                std::cout << "[PSF-INF] MainComponent: iteration: " << i << std::endl;
                processManager.handleProcesses();
                measurementHandler.saveData();
            }
        }

    private:
        Algorithm algorithm;
        MMStructure mmStructure{};
        PSF::measurement::MeasurementHandler measurementHandler{};
        memory::Memory<MEMORY_SIZE> memory{};
        process::ProcessManager<MEMORY_SIZE> processManager;
    };
}
