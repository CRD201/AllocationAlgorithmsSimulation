#pragma once

#include <iostream>
#include "ProcessSimulationFramework/process/ProcessManager.hpp"
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
              processManager{algorithm, mmStructure, memory}
        {
        }

        void run()
        {
            for (unsigned i{0}; i < NUMBER_OF_ITERATION; ++i)
            {
                std::cout << "[PSF-INF] MainComponent: iteration: " << i << std::endl;
                processManager.handleProcesses();
                std::cout << "[PSF-INF] MainComponent: fragmentation: " << memory.getFragmentedMemorySize() << std::endl;
            }
        }

    private:
        Algorithm algorithm;
        MMStructure mmStructure{};
        memory::Memory<MEMORY_SIZE> memory{};
        process::ProcessManager<MEMORY_SIZE> processManager;
    };
}
