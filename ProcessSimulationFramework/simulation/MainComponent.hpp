#pragma once

#include <iostream>
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
            for (int i{0}; i < NUMBER_OF_ITERATION; ++i)
            {
                const auto adress{algorithm.findSpace(i)};
                if (adress.has_value())
                {
                    std::cout << "[PSF-INF] adress allocated to: " << adress.value() << std::endl;
                }
                else
                {
                    std::cout << "[PSF-ERR] adress not found" << std::endl;
                }
            }
        }

    private:
        Algorithm algorithm;
        MMStructure mmStructure;
    };
}
