#pragma once

#include "utils/Concepts.hpp"

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
        MainComponent() : mmStructure{}, algorithm{mmStructure}
        {
        }

        void run()
        {
        }

    private:
        Algorithm algorithm;
        MMStructure mmStructure;
    };
}
