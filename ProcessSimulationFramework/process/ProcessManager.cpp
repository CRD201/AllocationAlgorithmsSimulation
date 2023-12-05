#include "ProcessManager.hpp"

namespace PSF::process
{
    ProcessManager::ProcessManager(
        const unsigned memorySize,
        MML::algorithms::AllocationAlgotithmI &algorithm,
        MML::structures::MemoryManagemantStructureI &mmStructure)
        : processFactory{memorySize},
          algorithm{algorithm},
          mmStructure{mmStructure}
    {
    }

    void ProcessManager::handleProcesses()
    {
        handleNewProcess();
        if (!processStorage.isProcessQueueEmpty())
        {
            handleQueuedProcesses();
        }
        handleFinishedPrecesses();
    }

    void ProcessManager::handleNewProcess()
    {
        Process process{processFactory.spawnProcess()};
        const auto &adress{algorithm.findSpace(process.getSize())};

        if (adress.has_value())
        {
            processStorage.storeProcess(process, adress.value());
        }
        else
        {
            processStorage.addProcessToQueue(process);
        }
    }

    void ProcessManager::handleQueuedProcesses()
    {
        const auto &queuedProcesses{processStorage.getQueue()};
        for (auto process : queuedProcesses)
        {
            const auto &adress{algorithm.findSpace(process.getSize())};
            if (adress.has_value())
            {
                processStorage.storeProcess(process, adress.value());
            }
        }
    }

    void ProcessManager::handleFinishedPrecesses()
    {
        const auto &finishedProcesses{processStorage.getFinishedProcesses()};
        for (auto [adress, process] : finishedProcesses)
        {
            mmStructure.freeSpace(adress, process.getSize());
        }
    }
}