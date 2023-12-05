#pragma once

#include <iostream>
#include "utils/Concepts.hpp"
#include "ProcessSimulationFramework/process/ProcessManager.hpp"

using PSF::simulation::utils::AllocationAlgotithm;
using PSF::simulation::utils::MemoryManagemantStructure;

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
              processManager{MEMORY_SIZE, algorithm, mmStructure}
        {
        }

        void run()
        {
            for (unsigned i{0}; i < NUMBER_OF_ITERATION; ++i)
            {
                std::cout << "[PSF-INF] MainComponent: iteration: " << i << std::endl;
                processManager.handleProcesses();
            }
        }

    private:
        Algorithm algorithm;
        MMStructure mmStructure;
        process::ProcessManager processManager;
    };
}
