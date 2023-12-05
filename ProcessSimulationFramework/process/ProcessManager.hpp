#pragma once

#include "MemoryManagemantLib/algorithms/AllocationAlgotithmI.hpp"
#include "MemoryManagemantLib/structures/MemoryManagemantStructureI.hpp"

#include "ProcessFactory.hpp"
#include "ProcessStorage.hpp"

namespace PSF::process
{
    class ProcessManager
    {
    public:
        ProcessManager(
            const unsigned memorySize,
            MML::algorithms::AllocationAlgotithmI &algorithm,
            MML::structures::MemoryManagemantStructureI &mmStructure);

        void handleProcesses();

    private:
        void handleNewProcess();
        void handleQueuedProcesses();
        void handleFinishedPrecesses();

        MML::algorithms::AllocationAlgotithmI &algorithm;
        MML::structures::MemoryManagemantStructureI &mmStructure;
        ProcessFactory processFactory;
        ProcessStorage processStorage{};
    };
}