#pragma once

#include <array>
#include "ProcessSimulationFramework/process/Process.hpp"

namespace PSF::memory
{
    template <unsigned SIZE>
    class Memory
    {
    public:
        void fillMemory(unsigned adress, process::Process process)
        {
            for (int i{0}; i < process.getSize(); ++i)
            {
                memory[adress + i] = process.getId();
            }
        }

        void freeMemory(unsigned adress, process::Process process)
        {
            for (int i{0}; i < process.getSize(); ++i)
            {
                memory[adress + i] = emptySpace;
            }
        }

        unsigned getFragmentedMemorySize()
        {
            unsigned fragmentedMemorySize{0};
            for (const auto &space : memory)
            {
                if (space == emptySpace)
                {
                    fragmentedMemorySize += 1;
                }
            }
            return fragmentedMemorySize;
        }

    private:
        const unsigned emptySpace{0};
        std::array<unsigned, SIZE> memory{};
    };
}