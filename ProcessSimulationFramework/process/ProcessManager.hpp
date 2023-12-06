#pragma once

#include "MemoryManagemantLib/algorithms/AllocationAlgotithmI.hpp"
#include "MemoryManagemantLib/structures/MemoryManagemantStructureI.hpp"
#include "ProcessSimulationFramework/measurement/MeasurementHandler.hpp"
#include "ProcessSimulationFramework/memory/Memory.hpp"

#include "ProcessFactory.hpp"
#include "ProcessStorage.hpp"

namespace PSF::process
{
    template <unsigned SIZE>
    class ProcessManager
    {
    public:
        ProcessManager(
            MML::algorithms::AllocationAlgotithmI &algorithm,
            MML::structures::MemoryManagemantStructureI &mmStructure,
            PSF::measurement::MeasurementHandler &measurementHandler,
            PSF::memory::Memory<SIZE> &memory)
            : algorithm{algorithm},
              mmStructure{mmStructure},
              measurementHandler{measurementHandler},
              memory{memory}
        {
        }

        void handleProcesses()
        {
            handleFinishedPrecesses();
            if (!processStorage.isProcessQueueEmpty())
            {
                handleQueuedProcesses();
            }
            handleNewProcess();
            measurementHandler.setFragmentationSize(memory.getFragmentedMemorySize());
        }

    private:
        std::optional<unsigned> getMemoryAdress(const unsigned size)
        {
            measurementHandler.startAlgorithmTimeMeasurement();
            measurementHandler.startMMStructureAllocationTimeMeasurement();

            const auto &adress{algorithm.findSpace(size)};

            measurementHandler.endAlgorithmTimeMeasurement();
            measurementHandler.endMMStructureAllocationTimeMeasurement();

            return adress;
        }

        void handleNewProcess()
        {
            Process process{processFactory.spawnProcess()};
            const auto &adress{getMemoryAdress(process.getSize())};

            if (adress.has_value())
            {
                memory.fillMemory(adress.value(), process);
                processStorage.storeProcess(process, adress.value());
            }
            else
            {
                processStorage.addProcessToQueue(process);
            }
        }

        void handleQueuedProcesses()
        {
            const auto &queuedProcesses{processStorage.getQueue()};
            for (auto process : queuedProcesses)
            {
                const auto &adress{getMemoryAdress(process.getSize())};
                if (adress.has_value())
                {
                    processStorage.storeProcess(process, adress.value());
                }
            }
        }

        void handleFinishedPrecesses()
        {
            const auto &finishedProcesses{processStorage.getFinishedProcesses()};
            for (auto [adress, process] : finishedProcesses)
            {
                memory.freeMemory(adress, process);
                measurementHandler.startMMStructureMemoryFreeingTimeMeasurement();
                mmStructure.freeSpace(adress, process.getSize());
                measurementHandler.endMMStructureMemoryFreeingTimeMeasurement();
            }
        }

        MML::algorithms::AllocationAlgotithmI &algorithm;
        MML::structures::MemoryManagemantStructureI &mmStructure;
        PSF::measurement::MeasurementHandler &measurementHandler;
        PSF::memory::Memory<SIZE> &memory;
        ProcessFactory processFactory{SIZE};
        ProcessStorage processStorage{};
    };
}